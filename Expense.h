// Created by Yael Goldin

#ifndef EXPENSETRACKER_EXPENSE_H
#define EXPENSETRACKER_EXPENSE_H


#include <string>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

class Expense {
  public:
    // creates an expense where the payer is involved (i.e. didn't just pay for someone else)
    Expense(double cost, string payer, set<string> &participants);

    // creates an expense
    Expense(double cost, string payer, set<string> &participants, bool payerInvolved);

    // destructs the expense
    ~Expense();

    double Cost() const { return cost_;}
    string Payer() const { return payer_; }
    set<string> Participants() const { return *participants_; }

    // returns how much each person's cost was in the expense
    double IndividualCost() const;

  private:
    double cost_;
    string payer_;
    set<string>* participants_;
    bool payer_involved_;
};

// override ostream
ostream &operator<<(ostream &out, const Expense &a);

#endif //EXPENSETRACKER_EXPENSE_H
