// Created by Yael Goldin

#include "Group.h"

#include <assert.h>
#include <iostream>
#include <set>

using namespace ExpenseTracker;

// prints all of the group's info to stdout
static void printGroup(Group& g);
// prints all of the group's members to stdout
static void printMembers(Group& g);
// prints the info of a the group's expenses to stdout
static void printExpenses(Group& g);
// returns a string representation of the set
static std::string setString(const std::unordered_set<std::string>& set);

int main() {
    std::unordered_set<std::string> people = {"A", "B", "C", "D"};
    Group g(people);

    std::unordered_set<std::string> participants = {"A", "B", "C"};
    bool expenseAdded = g.AddExpense(4, "D", participants, true);
    assert(expenseAdded);

    printGroup(g);
    return 0;
}

static void printGroup(Group& g) {
    printMembers(g);
    printExpenses(g);
}

static void printMembers(Group& g) {
    auto members = g.Members();
    if (members.empty()) {
        std::cout << "No members" << std::endl;
    } else {
        std::cout << "Members: " << setString(members) << std::endl;
    }
}

static void printExpenses(Group& g) {
    auto expenses = g.Expenses();
    if (expenses.empty()) {
        std::cout << "No expenses" << std::endl;
    } else {
        std::cout << "Expenses:" << std::endl;
        for (auto const& pair : expenses) {
            const Expense& e = pair.second;
            std::cout << " " << pair.first << ": " << e.Payer() << " paid " << e.Cost() << ". "
                      << setString(e.Participants()) << " owe " << e.IndividualCost() << " each"
                      << std::endl;
        }
    }
}

static std::string setString(const std::unordered_set<std::string>& set) {
    std::string result("[");
    if (!set.empty()) {
        std::set<std::string> ordered;
        for (auto const& s : set) {
            ordered.insert(s);
        }
        for (auto const& s : ordered) {
            result += s + ",";
        }
        result.pop_back();
    }
    result += "]";
    return result;
}
