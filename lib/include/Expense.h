// Created by Yael Goldin

#ifndef EXPENSETRACKER_EXPENSE_H
#define EXPENSETRACKER_EXPENSE_H

#include <memory>
#include <string>
#include <unordered_set>

namespace ExpenseTracker
{
    class Expense {
      public:
        // Creates an expense
        Expense(double cost, std::string payer, std::unordered_set<std::string>& participants,
                bool payerInvolved = true);

        // Returns how much each person's cost was in the expense
        double IndividualCost() const;

        // Returns the participants
        std::unordered_set<std::string> Participants() const;

        // Returns how much was paid
        double Cost() const { return m_cost; }

        // Returns who paid
        std::string Payer() const { return m_payer; }

      private:
        double m_cost;
        std::string m_payer;
        std::shared_ptr<std::unordered_set<std::string>> m_participants;
        bool m_payerInvolved;
    };

} // namespace ExpenseTracker

#endif // EXPENSETRACKER_EXPENSE_H
