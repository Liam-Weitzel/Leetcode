#include <map>
#include <numeric>
#include <set>
#include <vector>

class Solution { // Oct 18, 2025
public:
  int maxDistinctElements(std::vector<int>& nums, int k) {
    // k = 1, 3, 3-5
    // k = 2, 5, 2-6
    // k = 3, 7, 1-7
    // k = 4, 9, 0-8
    // each element can form (k*2)+1 distinct elements.
    // can't really be greedy here as maybe we meet another element that can ONLY be the one we just picked...
    // sorting!!
    // if we sort we can be greedy!
    // sorted freqmap & keep a set of used distinct numbers.
    if(k >= nums.size()) return nums.size();

    std::map<int, int> freqmap;
    for(int i : nums)
      freqmap[i]++;

    bool allOne = true;
    for(std::pair<int, int> i : freqmap) {
      if(i.second != 1) {
        allOne = false;
      }
    }
    if(allOne) return nums.size();

    std::set<int> used;
    for(std::pair<int, int> i : freqmap) {
      std::vector<int> range(k*2+1);
      std::iota(range.begin(), range.end(), i.first-k);
      // for(int x : range) std::cout << x << ", ";
      // std::cout << std::endl;
      int cur = 0;
      for(int j = 0; j < i.second; j++) {
        for(; cur < range.size(); cur++) {
          if(used.find(range[cur]) == used.end()) {
            used.insert(range[cur]);
            // std::cout << "inserting: " << range[cur] << std::endl;
            break;
          }
        }
      }
    }
    return used.size();
  }
};
