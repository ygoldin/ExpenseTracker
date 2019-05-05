// Created by Yael Goldin

#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include "Utils.h"

using namespace std;

void print(ostream &out, const set<string> &s) {
  out << "[";
  auto it = s.begin();
  out << *it;
  it++;
  while (it != s.end()) {
    out << "," << *it;
    it++;
  }
  out << "]";
}