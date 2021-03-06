// Created by Yael Goldin

#ifndef EXPENSETRACKER_GROUP_H
#define EXPENSETRACKER_GROUP_H

#include "BalanceTable.h"
#include "Expense.h"

#include <map>
#include <optional>
#include <unordered_set>
#include <vector>

namespace ExpenseTracker
{
    class Group {
      public:
        // Creates a group with the given members
        Group(std::unordered_set<std::string>& members);

        // Adds member to the group, returns true if this member is new
        bool AddMember(std::string member);

        // Returns all the members' names
        std::unordered_set<std::string> Members() const { return *m_members; };

        // Adds a new expense to the group
        // Returns true if the expense was added successfully
        // - there is at least one participant
        // - payer and participants exist in the group
        // - cost is positive
        bool AddExpense(double cost, std::string payer,
                        std::unordered_set<std::string>& participants, bool payerInvolved);

        // Removes the expense from the group if it existed
        // Returns true if it existed
        bool RemoveExpense(int id);

        // Returns all the expenses in order
        std::map<uint32_t, Expense> Expenses() const;

        // Returns all of the balances for this member (or nullopt if they aren't in the group)
        // Positive balances means other members owe money to this one
        std::optional<std::unordered_map<std::string, double>> Balances(std::string member) const;

      private:
        std::shared_ptr<std::unordered_set<std::string>> m_members;
        std::shared_ptr<std::vector<Expense>> m_expenses;
        std::shared_ptr<std::unordered_map<std::string, std::unique_ptr<BalanceTable>>> m_balances;

        // Returns if the member exists in this group
        bool MemberExists(std::string member) const;

        // Creates a balance table for the member if they have never been involved in an expense
        void InitializeBalanceIfNeeded(std::string member);

        // Updates both participants' balances
        void UpdateBalance(std::string receiver, std::string debtor, double val);
    };

} // namespace ExpenseTracker

#endif // EXPENSETRACKER_GROUP_H
