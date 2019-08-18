// Created by Yael Goldin

#include "Group.h"

namespace ExpenseTracker
{
    Group::Group(std::unordered_set<std::string>& members) {
        m_members = std::make_shared<std::unordered_set<std::string>>();
        m_expenses = std::make_shared<std::vector<Expense>>();
        m_balances =
            std::make_shared<std::unordered_map<std::string, std::unique_ptr<BalanceTable>>>();
        for (std::string m : members) {
            m_members->insert(m);
        }
    }

    bool Group::AddMember(std::string member) {
        if (MemberExists(member)) {
            return false;
        }
        m_members->insert(member);
        return true;
    }

    bool Group::AddExpense(double cost, std::string payer, std::unordered_set<std::string>& participants,
                           bool payerInvolved) {
        if (!MemberExists(payer) || participants.empty() || cost <= 0) {
            return false;
        }
        for (std::string p : participants) {
            if (!MemberExists(p)) {
                return false;
            }
        }

        Expense exp(cost, payer, participants, payerInvolved);
        m_expenses->push_back(exp);

        double individualCost = exp.IndividualCost();
        InitializeBalanceIfNeeded(payer);
        for (std::string s : participants) {
            InitializeBalanceIfNeeded(s);
            UpdateBalance(payer, s, individualCost);
        }
        return true;
    }

    bool Group::RemoveExpense(int id) {
        if (id <= 0 || id >= m_expenses->size()) {
            return false;
        }
        Expense exp = m_expenses->at(id - 1);
        m_expenses->erase(m_expenses->begin() + id - 1);
        double individualCost = exp.IndividualCost();
        auto participants = exp.Participants();
        std::string payer = exp.Payer();
        for (std::string s : participants) {
            UpdateBalance(s, payer, individualCost);
        }
        return true;
    }

    std::map<uint32_t, Expense> Group::Expenses() const {
        std::map<uint32_t, Expense> expenses;
        uint32_t id = 1;
        for (Expense e : *m_expenses) {
            expenses.insert({id, e});
            id++;
        }
        return expenses;
    }

    std::optional<std::unordered_map<std::string, double>>
        Group::Balances(std::string member) const {
        if (!MemberExists(member)) {
            return std::nullopt;
        } else if (m_balances->empty() || !m_balances->count(member)) {
            return std::unordered_map<std::string, double>();
        } else {
            return m_balances->at(member)->GetAllBalances();
        }
    }

    /* helpers */

    bool Group::MemberExists(std::string member) const { return m_members->count(member); }

    void Group::InitializeBalanceIfNeeded(std::string member) {
        if (!m_balances->count(member)) {
            m_balances->insert({member, std::make_unique<BalanceTable>()});
        }
    }

    void Group::UpdateBalance(std::string receiver, std::string debtor, double val) {
        m_balances->at(receiver)->UpdateBalance(debtor, val);
        m_balances->at(debtor)->UpdateBalance(receiver, -val);
    }

} // namespace ExpenseTracker