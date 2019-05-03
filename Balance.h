// Created by Yael Goldin

#ifndef EXPENSETRACKER_BALANCE_H
#define EXPENSETRACKER_BALANCE_H

#include <string>

using namespace std;

class Balance {
  public:
    Balance(double amount, string receiver, string debtor): amount_(amount), receiver_(receiver),
        debtor_(debtor) { }

    double Amount() const { return amount_; }
    string Receiver() const { return receiver_; }
    string Debtor() const { return debtor_; }

    // adds the given amount to the balance
    // if the total amount goes negative, switches the receiver and debtor
    void Update(double amount);

  private:
    double amount_;
    string receiver_;
    string debtor_;
};


#endif //EXPENSETRACKER_BALANCE_H
