// Created by Yael Goldin

#include <unordered_map>
#include <string>
#include "../include/BalanceTable.h"

BalanceTable::BalanceTable() {
  balances_ = new unordered_map<string, double>();
}

BalanceTable::~BalanceTable() {
  delete balances_;
}

void BalanceTable::UpdateBalance(string person, double amount) {
  if (!balances_->count(person)) {
    balances_->insert({person, amount});
  } else {
    double total = balances_->at(person) + amount;
    balances_->insert({person, total});
  }
}