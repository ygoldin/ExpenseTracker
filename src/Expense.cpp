// Created by Yael Goldin

#include <unordered_set>
#include "Expense.h"
#include "Utils.h"

namespace ExpenseTracker {

    Expense::Expense(double cost, std::string payer, std::set<std::string> &participants)
        : Expense(cost, payer, participants, true) {}

    Expense::Expense(double cost, std::string payer, std::set<std::string> &participants,
                     bool payerInvolved) {
      m_cost = cost;
      m_payer = payer;
      m_payerInvolved = payerInvolved;
      m_participants = std::make_shared<std::set<std::string>>(participants);
    }

    void Expense::Participants(std::set<std::string> *p) const {
      for (auto it : *m_participants) {
        p->insert(it);
      }
    }

    double Expense::IndividualCost() const {
      int size = m_participants->size();
      if (m_payerInvolved) {
        size++;
      }
      return m_cost / size;
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