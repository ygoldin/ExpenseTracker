# Created by Yael Goldin

cmake_minimum_required(VERSION 3.14)
project(ExpenseTracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExpenseTracker
    main.cpp
    src/BalanceTable.cpp
    src/Expense.cpp
    src/Group.cpp
    include/BalanceTable.h
    include/Expense.h
    include/Group.h)

include_directories(include)
