#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <vector>

class Solution { // Apr 08, 2024
public:
  int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
    std::stack<int> sandwichesStack;
    std::queue<int> studentsQueue;
    int numOfIterationsNothingChanged = 0;

    for(int i = sandwiches.size()-1; i >= 0; --i) sandwichesStack.push(sandwiches[i]);
    for(int i : students) studentsQueue.push(i);

    while(numOfIterationsNothingChanged < studentsQueue.size()*2 && !studentsQueue.empty() && !sandwichesStack.empty()) {
      if(sandwichesStack.top() == studentsQueue.front()) {
        numOfIterationsNothingChanged = 0;
        sandwichesStack.pop();
        studentsQueue.pop();
      } else {
        studentsQueue.push(studentsQueue.front());
        studentsQueue.pop();
        numOfIterationsNothingChanged++;
      }
    }

    return studentsQueue.size();
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> students = {1,1,1,0,0,1};
  std::vector<int> sandwiches = {1,0,0,0,1,1};
  std::cout << res->countStudents(students, sandwiches) << std::endl;
  return 0;
}
