// Created by Yael Goldin

#include <unordered_map>
#include <string>
#include "BalanceTable.h"

namespace ExpenseTracker {

    BalanceTable::BalanceTable() {
      balances_ = new std::unordered_map<std::string, double>();
    }

    BalanceTable::~BalanceTable() {
      delete balances_;
    }

    void BalanceTable::UpdateBalance(std::string person, double amount) {
      if (!balances_->count(person)) {
        balances_->insert({person, amount});
      } else {
        double total = balances_->at(person) + amount;
        balances_->insert({person, total});
      }
    }
} // namespace ExpenseTracker
