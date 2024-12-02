#include <iostream>
#include <vector>

class Solution { // Dec 02, 2024
public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    std::vector<std::string> words;
    size_t pos = 0;
    std::string word;
    while((pos = sentence.find(' ')) != std::string::npos) {
      word = sentence.substr(0, pos);
      words.push_back(word);
      sentence.erase(0, pos + 1);
    }
    words.push_back(sentence);

    for(int i = 0; i < words.size(); i++) {
      if(words[i].find(searchWord) == 0) return i+1;
    }

    return -1;
  }
};

void testSolution(std::string sentence, std::string searchWord, int expected) {
  Solution res;
  int ans = res.isPrefixOfWord(sentence, searchWord);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Sentence: " << sentence << std::endl;
  std::cout << "Search word: " << searchWord << std::endl;

  std::cout << "Output: " << ans << std::endl;

  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("i love eating burger", "burg", 4);
  testSolution("this problem is an easy problem", "pro", 2);
  testSolution("i am tired", "you", -1);
  testSolution("hello from the other side", "they", -1);
  testSolution("hellohello hellohellohello", "ell", -1);
}
