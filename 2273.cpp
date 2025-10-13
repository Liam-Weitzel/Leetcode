#include <algorithm>
#include <map>
#include <string>
#include <vector>

class Solution { // Oct 13, 2025
public:
    std::vector<std::string> removeAnagrams(std::vector<std::string>& words) {
        std::map<std::vector<int>, std::vector<int>> anagrams; //sorted chars of word -> index of word
        for(int i = 0; i < words.size(); i++) {
            std::vector<int> key(26, 0);
            for(char c : words[i]) key[c-'a']++;
            anagrams[key].push_back(i);
        }

        std::vector<int> toRemove;
        for(auto pair : anagrams) {
            //std::cout << std::accumulate(pair.first.begin(), pair.first.end(), 0) << std::endl;
            for(int i = 0; i < pair.second.size()-1; i++) {
                //std::cout << pair.second[i] << " == " << pair.second[i+1] << std::endl;
                if(pair.second[i]+1 == pair.second[i+1])
                    toRemove.push_back(pair.second[i+1]);
            }
        }

        std::sort(toRemove.begin(), toRemove.end());
        for(int i = toRemove.size()-1; i >= 0; i--) {
            //std::cout << toRemove[i] << ", ";
            words.erase(words.begin()+toRemove[i]);
        }
        return words;
    }
};
