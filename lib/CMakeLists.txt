# Created by Yael Goldin

add_library(ExpenseTracker STATIC
    src/BalanceTable.cpp
    src/Expense.cpp
    src/Group.cpp
    include/BalanceTable.h
    include/Expense.h
    include/Group.h)

target_include_directories(ExpenseTracker
    PUBLIC
        include)
