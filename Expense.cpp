// Created by Yael Goldin

#include <string>
#include "Expense.h"

using namespace std;

Expense::Expense(double cost, string payer, unordered_set<string> &participants)
    : Expense(cost, payer, participants, true) { }

Expense::Expense(double cost, string payer, unordered_set<string> &participants,
                 bool payerInvolved) {
  cost_ = cost;
  payer_ = payer;
  payer_involved_ = payerInvolved;
  participants_ = new unordered_set<string>();
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
