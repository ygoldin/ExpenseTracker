# Created by Yael Goldin

add_executable(ExpenseTrackerMain
    main.cpp)

target_link_libraries(ExpenseTrackerMain
    PRIVATE
        ExpenseTracker)
