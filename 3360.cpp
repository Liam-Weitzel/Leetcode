class Solution { // Nov 26, 2026
public:
  bool canAliceWin(int n) {
    // 10+9+8+7+6+5+4+3+2+1
    // 10
    // 19
    // 27
    // 34
    // 40
    // 45
    // 49
    // 52

    //but 1 <= n <= 50

    //cases where alice wins
    // 10-19, 27-34, 40-45, 49-52

    if(n >= 10 && n < 19) return true;
    if(n >= 27 && n < 34) return true;
    if(n >= 40 && n < 45) return true;
    if(n >= 49 && n <= 50) return true;

    return false;
  }
};
