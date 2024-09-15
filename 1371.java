import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

// Given the string s, 
// return the size of the longest substring containing each vowel an even number of times. 
// That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

class Solution { // Sep 15, 2024
    public int findTheLongestSubstring(String s) {
        Set<Character> vowels = new HashSet<>(java.util.Arrays.asList('a', 'e', 'i', 'o', 'u'));
        int bitmask = 0;
        Map<Integer, Integer> bitmaskToIndex = new HashMap<>();
        bitmaskToIndex.put(0, -1);
        
        int maxLength = 0;

        for(int i = 0; i < s.length(); i++) {
            if(vowels.contains(s.charAt(i))) {
                bitmask ^= (1 << (s.charAt(i) - 'a'));
            }
            if (bitmaskToIndex.containsKey(bitmask)) {
                maxLength = Math.max(maxLength, i - bitmaskToIndex.get(bitmask));
            } else {
                bitmaskToIndex.put(bitmask, i);
            }
        }

        return maxLength;
    }

    public static void testSolution(String s, int expected) {
        Solution solution = new Solution();
        int ans = solution.findTheLongestSubstring(s);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("S: " + s);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution("eleetminicoworoep", 13);
        testSolution("leetcodeisgreat", 5);
        testSolution("bcbcbc", 6);
    }
}
