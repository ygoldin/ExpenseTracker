// Created by Yael Goldin

#ifndef EXPENSETRACKER_EXPENSE_H
#define EXPENSETRACKER_EXPENSE_H

#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>

namespace ExpenseTracker {

    class Expense {
    public:
        // Creates an expense
        Expense(double cost, std::string payer, std::set<std::string> &participants,
                bool payerInvolved = true);

        // Returns how much was paid
        double Cost() const { return m_cost; }

        // Returns who paid
        std::string Payer() const { return m_payer; }

        // Returns the participants
        void Participants(std::set<std::string> *p) const;

        // Returns how much each person's cost was in the expense
        double IndividualCost() const;

    private:
        double m_cost;
        std::string m_payer;
        std::shared_ptr<std::set<std::string>> m_participants;
        bool m_payerInvolved;
    };

    // override ostream
    std::ostream &operator<<(std::ostream &out, const Expense &a);

} // namespace ExpenseTracker

#endif //EXPENSETRACKER_EXPENSE_H
