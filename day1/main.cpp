#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int calculateDistance(std::vector<int> &leftList, std::vector<int> &rightList) {
  std::sort(leftList.begin(), leftList.end());
  std::sort(rightList.begin(), rightList.end());
  auto itL = leftList.begin();
  auto itR = rightList.begin();
  int res = 0;
  for (; itL != leftList.end() && itR != rightList.end(); itL++, itR++) {
    res += abs(*itL - *itR);
  }
  return res;
}

std::vector<int> splitStringBySpases(const std::string &str) {
  std::vector<int> numerList;
  std::stringstream ss(str);
  std::string temp;
  while (ss >> temp) {
    numerList.push_back(std::stoi(temp));
  }
  return numerList;
}

int calculateSimilarityScore(std::vector<int> &leftList,
                             std::vector<int> &rightList) {
  std::map<int, int> rListFreq;
  for (auto rELe : rightList) {
    rListFreq[rELe]++;
  }
  int res = 0;
  for (auto lEle : leftList) {
    res += lEle * rListFreq[lEle];
  }
  return res;
}

int main() {

  std::vector<int> leftList;
  std::vector<int> rightList;
  std::ifstream file("input.txt");
  std::string str;
  while (std::getline(file, str)) {
    auto pairNumber = splitStringBySpases(str);
    leftList.push_back(pairNumber[0]);
    rightList.push_back(pairNumber[1]);
  }
  // Puzzle 1.
  // int res = calculateDistance(leftList, rightList);

  // Puzzle 2
  int res = calculateSimilarityScore(leftList, rightList);
  std::cout << "result is " << res << std::endl;
}
