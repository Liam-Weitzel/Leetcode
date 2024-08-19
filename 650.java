import java.util.*;
import java.util.stream.*;

class Solution { // Aug 19, 2024
    private int n;
    
    public int minSteps(int n) {
        if (n == 1) return 0;
        this.n = n;
        return 1 + dfs(1, 1);
    }
    
    private int dfs(int currentLength, int clipboardLength) {
        if (currentLength == n) return 0;
        if (currentLength > n) return Integer.MAX_VALUE / 2;
        
        int copyAndPaste = 2 + dfs(currentLength * 2, currentLength);
        int pasteOnly = 1 + dfs(currentLength + clipboardLength, clipboardLength);
        
        return Math.min(copyAndPaste, pasteOnly);
    }

    public static void testSolution(int n, int expected) {
        Solution solution = new Solution();
        final int ans = solution.minSteps(n);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("N: " + n);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(3, 3);
        testSolution(1, 0);
        testSolution(12, 7);
    }
}
