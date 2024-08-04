import java.util.*;
import java.util.stream.*;

class Solution { // Aug 01, 2024
    public static int countSeniors(String[] details) {
        return (int) Arrays.stream(details).filter(x -> Integer.valueOf(x.substring(11, 13)) > 60).count();
    }

    public static void testSolution(String[] details, final int expected) {
        final int ans = countSeniors(details);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Details: " + details);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new String[]{"7868190130M7522","5303914400F9211","9273338290F4010"}, 2);
        testSolution(new String[]{"1313579440F2036","2921522980M5644"}, 0);
    }
}
