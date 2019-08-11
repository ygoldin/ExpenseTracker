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

using namespace std;

class Group {
  public:
    Group();
    Group(unordered_set<string> &members);
    ~Group();

    // adds member to group, returns true if new member
    bool AddMember(string member);

    // adds a new expense to the group
    // returns true if payer and participants exist in the group, and there is at least
    // one participant
    bool AddExpense(double cost, string payer, set<string> &participants, bool payerInvolved);

    // removes the expense from the group
    // returns true if expense existed
    bool RemoveExpense(int id);

    // prints all expenses to the given stream
    void Expenses(ostream &out);

  private:
    unordered_set<string>* members_;
    vector<Expense>* expenses_;
    unordered_map<string, BalanceTable*>* balances_;

    void Setup();
    bool MemberExists(string member);
    void InitializeBalanceIfNeeded(string member);  // creates balance tables if needed
    void UpdateBalance(string receiver, string debtor, double val);
};


#endif //EXPENSETRACKER_GROUP_H
