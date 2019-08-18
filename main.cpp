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
// prints all of the group's balances to stdout
static void printBalances(Group& g);
// returns a string representation of the set
static std::string setString(const std::unordered_set<std::string>& set);

int main() {
    std::unordered_set<std::string> people = {"A", "B", "C", "D"};
    Group g(people);

    std::unordered_set<std::string> participants1 = {"A", "B", "C"};
    bool expenseAdded = g.AddExpense(4, "D", participants1, true);
    assert(expenseAdded);
    printGroup(g);

    std::unordered_set<std::string> participants2 = {"D"};
    expenseAdded = g.AddExpense(2, "A", participants2, true);
    assert(expenseAdded);
    printGroup(g);

    g.RemoveExpense(1);
    printGroup(g);

    return 0;
}

static void printGroup(Group& g) {
    printMembers(g);
    printExpenses(g);
    printBalances(g);
    std::cout << std::endl;
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

static void printBalances(Group& g) {
    std::cout << "Balances: " << std::endl;
    auto members = g.Members();
    for (std::string s : members) {
        std::cout << " " << s << ":";
        auto balancesOpt = g.Balances(s);
        assert(balancesOpt.has_value());
        auto balances = balancesOpt.value();
        if (balances.empty()) {
            std::cout << " none" << std::endl;
        } else {
            std::cout << std::endl;
            for (auto info : balances) {
                if (info.second < 0) {
                    std::cout << "  owes " << -info.second << " to " << info.first << std::endl;
                } else {
                    std::cout << "  is owed " << info.second << " by " << info.first << std::endl;
                }
            }
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
