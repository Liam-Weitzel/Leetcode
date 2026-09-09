class Solution {
public:
  long long countCommas(long long n) {
    // Same as 3870...

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
    return 0LL;
  }
};
