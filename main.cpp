#include <iostream>
#include <unordered_set>
#include <set>
#include "Group.h"

using namespace std;

int main() {
  unordered_set<string> people = {"A", "B", "C", "D"};
  Group g(people);

  set<string> participants = {"A", "B", "C"};
  bool b = g.AddExpense(4, "D", participants, true);
  cout << b << endl;

  g.Expenses(cout);
  return 0;
}