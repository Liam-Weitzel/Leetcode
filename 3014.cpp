#include <string>

class Solution { // Jul 30, 2026
public:
  int minimumPushes(std::string word) {
    // if distinct chars in word <= 8 return word size
    // if(word.size() <= 8) return word.size();
    // if distinct chars in word > 8 
    // 8 + 8 + 8 + 2 = 26
    // at max 4 presses
    // each char gets a weight depending on their frequency
    // as if we assign a letter that appears 3 times to key that requires 4 presses the total cost = 3 * 4 
    // but if we assign a letter that appears 1 times to a key that requires 4 presses the total cost = 1 * 4 and we can do 3 * 1 for the other one...
    // so greedy, we assign the most frequently occuring chars first.
    //All letters in word are distinct. AHAHHA
    // then the answer is just 
    int res = 0;
    for(int i = 0; i < word.size(); i++) res += (i/8)+1;
    return res;
    // I know there is an O(1) formula for this but I can't find it. also this is basically O(1) as word.size() is capped at 26...
  }
};
