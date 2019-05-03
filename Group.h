// Created by Yael Goldin

#ifndef EXPENSETRACKER_GROUP_H
#define EXPENSETRACKER_GROUP_H

#include <string>
#include <unordered_set>
#include <vector>
#include "Balance.h"
#include "Expense.h"

using namespace std;

class Group {
  public:
    Group();
    Group(unordered_set<string> &members);
    ~Group();

    void AddMember(string member);

  private:
    unordered_set<string>* members_;
    vector<Expense>* expenses_;
    unordered_set<Balance>* balances_;

    void Setup();
};


#endif //EXPENSETRACKER_GROUP_H
