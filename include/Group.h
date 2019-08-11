// Created by Yael Goldin

#ifndef EXPENSETRACKER_GROUP_H
#define EXPENSETRACKER_GROUP_H

#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>
#include "BalanceTable.h"
#include "Expense.h"

class Group {
  public:
    Group();
    Group(std::unordered_set<std::string> &members);
    ~Group();

    // adds member to group, returns true if new member
    bool AddMember(std::string member);

    // adds a new expense to the group
    // returns true if payer and participants exist in the group, and there is at least
    // one participant
    bool AddExpense(double cost, std::string payer, std::set<std::string> &participants, bool payerInvolved);

    // removes the expense from the group
    // returns true if expense existed
    bool RemoveExpense(int id);

    // prints all expenses to the given stream
    void Expenses(std::ostream &out);

  private:
    std::unordered_set<std::string>* members_;
    std::vector<Expense>* expenses_;
    std::unordered_map<std::string, BalanceTable*>* balances_;

    void Setup();
    bool MemberExists(std::string member);
    void InitializeBalanceIfNeeded(std::string member);  // creates balance tables if needed
    void UpdateBalance(std::string receiver, std::string debtor, double val);
};


#endif //EXPENSETRACKER_GROUP_H
