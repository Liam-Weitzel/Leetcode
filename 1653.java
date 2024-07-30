import java.util.*;
import java.util.stream.*;

class Solution { // Jul 30, 2024
    public static int minimumDeletions(String s) {
        int aCount = 0;
        int[] aArr = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'a') aCount++;
            aArr[i] = aCount;
        }

        int bCount = 0;
        int[] bArr = new int[s.length()];
        for (int i = s.length()-1; i >= 0; i--) {
            if(s.charAt(i) == 'b') bCount++;
            bArr[i] = bCount;
        }

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < s.length(); i++) {
            int curr = Math.abs(aArr[i]-aCount)+Math.abs(bArr[i]-bCount);
            if(curr < min) min = curr;
        }

        return min;
    }

    public static void testSolution(String s, int expected) {
        Integer ans = minimumDeletions(s);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("S: " + s);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution("aababbab", 2);
        testSolution("bbaaaaabb", 2);
        testSolution("aaabbaabb", 2);
        testSolution("aaabaa", 1);
        testSolution("a", 0);
    }
}
