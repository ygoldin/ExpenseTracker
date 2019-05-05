// Created by Yael Goldin

#ifndef EXPENSETRACKER_GROUP_H
#define EXPENSETRACKER_GROUP_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "BalanceTable.h"
#include "Expense.h"

using namespace std;

class Group {
  public:
    Group();
    Group(unordered_set<string> &members);
    ~Group();

    bool AddMember(string member);

    bool AddExpense(double cost, string payer, unordered_set<string> &participants,
        bool payerInvolved);

  private:
    unordered_set<string>* members_;
    vector<Expense>* expenses_;
    unordered_map<string, BalanceTable>* balances_;

    void Setup();
    bool MemberExists(string member);
    void InitializeBalanceIfNeeded(string member);
};


#endif //EXPENSETRACKER_GROUP_H
