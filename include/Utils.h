// Created by Yael Goldin

#ifndef EXPENSETRACKER_UTILS_H
#define EXPENSETRACKER_UTILS_H

#include <iostream>
#include <set>
#include <sstream>
#include <string>

namespace ExpenseTracker
{
    // prints the unordered set to the given stream
    void print(std::ostream& out, const std::set<std::string>& s);

} // namespace ExpenseTracker

#endif // EXPENSETRACKER_UTILS_H
