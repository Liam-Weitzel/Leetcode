#include <algorithm>
#include <deque>
#include <map>
#include <string>

class Solution { // Jul 28, 2026
public:
  std::string smallestPalindrome(std::string s) {
    //return the lexographically smallest palindromic permutation of s
    //input: s = "babab"
    // output: "abbba"
    //thing about palindromes:
    //1. odd count of chars always in the middle
    //2. cant have more than 1 odd count of chars
    //3. rest has to be even
    //dont we just slap everything into a sorted hashmap and put the odd in the middle?
    //no we dont, consider this case: "inini" != "niiin" which is what our algo would do
    //we have to do a greedy approach where we take half the elements and sort them to be lexographically then anther pass where we insert the remaining odd num;
    if(s.size() <= 2) return s;

    if(s.size()%2==0) {
      s.erase(s.size()/2, s.size()/2);
      std::sort(s.begin(), s.end());
      std::string sback = s;
      std::reverse(sback.begin(), sback.end());
      s.append(sback);
      return s;
    }
    std::map<char, int> charcount;
    for(char i : s) charcount[i]++;
    char odd = '0';
    for(std::pair<char, int> i : charcount) if(i.second%2!=0) odd = i.first;
    charcount[odd]--;

    //now make the smallest palindromic subsequence, add odd in the middle once;

    std::deque<char> dq;
    for (auto i = charcount.rbegin(); i != charcount.rend(); ++i) {
      for(int j = 0; j < i->second/2; j++) {
        dq.push_back(i->first);
        dq.push_front(i->first);
      }
    }

    std::string res = "";
    while(!dq.empty()) {
      res += dq.front();
      dq.pop_front();
      if(dq.size() == s.size()/2) res.push_back(odd);
    }

    //this works, have to get off the train so no time to clean up

    return res;
  }
};
