#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <ostream>
#include <set>
#include <vector>

class Solution { // Jul 16, 2026
private:
  int gcd(int a, int b) {
    int remainder = std::min(a, b);
    int prevRemainder = 0;
    while(remainder != 0) {
      prevRemainder = remainder;
      remainder = std::max(a, b) % std::min(b, a);
      b = std::min(b, a);
      a = remainder;
    }
    return prevRemainder;
  }

public:
  long long gcdSum(std::vector<int>& nums) {
    int n = nums.size();

    std::vector<int> prefixMax(n);
    int maxSoFar = INT_MIN;
    //std::cout << "prefixMax: ";
    for(int i = 0; i < n; i++) {
      maxSoFar = std::max(nums[i], maxSoFar);
      prefixMax[i] = maxSoFar;
      //std::cout << prefixMax[i] << ", ";
    }
    //std::cout << std::endl;

    std::multiset<int> prefixGcd;
    //std::cout << "prefixGcd: ";
    for(int i = 0; i < n; i++) {
      //std::cout << prefixMax[i] << " % " << nums[i] << " = "; 
      int cur = gcd(prefixMax[i], nums[i]);
      prefixGcd.insert(cur);
      //std::cout << cur << " : ";
    }
    //std::cout << std::endl;

    std::vector<int> gcdValues;
    //std::cout << "gcdSize: " << prefixGcd.size() << std::endl;
    //std::cout << "gcdValues: ";

    while(prefixGcd.size() >= 2) {
      auto front = prefixGcd.begin();
      auto back = std::prev(prefixGcd.end());
      int min = *front;
      int max = *back;
      //std::cout << min << " % " << max << " = "; 
      gcdValues.push_back(gcd(min, max));
      //std::cout << gcdValues.back() << " : ";
      prefixGcd.erase(back);
      prefixGcd.erase(front);
    }
    //std::cout << std::endl;

    return std::accumulate(gcdValues.begin(), gcdValues.end(), 0LL);
  }
};
