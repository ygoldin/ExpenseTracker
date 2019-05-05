#include <iostream>
#include <unordered_set>
#include <set>
#include "Group.h"

using namespace std;

int main() {
  unordered_set<string> people;
  people.insert("A");
  people.insert("B");
  people.insert("C");
  people.insert("D");
  Group g(people);

  set<string> participants;
  participants.insert("A");
  participants.insert("B");
  participants.insert("C");
  g.AddExpense(4, "D", participants, true);

  g.Expenses(cout);
  return 0;
}