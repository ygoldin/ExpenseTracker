// Created by Yael Goldin

#include "Group.h"

namespace ExpenseTracker
{
    Group::Group(std::unordered_set<std::string>& members) {
        members_ = std::make_shared<std::unordered_set<std::string>>();
        expenses_ = std::make_shared<std::vector<Expense>>();
        m_balances =
            std::make_shared<std::unordered_map<std::string, std::unique_ptr<BalanceTable>>>();
        for (std::string m : members) {
            members_->insert(m);
        }
    }

    bool Group::AddMember(std::string member) {
        if (MemberExists(member)) {
            return false;
        }
        members_->insert(member);
        return true;
    }

    bool Group::AddExpense(double cost, std::string payer, std::set<std::string>& participants,
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
        expenses_->push_back(exp);

        double individualCost = exp.IndividualCost();
        InitializeBalanceIfNeeded(payer);
        for (std::string s : participants) {
            InitializeBalanceIfNeeded(s);
            UpdateBalance(payer, s, individualCost);
        }
        return true;
    }

    bool Group::RemoveExpense(int id) {
        if (id <= 0 || id >= expenses_->size()) {
            return false;
        }
        Expense exp = expenses_->at(id - 1);
        expenses_->erase(expenses_->begin() + id - 1);
        double individualCost = exp.IndividualCost();
        auto participants = exp.Participants();
        std::string payer = exp.Payer();
        for (std::string s : participants) {
            UpdateBalance(s, payer, individualCost);
        }
        return true;
    }

    void Group::Expenses(std::ostream& out) {
        if (expenses_->empty()) {
            out << "No expenses" << std::endl;
        } else {
            for (int i = 0; i < expenses_->size(); i++) {
                out << i + 1 << ": " << expenses_->at(i) << std::endl;
            }
        }
    }

    /* helpers */

    bool Group::MemberExists(std::string member) { return members_->count(member); }

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