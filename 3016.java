import java.util.*; 
import java.io.*;

class Pair {
    private final String key;
    private final Integer val;

    public Pair(String key, Integer val) {
        this.key = key;
        this.val = val;
    }

    public String getKey() {
        return key;
    }

    public Integer getVal() {
        return val;
    }
}

class Solution { // Aug 06, 2024
    public static int minimumPushes(String word) {
        Map<String, Integer> freqMap = new HashMap<>();

        for(char i : word.toCharArray()) {
            String key = "" + i;
            Integer incremented = freqMap.getOrDefault(key, 0) + 1;
            freqMap.put(key, incremented);
        }

        PriorityQueue<Pair> freqHeap = new PriorityQueue<>(Comparator.comparingInt(Pair::getVal).reversed());

        for (Map.Entry<String, Integer> entry : freqMap.entrySet()) {
            freqHeap.add(new Pair(entry.getKey(), entry.getValue()));
        }

        Map<String, Integer> keyMap = new HashMap<>();
        int[] assignedPerKey = new int[8];
        int key = 0;

        while(!freqHeap.isEmpty()) {
            Pair curr = freqHeap.poll();
            assignedPerKey[key]++;
            keyMap.put(curr.getKey(), assignedPerKey[key]);
            key++;
            if(key > 7) key = 0;
        }

        int res = 0;
        for (Map.Entry<String, Integer> entry : freqMap.entrySet()) {
            res += keyMap.get(entry.getKey()) * entry.getValue();
        }

        return res;
    }

    public static void testSolution(String word, final int expected) {
        final int ans = minimumPushes(word);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Word: " + word);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution("abcde", 5);
        testSolution("xyzxyzxyzxyz", 12);
        testSolution("aabbccddeeffgghhiiiiii", 24);
    }
}
