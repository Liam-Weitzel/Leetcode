#include <algorithm>
#include <vector>

class Solution { // Jul 13, 2025
public:
  int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
    std::sort(players.begin(), players.end());
    std::sort(trainers.begin(), trainers.end());

    int lastTrainer = -1;
    int count = 0;
    for(int i = 0; i < players.size(); i++) {
      for(int j = lastTrainer+1; j < trainers.size(); j++) {
        if(players[i] <= trainers[j]) {
          count++;
          lastTrainer = j;
          break;
        }
      }
    }

    return count;
  }
};
