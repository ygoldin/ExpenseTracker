// Created by Yael Goldin

#ifndef EXPENSETRACKER_BALANCETABLE_H
#define EXPENSETRACKER_BALANCETABLE_H

#include <unordered_map>
#include <string>

// this class represents one person's current balances
class BalanceTable {
  public:
    BalanceTable();
    ~BalanceTable();

    // either creates a new balance with this person, or updates it by adding the given amount
    // positive balance means the given person owes money to the table owner
    void UpdateBalance(std::string person, double amount);

  private:
    std::unordered_map<std::string, double>* balances_;
};


#endif //EXPENSETRACKER_BALANCETABLE_H
