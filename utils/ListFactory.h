#ifndef LISTFACTORY_H
#define LISTFACTORY_H

#include "ListNode.h"
#include <vector>

class ListFactory {
public:
  static ListNode* CreateList(const std::vector<int>& values);
};

#endif // LISTFACTORY_H
