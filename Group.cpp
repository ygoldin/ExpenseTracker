// Created by Yael Goldin

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>
#include "BalanceTable.h"
#include "Expense.h"
#include "Group.h"

using namespace std;

Group::Group() {
  Setup();
}

Group::Group(unordered_set<string> &members) {
  Setup();
  for (string m : members) {
    members_->insert(m);
  }
}

Group::~Group() {
  delete members_;
  delete expenses_;
  delete balances_;
}

bool Group::AddMember(string member) {
  if (MemberExists(member)) {
    return false;
  }
  members_->insert(member);
  return true;
}

bool Group::AddExpense(double cost, string payer, set<string> &participants, bool payerInvolved) {
  if (!MemberExists(payer) || participants.size() == 0) {
    return false;
  }
  for (string p : participants) {
    if (!MemberExists(p)) {
      return false;
    }
  }

  Expense exp(cost, payer, participants, payerInvolved);
  expenses_->push_back(exp);

  double individualCost = exp.IndividualCost();
  InitializeBalanceIfNeeded(payer);
  for (string s : participants) {
    InitializeBalanceIfNeeded(s);
    UpdateBalance(payer, s, individualCost);
  }
  return true;
}

bool Group::RemoveExpense(int id) {
  if (id <= 0 || id >= expenses_->size()) {
    return false;
  }
  Expense exp = expenses_->at(id - 1);
  expenses_->erase(expenses_->begin() + id - 1);
  double individualCost = exp.IndividualCost();
  set<string> participants = exp.Participants();
  string payer = exp.Payer();
  for (string s : participants) {
    UpdateBalance(s, payer, individualCost);
  }
  return true;
}

void Group::Expenses(ostream &out) {
  if (expenses_->size() == 0) {
    out << "No expenses";
  } else {
    for (int i = 0; i < expenses_->size(); i++) {
      out << i + 1 << ": " << expenses_->at(i) << endl;
    }
  }
}

/* helpers */

void Group::Setup() {
  members_ = new unordered_set<string>();
  expenses_ = new vector<Expense>();
  balances_ = new unordered_map<string, BalanceTable>();
}

bool Group::MemberExists(string member) {
  return members_->count(member);
}

void Group::InitializeBalanceIfNeeded(string member) {
  if (balances_->count(member)) {
    BalanceTable tbl;
    balances_->insert({member, tbl});
  }
}

void Group::UpdateBalance(string s1, string s2, double val) {
  balances_->at(s1).UpdateBalance(s2, val);
  balances_->at(s2).UpdateBalance(s1, -val);
}
