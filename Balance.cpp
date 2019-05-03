// Created by Yael Goldin

#include <string>
#include "Balance.h"

using namespace std;

void Balance::Update(double amount) {
  amount_ += amount;
  if (amount_ < 0) {
    amount_ = -amount_;
    string temp = receiver_;
    receiver_ = debtor_;
    debtor_ = temp;
  }
}