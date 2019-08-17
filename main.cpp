// Created by Yael Goldin

#include <assert.h>
#include "Group.h"

using namespace ExpenseTracker;

int main() {
    std::unordered_set<std::string> people = {"A", "B", "C", "D"};
    Group g(people);

    std::set<std::string> participants = {"A", "B", "C"};
    bool expenseAdded = g.AddExpense(4, "D", participants, true);
    assert(expenseAdded);

    g.Expenses(std::cout);
    return 0;
}
