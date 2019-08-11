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
        // creates an expense where the payer is involved (i.e. didn't just pay for someone else)
        Expense(double cost, std::string payer, std::set<std::string> &participants);

        // creates an expense
        Expense(double cost, std::string payer, std::set<std::string> &participants,
                bool payerInvolved);

        double Cost() const { return m_cost; }

        std::string Payer() const { return m_payer; }

        void Participants(std::set<std::string> *p) const;

        // returns how much each person's cost was in the expense
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
