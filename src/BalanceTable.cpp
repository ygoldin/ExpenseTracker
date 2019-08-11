// Created by Yael Goldin

#include "BalanceTable.h"

namespace ExpenseTracker {

    BalanceTable::BalanceTable() {
      balances_ = std::make_shared<std::unordered_map<std::string, double>>();
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
