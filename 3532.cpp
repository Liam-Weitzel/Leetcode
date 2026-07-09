#include <cstdlib>
#include <vector>

class Solution { // Jul 09, 2026
public:
  std::vector<bool> pathExistenceQueries(int n, std::vector<int>& nums, int maxDiff, std::vector<std::vector<int>>& queries) {
    // nums = non decreasing order
    // n = nums.size()
    // int maxDiff
    // an undirected edge automatically exists if |nums[i] - nums[j]| <= maxDiff
    // for each query, check if a path exists.
    // return vec bool for all queries if path exists or not

    //pre computing OP
    //we can just group the connected nodes in a set
    //then we have O(1) lookup for each query
    //creating this would be O(n) - since we have to check each connection for maxDiff its actually O(n^2)
    //so total TC is O(n^2)
    //can we optimize this to be O(nlogn with binary search?) Its already guaranteed to be sorted

    // Input: n = 4, nums = [2,5,6,8], maxDiff = 2, queries = [[0,1],[0,2],[1,3],[2,3]]
    //
    // Output: [false,false,true,true]

    //2, 5, 6, 8
    //creating the graph: sort + binary search N times -> nlogn
    //dfs to find connected components = o(n)
    //lookup queries in sets = o(n)

    //realization, its pre sorted and we are solving the wrong problem
    //all we need to know is which nodes are connected, we dont wanna traverse it at all...
    //we can just use the pre-sorted array instead and iterate over it in O(n^2/2)
    //but since we know the answer for the previous, we can skip directly there.

    //realization, im doing it wrong, we just wanna check if the diff between cur and prev is <= maxDiff.
    //if yes, add it to this set, otherwise create a new one...

    int group = 0;
    std::vector<int> indexToGroup(n);

    for(int i = 1; i < nums.size(); i++) {
      if(std::abs(nums[i-1] - nums[i]) > maxDiff) group++;
      indexToGroup[i] = group;
    }

    std::vector<bool> res;
    res.reserve(queries.size());
    for(std::vector<int> query : queries) {
      if(indexToGroup[query[0]] == indexToGroup[query[1]]) res.push_back(true);
      else res.push_back(false);
    }

    return res;
  }
};
