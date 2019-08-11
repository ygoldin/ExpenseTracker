// Created by Yael Goldin

#ifndef EXPENSETRACKER_BALANCETABLE_H
#define EXPENSETRACKER_BALANCETABLE_H

#include <memory>
#include <string>
#include <unordered_map>

namespace ExpenseTracker {

    // this class represents one person's current balances
    class BalanceTable {
    public:
        BalanceTable();

        // either creates a new balance with this person, or updates it by adding the given amount
        // positive balance means the given person owes money to the table owner
        void UpdateBalance(std::string person, double amount);

    private:
        std::shared_ptr<std::unordered_map<std::string, double>> m_balances;
    };

} // namespace ExpenseTracker

#endif //EXPENSETRACKER_BALANCETABLE_H
