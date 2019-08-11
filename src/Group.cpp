// Created by Yael Goldin

#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>
#include "BalanceTable.h"
#include "Expense.h"
#include "Group.h"

Group::Group() {
  Setup();
}

Group::Group(std::unordered_set<std::string> &members) {
  Setup();
  for (std::string m : members) {
    members_->insert(m);
  }
}

Group::~Group() {
  delete members_;
  delete expenses_;
  for (auto it = balances_->begin(); it != balances_->end(); ++it) {
    delete it->second;
  }
  delete balances_;
}

bool Group::AddMember(std::string member) {
  if (MemberExists(member)) {
    return false;
  }
  members_->insert(member);
  return true;
}

bool Group::AddExpense(double cost, std::string payer, std::set<std::string> &participants, bool payerInvolved) {
  if (!MemberExists(payer) || participants.empty() || cost <= 0) {
    return false;
  }
  for (std::string p : participants) {
    if (!MemberExists(p)) {
      return false;
    }
  }

  Expense exp(cost, payer, participants, payerInvolved);
  expenses_->push_back(exp);

  double individualCost = exp.IndividualCost();
  InitializeBalanceIfNeeded(payer);
  for (std::string s : participants) {
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
  std::set<std::string> participants;
  exp.Participants(&participants);
  std::string payer = exp.Payer();
  for (std::string s : participants) {
    UpdateBalance(s, payer, individualCost);
  }
  return true;
}

void Group::Expenses(std::ostream &out) {
  if (expenses_->empty()) {
    out << "No expenses" << std::endl;
  } else {
    for (int i = 0; i < expenses_->size(); i++) {
      out << i + 1 << ": " << expenses_->at(i) << std::endl;
    }
  }
}

/* helpers */

void Group::Setup() {
  members_ = new std::unordered_set<std::string>();
  expenses_ = new std::vector<Expense>();
  balances_ = new std::unordered_map<std::string, BalanceTable*>();
}

bool Group::MemberExists(std::string member) {
  return members_->count(member);
}

void Group::InitializeBalanceIfNeeded(std::string member) {
  if (!balances_->count(member)) {
    BalanceTable *tbl = new BalanceTable();
    balances_->insert({member, tbl});
  }
}

void Group::UpdateBalance(std::string receiver, std::string debtor, double val) {
  balances_->at(receiver)->UpdateBalance(debtor, val);
  balances_->at(debtor)->UpdateBalance(receiver, -val);
}
