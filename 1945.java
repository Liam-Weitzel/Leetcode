import java.util.*;
import java.util.stream.*;

// Given s, a string of lowercase english letters and an integer k.
// Convert s into an integer by replacing each letter with its position in the alphabet.
// Then transform the integer by replacing it with the sum of its digits.
// Repeat the transform operation k times in total
//
// For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:
//
//     Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
//     Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
//     Transform #2: 17 ➝ 1 + 7 ➝ 8
//
// Return the resulting integer after performing the operations described above.

class Solution { // Sep 03, 2024
    public static int getLucky(String s, int k) {
        char[] cArr = s.toCharArray();
        int[] intArr = new int[cArr.length];
        for (int i = 0; i < cArr.length; i++) {
            intArr[i] = cArr[i]-96;
        }

        String intStr = Arrays.toString(intArr)
        .replace(",", "")
        .replace("[", "")
        .replace("]", "")
        .replace(" ", "")
        .trim();
        int sum = 0;

        for (int i = 0; i < k; i++) {
            System.out.println(intStr);
            sum = 0;
            for (char c : intStr.toCharArray()) sum += Character.getNumericValue(c);
            intStr = String.valueOf(sum);
        }

        return sum;
    }

    public static void testSolution(String s, int k, int expected) {
        Solution solution = new Solution();
        int ans = solution.getLucky(s, k);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("String: " + s);
        System.out.println("K: " + k);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution("iiii", 1, 36);
        testSolution("leetcode", 2, 6);
        testSolution("zbax", 2, 8);
    }
}
