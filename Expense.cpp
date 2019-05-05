// Created by Yael Goldin

#include <string>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <set>
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
  participants_ = new set<string>(participants);
}

Expense::~Expense() {
  delete participants_;
}

void Expense::Participants(set<string> *p) const {
  for (auto it = participants_->begin(); it != participants_->end(); ++it) {
    p->insert(*it);
  }
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
  set<string> participants;
  a.Participants(&participants);
  print(out, participants);
  out << " owe " << a.IndividualCost() << " each";
  return out;
}
