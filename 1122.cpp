#include <iostream>
#include <map>
#include <utility>
#include <vector>

class Solution {  // Jun 11, 2024
public:
  std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::map<int, int> frequencies;
    for(int i : arr1) frequencies[i]++;

    std::vector<int> res;
    for(int i : arr2) {
      for(int j = 0; j < frequencies[i]; j++) {
        res.push_back(i);
      }
      frequencies[i] = 0;
    }

    for(std::pair<int, int> i : frequencies) {
      for(int j = 0; j < i.second; j++) res.push_back(i.first);
    }

    return res;
  }
};

int main (int argc, char *argv[]) {
  Solution res;
  std::vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
  std::vector<int> arr2 = {2,1,4,3,9,6};
  std::cout << std::endl;
  for(int i : res.relativeSortArray(arr1, arr2)) std::cout << i << ", ";
  std::cout << std::endl;
}
