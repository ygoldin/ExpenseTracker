// Created by Yael Goldin

#include "Utils.h"

namespace ExpenseTracker {

    void print(std::ostream &out, const std::set<std::string> &s) {
      out << "[";
      if (!s.empty()) {
        auto it = s.begin();
        out << *it;
        it++;
        while (it != s.end()) {
          out << "," << *it;
          it++;
        }
      }
      out << "]";
    }

} // namespace ExpenseTracker