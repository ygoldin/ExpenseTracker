// Created by Yael Goldin

#include "Group.h"

#include <assert.h>
#include <iostream>

using namespace ExpenseTracker;

// prints all of the group's info to stdout
static void printGroup(Group& g);
// prints the info of a single expense to stdout
static void printSingleExpense(uint32_t id, const Expense& e);
// returns a string representation of the set
static std::string setString(const std::set<std::string>& set);

int main() {
    std::unordered_set<std::string> people = {"A", "B", "C", "D"};
    Group g(people);

    std::set<std::string> participants = {"A", "B", "C"};
    bool expenseAdded = g.AddExpense(4, "D", participants, true);
    assert(expenseAdded);

    printGroup(g);
    return 0;
}

static void printGroup(Group& g) {
    auto expenses = g.Expenses();
    if (expenses.empty()) {
        std::cout << "No expenses" << std::endl;
    } else {
        for (auto const& pair : expenses) {
            printSingleExpense(pair.first, pair.second);
        }
    }
}

static std::string setString(const std::set<std::string>& set) {
    std::string result("[");
    if (!set.empty()) {
        for (auto const& s : set) {
            result += s + ",";
        }
        result.pop_back();
    }
    result += "]";
    return result;
}

static void printSingleExpense(uint32_t id, const Expense& e) {
    std::cout << id << ": ";
    std::cout << e.Payer() << " paid " << e.Cost() << ". ";
    std::cout << setString(e.Participants()) << " owe " << e.IndividualCost() << " each"
              << std::endl;
}
