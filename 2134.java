import java.util.*;
import java.util.stream.*;


class Solution { // Aug 02, 2024
    public static int minSwaps(int[] nums) {
        int[] copyOfNums = new int[nums.length*2];
        for(int i = 0; i < copyOfNums.length; i++) {
            int curr = i%nums.length;
            copyOfNums[i] = nums[curr];
        }

        int total = (int) Arrays.stream(nums).sum();
        int left = 0;
        int right = total-1;
        int numOfSwaps = (int) Arrays.stream(copyOfNums, left, total).filter(x -> x == 0).count();
        int minNumberOfSwaps = numOfSwaps;

        while(right < copyOfNums.length-1) {
            right++;
            left++;
            if(copyOfNums[left-1] == 0) numOfSwaps--;
            if(copyOfNums[right] == 0) numOfSwaps++;
            minNumberOfSwaps = Math.min(minNumberOfSwaps, numOfSwaps);
        }

        return minNumberOfSwaps;
    }

    public static void testSolution(int[] nums, final int expected) {
        final int ans = minSwaps(nums);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Nums: " + nums);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new int[]{0,1,0,1,1,0,0}, 1);
        testSolution(new int[]{0,1,1,1,0,0,1,1,0}, 2);
        testSolution(new int[]{1,1,0,0,1}, 0);
    }
}
