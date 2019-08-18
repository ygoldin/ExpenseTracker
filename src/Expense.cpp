// Created by Yael Goldin

#include "Expense.h"

#include "Utils.h"

#include <unordered_set>

namespace ExpenseTracker
{
    Expense::Expense(double cost, std::string payer, std::set<std::string>& participants,
                     bool payerInvolved)
        : m_cost(cost), m_payer(payer), m_payerInvolved(payerInvolved) {
        m_participants =
            std::make_shared<std::set<std::string>>(participants); // fffffffffffffffffffffff
    }

    double Expense::IndividualCost() const {
        int size = m_participants->size();
        if (m_payerInvolved) {
            size++;
        }
        return m_cost / size;
    }

    std::set<std::string> Expense::Participants() const {
        return std::set<std::string>(*m_participants);
    }

    std::ostream& operator<<(std::ostream& out, const Expense& a) {
        out << a.Payer() << " paid " << a.Cost() << ". ";
        auto participants = a.Participants();
        print(out, participants);
        out << " owe " << a.IndividualCost() << " each";
        return out;
    }

} // namespace ExpenseTracker