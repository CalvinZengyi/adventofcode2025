#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> splitStringBySpases(const std::string &str) {
  std::vector<int> numList;
  std::stringstream ss(str);
  std::string temp;
  while (ss >> temp) {
    numList.push_back(std::stoi(temp));
  }
  return numList;
}

void printVector(std::vector<int> &row) {
  for (const int i : row) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

bool isSafeIncremental(std::vector<int> &dataList) {
  assert(dataList.size() > 0);
  for (int i = 1; i < dataList.size(); i++) {
    int sub = dataList[i] - dataList[i - 1];
    if (sub < 1 || sub > 3) {
      std::cout << "unsafe line: ";
      printVector(dataList);
      return false;
    }
  }
  std::cout << "safe line: ";
  printVector(dataList);
  return true;
}

bool isSafeDecrease(std::vector<int> &dataList) {
  assert(dataList.size() > 0);

  for (int i = 1; i < dataList.size(); i++) {
    int sub = dataList[i - 1] - dataList[i];
    if (sub < 1 || sub > 3) {
      std::cout << "unsafe line: ";
      printVector(dataList);
      return false;
    }
  }
  std::cout << "safe line: ";
  printVector(dataList);
  return true;
}

bool isSafe(std::vector<int> &dataList) {
  assert(dataList.size() > 0);
  if (dataList[0] < dataList[1]) {
    return isSafeIncremental(dataList);
  } else if (dataList[0] > dataList[1]) {
    return isSafeDecrease(dataList);
  }

  return false;
}

int main() {

  std::ifstream file("input.txt");
  std::string str;
  int res = 0;
  while (std::getline(file, str)) {
    auto numList = splitStringBySpases(str);
    if (isSafe(numList)) {
      res++;
    }
  }
  std::cout << "res is " << res << std::endl;
  return res;
}
