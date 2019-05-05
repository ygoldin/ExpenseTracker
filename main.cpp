#include <assert.h>
#include <iostream>
#include <unordered_set>
#include <set>
#include "Group.h"

using namespace std;

int main() {
  unordered_set<string> people = {"A", "B", "C", "D"};
  Group g(people);

  set<string> participants = {"A", "B", "C"};
  bool expenseAdded = g.AddExpense(4, "D", participants, true);
  assert(expenseAdded);

  g.Expenses(cout);
  return 0;
}
