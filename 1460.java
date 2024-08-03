import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.*;

class Solution { // Aug 03, 2024
    public static boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            int incremented = map.getOrDefault(i, 0) + 1;
            map.put(i, incremented);
        }

        for (int i : target) {
            int decremented = map.getOrDefault(i, 0) - 1;
            if(decremented < 0) return false;
            map.put(i, decremented);
        }

        return true;
    }

    public static void testSolution(int[] target, int[] arr, final boolean expected) {
        final boolean ans = canBeEqual(target, arr);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Target: " + target);
        System.out.println("Arr: " + arr);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new int[]{1,2,3,4}, new int[]{2,4,1,3}, true);
        testSolution(new int[]{7}, new int[]{7}, true);
        testSolution(new int[]{1,2,3,8}, new int[]{2,4,1,3}, false);
    }
}
