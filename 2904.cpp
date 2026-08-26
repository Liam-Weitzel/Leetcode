#include <algorithm>
#include <climits>
#include <cstddef>
#include <string>
#include <vector>

class Solution { // Aug 26, 2026
public:
  std::string shortestBeautifulSubstring(std::string s, int k) {
    //s = "100011001", k = 3
    //A substring of s is beautiful if the number of 1's in it is exactly k.
    //- prefix number of 1s?
    //Let len be the length of the shortest beautiful substring.
    //- ok so we take the shortest and that is len
    //Return the lexicographically smallest beautiful substring of string s with length equal to len. If s doesn't contain a beautiful substring, return an empty string.
    //- from all prossible shortest, take the lexicographically smallest
    //A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.
    //return "11001"
    //"100011001"
    //1 0 0 0 1 1 0 0 1 - s
    //1,1,1,1,2,3,3,3,4 - prefix one count - we don't actually need this step, we can do it implicitly during the sliding window
    //sliding window over prefix one count to find all substrings where number of 1's is equal to k (3)
    //"1 0 0 0 1 1", "0 0 0 1 1 0 0 1", "0 0 1 1 0 0 1, "0 1 1 0 0 1", "1 1 0 0 1"
    // find the shortest among these = 5
    // among the shortest , which one is the lexicographically smallest?
    // return that "11001"

    if(k == 1 && s.contains('1')) return "1";

    int left = 0;
    int right = 0;
    int count = 0;
    if(s[0] == '1') count++;
    std::vector<std::string> beautiful;
    while(left < s.size()) {
      if(count == k) {
        beautiful.push_back(s.substr(left, right+1-left));
      } else if(count < k && right < s.size()) {
        right++;
        if(s[right] == '1') count++;
        continue;
      }
      if(s[left] == '1') count--;
      left++;
    }

    std::size_t minLen = INT_MAX;
    for(std::string i : beautiful) minLen = std::min(minLen, i.size());

    std::vector<std::string> minLenBeautiful;
    for(std::string i : beautiful) if(i.size() == minLen) minLenBeautiful.push_back(i);

    std::sort(minLenBeautiful.begin(), minLenBeautiful.end());

    return minLenBeautiful.size() ? minLenBeautiful[0] : "";
  }
};
