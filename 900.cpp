#include <iostream>
#include <vector>

class RLEIterator { // Jul 18, 2026
// This is an O(N) time, O(N) space solution
private:
  std::vector<int> encoding;
  long long cur = 0;
  int lastIter = 0;
  long long lastCount = 0;
public:
  RLEIterator(std::vector<int>& encoding) {
    this->encoding = encoding;
    this->lastCount = encoding[0];
  }
  
  int next(int n) {
    this->cur += n;
    while(this->lastIter < this->encoding.size()-2 && this->lastCount < this->cur) {
      this->lastIter += 2;
      this->lastCount += this->encoding[this->lastIter];
    }
    std::cout << this->lastIter << " " << this->lastCount << " " << this->cur << std::endl;
    if(this->lastIter == this->encoding.size()-2 && this->lastCount < this->cur) return -1;
    return this->encoding[this->lastIter+1];
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
