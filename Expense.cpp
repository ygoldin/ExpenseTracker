// Created by Yael Goldin

#include <string>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include "Expense.h"
#include "Utils.h"

using namespace std;

Expense::Expense(double cost, string payer, set<string> &participants)
    : Expense(cost, payer, participants, true) { }

Expense::Expense(double cost, string payer, set<string> &participants,
                 bool payerInvolved) {
  cost_ = cost;
  payer_ = payer;
  payer_involved_ = payerInvolved;
  participants_ = new set<string>();
  for (string p : participants) {
    participants_->insert(p);
  }
}

Expense::~Expense() {
  delete participants_;
}

double Expense::IndividualCost() const {
  int size = participants_->size();
  if (payer_involved_) {
    size++;
  }
  return cost_ / size;
}

ostream &operator<<(ostream &out, const Expense &a) {
  out << a.Payer() << " paid " << a.Cost() << ". ";
  print(out, a.Participants());
  out << " owe " << a.IndividualCost();
  return out;
}
