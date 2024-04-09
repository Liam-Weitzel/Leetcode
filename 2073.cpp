#include <iostream>
#include <memory>
#include <vector>

class Solution { // Apr 09, 2024
public:
  int timeRequiredToBuy(std::vector<int>& tickets, int k) {
    int time = 0;
    int iter = 0;
    while(tickets[k] != 0) {
      if(tickets[iter] > 0) {
        time++;
        tickets[iter]--;
      }
      iter++;
      if(iter >= tickets.size()) iter = 0;
    }
    return time;
  }
};

int main (int argc, char *argv[]) {
  std::unique_ptr<Solution> res = std::make_unique<Solution>();
  std::vector<int> tickets = {2,3,2};
  std::cout << res->timeRequiredToBuy(tickets, 2) << std::endl;
  return 0;
}
