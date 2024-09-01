import java.util.*;
import java.util.stream.*;

// given a 0-indexed 1-dimensional (1D) integer array 'original', and two integers, m and n.
// Create a 2d array with m rows and n columns using all the elements from 'original'.
// The elements from indices 0 to n-1 inclusive of original should form the first row of the created 2d array.
// The elements from indices n to 2 * n-1 inclusive of original should form the second row of the created 2d array.

class Solution { // Sept 01, 2024
    public static int[][] construct2DArray(int[] original, int m, int n) {
        if(original.length != m*n) return new int[][]{};
        int[][] ans = new int[m][n];

        for(int mc = 0; mc < m; mc++) {
            for(int nc = 0; nc < n; nc++) {
                ans[mc][nc] = original[mc*n+nc];
            }
        }
        
        return ans;
    }

    public static void testSolution(int[] original, int m, int n, int[][] expected) {
        Solution solution = new Solution();
        int[][] ans = solution.construct2DArray(original, m, n);

        if(Arrays.deepToString(ans).equals(Arrays.deepToString(expected))) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Original: " + Arrays.toString(original));
        System.out.println("M: " + m);
        System.out.println("N: " + n);
        System.out.println("Expected: " + Arrays.deepToString(expected) + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new int[]{1,2,3,4}, 2, 2, new int[][]{{1,2},{3,4}});
    }
}
