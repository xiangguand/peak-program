/**
 * \file main.cpp
 * VICI Holding Interview question.
 *
 * \author Xiang-Guan Deng (Danny Deng)
 * xiangguand@gmail.com
 **/

#include <chrono>
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "peak.h"

int main(int argc, char *argv[]) {
  if (3 != argc) {
    cout << "Invalid command, example: peak 80 test.txt" << endl;
    return -1;
  }

  int k = atoi(argv[1]);
  string inputFile = argv[2];

  ifstream file(inputFile);
  vector<int> nums;
  if (file) {
    string line;
    while (getline(file, line)) {
      nums.push_back(stoi(line));
      // cout << nums.back() << endl;
    }
  } else {
    cerr << "Fail to read the " << inputFile << endl;
    return -1;
  }

  if (0 == nums.size()) {
    cout << "Peak can not parse any numbers" << endl;
  }

  auto start = chrono::high_resolution_clock::now();
  vector<vector<int>> result = peak(nums, k);
  auto end = chrono::high_resolution_clock::now();
  for (auto &v : result) {
    for (auto &i : v) {
      cout << i << " ";
    }
    cout << endl;
  }

  auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
  cout << "duration: " << duration.count() << " ns" << endl;
}
