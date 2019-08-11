// Created by Yael Goldin

#include <string>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <set>
#include "Expense.h"
#include "Utils.h"

namespace ExpenseTracker {

    Expense::Expense(double cost, std::string payer, std::set<std::string> &participants)
        : Expense(cost, payer, participants, true) {}

    Expense::Expense(double cost, std::string payer, std::set<std::string> &participants,
                     bool payerInvolved) {
      cost_ = cost;
      payer_ = payer;
      payer_involved_ = payerInvolved;
      participants_ = new std::set<std::string>(participants);
    }

    Expense::~Expense() {
      delete participants_;
    }

    void Expense::Participants(std::set<std::string> *p) const {
      for (auto it : *participants_) {
        p->insert(it);
      }
    }

    double Expense::IndividualCost() const {
      int size = participants_->size();
      if (payer_involved_) {
        size++;
      }
      return cost_ / size;
    }

    std::ostream &operator<<(std::ostream &out, const Expense &a) {
      out << a.Payer() << " paid " << a.Cost() << ". ";
      std::set<std::string> participants;
      a.Participants(&participants);
      print(out, participants);
      out << " owe " << a.IndividualCost() << " each";
      return out;
    }

} // namespace ExpenseTracker