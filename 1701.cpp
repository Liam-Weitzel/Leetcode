#include <vector>
#include <iostream>

class Solution { // Jul 09, 2024
public:
  double averageWaitingTime(std::vector<std::vector<int>> customers) {
    long waitingTimeSum = 0;
    int previousWillBeDoneAt = 0;

    for(std::vector<int> i : customers) {
      int orderStartTime = std::max(previousWillBeDoneAt, i[0]);
      waitingTimeSum += (orderStartTime + i[1]) - i[0];
      previousWillBeDoneAt = orderStartTime + i[1];
    }

    return (double) waitingTimeSum / customers.size();
  }
};

/* Java version:
class Solution {
  public double averageWaitingTime(int[][] customers) {
    long waitingTimeSum = 0;
    int previousWillBeDoneAt = 0;

    for(int[] i : customers) {
      int orderStartTime = Math.max(previousWillBeDoneAt, i[0]);
      waitingTimeSum += (orderStartTime+i[1])-i[0];
      previousWillBeDoneAt = orderStartTime+i[1];
    }

    return (double) waitingTimeSum/customers.length;
  }
}
*/

void testSolution(std::vector<std::vector<int>> customers, double expected) {
  Solution res;
  double ans = res.averageWaitingTime(customers);

  if(ans == expected) std::cout << "\033[1;32m"; //color output text green
  else std::cout << "\033[1;31m"; //color output text red

  std::cout << "Customers: ";
  for(std::vector<int> i : customers) {
    std::cout << "[" << i[0] << ", " << i[1] << "]";
  }
  std::cout << std::endl;

  std::cout << "Output: " << ans << std::endl;
  std::cout << "Expected: " << expected << "\033[0m" << std::endl << std::endl;
}

int main (int argc, char *argv[]) {
  testSolution({{1,2},{2,5},{4,3}}, 5.00000);
  testSolution({{5,2},{5,4},{10,3},{20,1}}, 3.250000);
}
