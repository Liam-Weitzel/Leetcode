import java.util.*;
import java.util.stream.*;

//n+m 6 sided dice are rolled.
//n of the observations went missing, and you only have the observations of m rolls.
//We have the average of n + m rolls.
//
//Return an array oflength n containing the missing observaions such that the average value of n + m rolls is exactly mean.
//If therea re multiple valid answers, return any of them. If noy such array exists, return an empty array.

class Solution { // Sep 05, 2024
    public static double findMean(int[] a, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += a[i];
        return (double)sum / (double)n;
    }

    public static int[] missingRolls(int[] rolls, int mean, int n) {
        int currDiff = 0;
        for(int i : rolls) currDiff += mean-i;
        int[] res = new int[n];
        for(int i = 0; i < n; i++) {
            int pick = Math.min(6, Math.max(1, mean+currDiff));
            res[i] = pick;
            currDiff -= mean-pick;
        }

        //NOTE: OUT OF TIME
        return res;
    }

    public static void testSolution(int[] rolls, int mean, int n, int[] expected) {
        Solution solution = new Solution();
        int[] ans = solution.missingRolls(rolls, mean, n);

        if(Arrays.toString(ans).equals(Arrays.toString(expected))) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Rolls: " + rolls);
        System.out.println("N: " + n);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution(new int[]{3,2,4,3}, 4, 2, new int[]{6,6});
        testSolution(new int[]{1,5,6}, 3, 4, new int[]{2,3,2,2});
        testSolution(new int[]{1,2,3,4}, 6, 4, new int[]{});
    }
}
