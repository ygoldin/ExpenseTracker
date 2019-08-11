// Created by Yael Goldin

#include "BalanceTable.h"

namespace ExpenseTracker {

    BalanceTable::BalanceTable() {
      m_balances = std::make_shared<std::unordered_map<std::string, double>>();
    }

    void BalanceTable::UpdateBalance(std::string person, double amount) {
      if (!m_balances->count(person)) {
        m_balances->insert({person, amount});
      } else {
        double total = m_balances->at(person) + amount;
        m_balances->insert({person, total});
      }
    }
} // namespace ExpenseTracker
