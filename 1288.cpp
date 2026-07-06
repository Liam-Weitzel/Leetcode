#include <vector>

class Solution { // Jul 06, 2026
public:
  int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
    // Input: intervals = [[1,4],[3,6],[2,8]]
    // Output: 2
    // Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

    // idea1: sort based on interval size?
    // add them a linkedlist and check if all values are already in an interval

    // idea2: flatten intervals into a vector of sorted value pair<int, bool>
    // if we see start -> start -> end -> end, we can remove the inner start end.
    // the whole array should be start -> end -> start -> end
    // not true, it can also be start -> start -> end -> end... we miss calculated

    // idea3: flatting intervals into a map: key start index, val pair<currently open, end index>
    // iterate over elements in map (sorted)

    // idea4: sort intervals by starting index, iterate over them
    // have a seperate array for keeping track of open ranges (start and end)
    // if we close an array, we compare it to all currently open arrays, if the start index is < my start index, we can remove it
    // O(N^2)
    
    // idea5: use 2 for loops
    // check for each pair that it covers by another or not
    // if cover inc the counter and break
    // O(N^2)

    // lets implement idea5 quickly due to time restraints

    int res = 0;
    std::vector<bool> removed(intervals.size());

    for(int i = 0; i < intervals.size(); i++) {
      std::vector<int> curr_i = intervals[i];
      for(int j = 0; j < intervals.size(); j++) {
        std::vector<int> curr_j = intervals[j];
        if(curr_j[0] <= curr_i[0] && curr_i[1] <= curr_j[1] && !removed[j] && !removed[i] && i != j) {
          res++;
          removed[i] = true;
          break;
        }
      }
    }

    return intervals.size() - res;
  }
};
