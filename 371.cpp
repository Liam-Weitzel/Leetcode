class Solution { // Jan 30, 2026
public:
  int getSum(int a, int b) {
    // Approach: Bit Manipulation (Binary Addition)
    //
    // Goal:
    // Compute the sum of two integers without using the '+' or '-' operators.
    //
    // Key Observations:
    //     XOR (^) adds two bits without considering carry.
    //     AND (&) followed by left shift gives the carry bits.
    //
    // Algorithm:
    //     While there is a carry (b ≠ 0):
    //         carry = (a & b) << 1 // compute carry bits
    //         a = a ^ b // sum without carry
    //         b = carry // propagate carry
    //     When no carry remains, a holds the final sum.
    //
    // Why It Works:
    //     This mimics binary addition at the bit level.
    //     Repeats until all carry bits are resolved.
    //
    // Time Complexity: O(1) (bounded by number of bits, typically 32)
    // Space Complexity: O(1)

    while( b != 0 ) {
      int carry = (a & b) << 1;
      a = a ^ b;
      b = carry;
    }

    return a;
  }
};
