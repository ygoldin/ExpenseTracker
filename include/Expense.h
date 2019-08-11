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

        double Cost() const { return cost_; }

        std::string Payer() const { return payer_; }

        void Participants(std::set<std::string> *p) const;

        // returns how much each person's cost was in the expense
        double IndividualCost() const;

    private:
        double cost_;
        std::string payer_;
        std::shared_ptr<std::set<std::string>> participants_;
        bool payer_involved_;
    };

// override ostream
    std::ostream &operator<<(std::ostream &out, const Expense &a);

} // namespace ExpenseTracker

#endif //EXPENSETRACKER_EXPENSE_H
