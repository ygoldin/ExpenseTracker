// Created by Yael Goldin

#include <string>
#include <unordered_set>
#include <vector>
#include "Balance.h"
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

void Group::Setup() {
  members_ = new unordered_set<string>();
  expenses_ = new vector<Expense>();
  balances_ = new unordered_set<Balance>();
}

Group::~Group() {
  delete members_;
  delete expenses_;
  delete balances_;
}

void Group::AddMember(string member) {
  members_->insert(member);
}