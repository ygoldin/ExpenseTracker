// Created by Yael Goldin

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
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

bool Group::AddExpense(double cost, string payer, unordered_set<string> &participants,
                bool payerInvolved) {
  if (!MemberExists(payer)) {
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
    balances_->at(payer).UpdateBalance(s, individualCost);
    balances_->at(s).UpdateBalance(payer, -individualCost);
  }
  return true;
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