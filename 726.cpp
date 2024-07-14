#include <cctype>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>

class Solution { // Jul 14, 2024
public:
  std::string countOfAtoms(std::string formula) {
    formula.push_back('A');
    std::string lastElement = "";
    std::stack<std::map<std::string, int>> scope;
    scope.push(std::map<std::string, int>());

    for(char i : formula) {
      if(std::isupper(i) || i == '(' || i == ')') {
        size_t last_index = lastElement.find_last_not_of("0123456789");
        std::string number = lastElement.substr(last_index + 1);
        std::string element = lastElement.substr(0, last_index + 1);
        int num = (number == "" ? 1 : std::stoi(number));
        if(element == "(") {
          scope.push(std::map<std::string, int>());
        } else if (element == ")") {
          std::map<std::string, int> child = scope.top();
          scope.pop();
          for(std::pair<std::string, int> i : child) {
            scope.top()[i.first] += (i.second*num);
          }
        } 
        scope.top()[element]+=num;
        lastElement.clear();
      }
      lastElement.push_back(i);
    }

    std::string res = "";
    for(std::pair<std::string, int> i : scope.top()) {
      if(i.first != ")" && i.first != "(" && i.first != "") {
        res.append(i.first);
        if(i.second != 1) res.append(std::to_string(i.second));
      }
    }

    return res;
  }
};

void testSolution(std::string formula, std::string expected) {
  Solution res;
  std::string ans = res.countOfAtoms(formula);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Formula: " << formula << std::endl;
  std::cout << "Output: " << ans << std::endl;
  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution("H2O", "H2O");
  testSolution("Mg(OH)2", "H2MgO2");
  testSolution("K4(ON(SO3)2)2", "K4N2O14S4");
  testSolution("HHe", "HHe");
  testSolution("(H24)2He", "H48He");
}
