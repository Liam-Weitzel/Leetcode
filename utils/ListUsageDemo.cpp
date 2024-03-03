//COMPILED USING: g++ ListUsageDemo.cpp ListFactory.cpp ListPrinter.cpp -o ListUsageDemo

#include <cstdlib>
#include "ListNode.h"
#include "ListPrinter.h"
#include "ListFactory.h"
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> values = {1, 2, 3, 4, 5};
  ListNode* list = ListFactory::CreateList(values);
  ListPrinter::PrintList(list);
  free(list);
  return 0;
}
