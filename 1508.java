import java.util.*;
import java.util.stream.*;

class Solution { // Aug 04, 2024
    public static int rangeSum(int[] nums, int n, int left, int right) {
        final int MOD = 1000000007;
        List<Integer> expandedNums = new ArrayList<>(n * (n + 1) / 2);

        for(int i = 0; i < n; i++) {
            int currSum = 0;
            for(int j = i; j < n; j++) {
                currSum += nums[j];
                currSum %= MOD;
                expandedNums.add(currSum);
            }
        }

        Collections.sort(expandedNums);
        int sum = 0;
        expandedNums = expandedNums.subList(left-1, right);
        for(int i : expandedNums) {
            sum += i;
            sum %= MOD;
        }
        
        return sum;
    }

    public static void testSolution(int[] nums, int n, int left, int right, final int expected) {
        final int ans = rangeSum(nums, n, left, right);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Nums: " + nums);
        System.out.println("N: " + n);
        System.out.println("Left: " + left);
        System.out.println("Right: " + right);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new int[]{1,2,3,4}, 4, 1, 5, 13);
        testSolution(new int[]{1,2,3,4}, 4, 3, 4, 6);
        testSolution(new int[]{1,2,3,4}, 4, 1, 10, 50);
    }
}
