// Created by Yael Goldin

#ifndef EXPENSETRACKER_BALANCETABLE_H
#define EXPENSETRACKER_BALANCETABLE_H

#include <unordered_map>
#include <string>

using namespace std;

// this class represents one person's current balances
class BalanceTable {
  public:
    BalanceTable();
    ~BalanceTable();

    // either creates a new balance with this person, or updates it by adding the given amount
    // positive balance means the given person is owed money
    void UpdateBalance(string person, double amount);

  private:
    unordered_map<string, double>* balances_;
};


#endif //EXPENSETRACKER_BALANCETABLE_H
