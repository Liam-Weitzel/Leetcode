import java.util.*;
import java.util.stream.*;

class Solution { // Aug 17, 2024
    public static class Pair<K, V> {
        private final K key;
        private final V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(key, pair.key) && Objects.equals(value, pair.value);
        }

        @Override
        public int hashCode() {
            return Objects.hash(key, value);
        }

        @Override
        public String toString() {
            return "Pair{" + "key=" + key + ", value=" + value + '}';
        }
    }

    private Map<Pair<Integer, Integer>, Long> memo;
    int[][] points;

    private long dfs(int row, int col) {
        Pair<Integer, Integer> curr = new Pair<>(row, col);
        if (memo.containsKey(curr)) return memo.get(curr);
        if (row + 1 == points.length) return points[row][col];

        long max = 0;
        for (int i = 0; i < points[row + 1].length; i++) {
            long newScore = dfs(row + 1, i) - Math.abs(i - col);
            max = Math.max(max, newScore);
        }
        
        max += points[row][col];
        memo.put(curr, max);
        return max;
    }

    public long maxPoints(int[][] points) {
        this.memo = new HashMap<>();
        this.points = points;
        long max = 0;
        for(int i = 0; i < points[0].length; i++) {
            max = Math.max(max, dfs(0, i));
        }
        return max;
    }

    public static void testSolution(int[][] points, long expected) {
        Solution solution = new Solution();
        final long ans = solution.maxPoints(points);

        if (ans == expected) System.out.println("\033[1;32m"); // color output text green
        else System.out.println("\033[1;31m"); // color output text red

        System.out.println("Points: " + Arrays.deepToString(points));
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution(new int[][]{{1, 2, 3}, {1, 5, 1}, {3, 1, 1}}, 9);
        testSolution(new int[][]{{1, 5}, {2, 3}, {4, 2}}, 11);
    }
}
