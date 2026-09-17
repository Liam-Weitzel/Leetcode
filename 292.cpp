class Solution { // Sep 17, 2026
public:
  bool canWinNim(int n) {
    //ON MY TURN:
    //if stones left = 1, i win
    //if stones left = 2, i win
    //if stones left = 3, i win
    //if stones left = 4, i can't win
    //if stones left = 5, i win
    //if stones left = 6, i win
    //if stones left = 7, i win
    //if stones left = 8, i can't win
    //if stones left = 9, i win
    //if stones left = 10, i win
    //if stones left = 11, i win
    //if stones left = 12, i can't win
    //etc. etc.
    //so it looks like 3 cases i can win, then one case i can't... so if n%4==0 return false

    if(n%4==0) return false;
    return true;
  }
};
