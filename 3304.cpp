#include <string>

class Solution { // Jul 03, 2025
public:
    char incrementChar(char i) {
        if(i == 'z') i = 'a';
        else i++;
        return i; 
    }

    std::string incrementString(std::string i) {
        for(int j = 0; j < i.size(); j++) i[j] = incrementChar(i[j]);
        return i;
    }

    char kthCharacter(int k) {
        std::string word = "a";
        while(word.size() < k) {
            word += incrementString(word);
        }
        return word[k-1];
    }
};
