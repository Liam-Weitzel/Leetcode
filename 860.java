import java.util.*;
import java.util.stream.*;

class Solution { // Aug 15, 2024
    public static boolean lemonadeChange(int[] bills) {
        int[] billsTaken = new int[3];

        for(int i : bills) {
            if(i == 5) billsTaken[0]++;
            if(i == 10) billsTaken[1]++;
            if(i == 20) billsTaken[2]++;

            int toReturn = i - 5;
            while(toReturn > 0 && (billsTaken[2] > 0 || billsTaken[1] > 0 || billsTaken[0] > 0)) {
                System.out.println(toReturn);
                if(toReturn >= 20 && billsTaken[2] > 0) {
                    toReturn -= 20;
                    billsTaken[2]--;
                } else if (toReturn >= 10 && billsTaken[1] > 0) {
                    toReturn -= 10;
                    billsTaken[1]--;
                } else if (toReturn >= 5 && billsTaken[0] > 0) {
                    toReturn -= 5;
                    billsTaken[0]--;
                } else {
                    return false;
                }
            }
            if(toReturn != 0) return false;
        }

        return true;
    }

    public static void testSolution(int[] bills, boolean expected) {
        boolean ans = lemonadeChange(bills);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Bills: " + Arrays.toString(bills));
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new int[]{5,5,5,10,20}, true);
        testSolution(new int[]{5,5,10,10,20}, false);
        testSolution(new int[]{5,5,5,5,20,20,5,5,5,5}, false);
    }
}
