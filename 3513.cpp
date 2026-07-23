#include <vector>
#include <bit>
#include <limits.h>

class Solution { // Jul 23, 2026
public:
  int uniqueXorTriplets(std::vector<int>& nums) {
    // nums = permutation a number in the range 1, nums.size();
    //so: how many unique xor triplets OUTPUTS can i make with the numbers given? 
    //1,2 = 1,1,1 = 1,1,2 = 1,2,2 = 2,2,2
    // = 2 as 1,1,1 and 1,1,2 are the same and 0,0,1 and 1,1,1 are the same

    //3,1,2 = 3,3,3 = 3,3,1 = 3,3,2 = 3,2,1
    // = 4 as only these options give use 0,1,2,3

    // at max it will be N+1?
    // XOR(3,3,2) is the same as XOR(2,2,2) is the same as XOR(1,1,2)
    // lets do this by hand...
    // 3 = 11
    // 2 = 10
    // 1 = 01

    // xor(3,3) = 00
    // xor(0,2) = 10
    // so xor(3,3,2) = 10

    // xor(2, 2) = 00
    // xor(0, 2) = 10
    // so xor(2,2,2) = 10

    // xor(1,1) = 00
    // xor(0,2) = 10
    // so xor(1,1,2) = 10

    // agreed. any same two numbers first will cancel out, then the last one is just the full answer...

    // O(N^2) solution is to just try and see each, lets see the topics. Array Math Bitmanipulation
    // Math is interesting since it confirms what I thought already
    // There is probably a mathematical expression for what have to return
    // But im not smart enough to deduce it

    // Lets see a hint
    //  1/3
    // What is the maximum and minimum value we can obtain using the given numbers?
    // - maximum is the result which has the most bits set
    // - so we take each number and see how many bits it cancels out if we XOR or if we don't
    // - computationally will be O(N) since we never want to do a duplicate i think
    // - same goes for minimum

    // lets see another hint
    //  2/3
    // Can we generate all numbers within that range?
    // - Yes we can since you're saying it here.

    // last hint
    //  3/3
    //     For n >= 3 we can obtain all numbers in [0, 2^(msb(n) + 1) - 1], where msb(n) is the index of the most significant bit in n’s binary representation (i.e., the highest power of 2 less than or equal to n). Handle the case when n <= 2 separately.
    // wtf?

    // so if the number of elements in nums is greater than or equal to 3 we can always get all numbers between 0 and 2^(most significant bit of(size of nums vector) + 1) -1. 

    // ok thanks for answer lets code it up...

    int n = nums.size();

    if (n == 1) return 1;
    if (n == 2) return 2;

    int bits = 64 - std::countl_zero((unsigned long long)n);
    return 1 << bits;
  }
};
