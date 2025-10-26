#include <vector>

class Bank { // Oct 26, 2025
private:
  std::vector<long long> balance;

public:
  Bank(std::vector<long long>& balance) {
    this->balance = balance;
  }
  
  bool transfer(int account1, int account2, long long money) {
    account1--;
    account2--;
    if(account1 >= 0 && account1 < this->balance.size()) {
      if(account2 >= 0 && account2 < this->balance.size()) {
        if(this->balance[account1] - money >= 0) {
          this->balance[account1] -= money;
          this->balance[account2] += money;
          return true;
        }
      }
    }
    return false;
  }
  
  bool deposit(int account, long long money) {
    account--;
    if(account >= 0 && account < this->balance.size()) {
      this->balance[account] += money;
      return true;
    }
    return false;
  }
  
  bool withdraw(int account, long long money) {
    account--;
    if(account >= 0 && account < this->balance.size()) {
      if(this->balance[account] - money >= 0) { 
        this->balance[account] -= money;
        return true;
      }
    }
    return false;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
