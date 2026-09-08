class Solution { // Sep 08, 2026
public:
  int countCommas(int n) {
    //Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.
    //A comma is placed every 3 digits.
    //We defo don't wanna iterate from 1, n.
    //What we can do instead is through the powers of 1000
    //But the last bit we will have to add only the difference between the closest power of 1000 and n.

    // 9805
    // cur = 1000;
    // res = 0;
    // 9999805/1000 = 9999.805
    // res += 1000 * 1;
    // 9999805/1000000 = 9.999805
    // res += 1000000 * 2;
    // 9999805/1000000000 = 0.009999805
    // res += 9999805 - 1000000;

    long long cur = 1000;
    int comma = 1;
    long long res = 0;

    while(n / cur >= 1000) {
      res += (cur * 1000 - cur) * comma;
      cur *= 1000;
      comma++;
    }

    if(n >= cur)
      res += (n - cur + 1) * comma;

    return res;
  }
};
