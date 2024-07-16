//COMPILED USING: g++ 2096.cpp utils/TreeFactory.cpp utils/TreePrinter.cpp -g -o 2096

#include "utils/TreeNode.h"
#include "utils/TreeFactory.h"
#include "utils/TreePrinter.h"
#include <iostream>

class Solution { // Jul 16, 2024
public:
  std::string getDirections(TreeNode* root, int startValue, int destValue) {
    std::string pathRootToStart = dfsGetPath(root, startValue);
    std::string pathRootToDest = dfsGetPath(root, destValue);
    std::string pathLCAToStart = removeCommonPrefixButOne(pathRootToStart, pathRootToDest);
    std::string pathLCAToDest = removeCommonPrefixButOne(pathRootToDest, pathRootToStart);

    //Replace all chars in start with U's
    //Append pathLCAToDest?

    return "";
  }

private:
  std::string dfsGetPath(TreeNode* node, int target) {
    
    return "";
  }

  std::string removeCommonPrefixButOne(std::string s1, std::string s2) {
    
    return s1;
  }

};

void testSolution(std::vector<int> nums, int startValue, int destValue, std::string expected) {
  TreeNode* inputTree = TreeFactory::CreateTree(nums);

  Solution solution;
  std::string res = solution.getDirections(inputTree, startValue, destValue);

  if(res == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Input:" << std::endl;
  TreePrinter::PrintTree(inputTree);
  std::cout << std::endl;

  std::cout << "Output: " << res << std::endl;
  std::cout << std::endl;

  std::cout << "Expected: " << expected << std::endl;
  std::cout << "\033[0m" << std::endl;
  std::cout << "--------------------------" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({5,1,2,3,-1,6,4}, 3, 6, "UURL");
  testSolution({2,1}, 2, 1, "L");
}
