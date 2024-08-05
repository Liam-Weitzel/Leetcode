import java.util.*;
import java.util.stream.*;

class Solution { // Aug 05, 2024
    public static String kthDistinct(String[] arr, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String i : arr) {
            Integer incremented = map.getOrDefault(i, 0) + 1;
            map.put(i, incremented);
        }

        int count = 0;
        for(String i : arr) {
            if(map.get(i) == 1) {
                count++;
                if(count == k) return i;
            }
        }

        return "";
    }

    public static void testSolution(String[] arr, int k, String expected) {
        final String ans = kthDistinct(arr, k);

        if(ans.equals(expected)) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Arr: " + arr);
        System.out.println("K: " + k);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new String[]{"d","b","c","b","c","a"}, 2, "a");
        testSolution(new String[]{"aaa","aa","a"}, 1, "aaa");
        testSolution(new String[]{"a","b","a"}, 3, "");
    }
}
