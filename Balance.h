// Created by Yael Goldin

#ifndef EXPENSETRACKER_BALANCE_H
#define EXPENSETRACKER_BALANCE_H

#include <string>

using namespace std;

class Balance {
  public:
    Balance(double amount, string otherParty): amount_(amount), other_party_(otherParty) { }

    double Amount() const { return amount_; }
    string OtherParty() const { return other_party_; }

    // adds the given amount to the balance
    void Update(double amount);

  private:
    double amount_;
    string other_party_;
};


#endif //EXPENSETRACKER_BALANCE_H
