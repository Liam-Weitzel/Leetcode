import java.util.*;
import java.util.stream.*;

class Solution { // Aug 16, 2024
    public static int maxDistance(List<List<Integer>> arrays) {
        List<List<Integer>> mins = new ArrayList<>();
        List<List<Integer>> maxs = new ArrayList<>();

        for(int i = 0; i < arrays.size(); i++) { 
            mins.add(Arrays.asList(arrays.get(i).get(0), i));
            maxs.add(Arrays.asList(arrays.get(i).get(arrays.get(i).size()-1), i));
        }

        List<List<Integer>> filteredMins = mins.stream()
                .sorted((x,y) -> Integer.compare(x.get(0), y.get(0)))
                .limit(2)
                .collect(Collectors.toList());

        List<List<Integer>> filteredMaxs = maxs.stream()
                .sorted((x,y) -> Integer.compare(y.get(0), x.get(0)))
                .limit(2)
                .collect(Collectors.toList());

        mins = filteredMins;
        maxs = filteredMaxs;

        int res = 0;

        for(List<Integer> min : mins) {
            for(List<Integer> max : maxs) {
                if(min.get(1) != max.get(1)) {
                    int curr = Math.abs(min.get(0) - max.get(0));
                    res = Math.max(res, curr);
                }
            }
        }

        return res;
    }

    public static void testSolution(List<List<Integer>> arrays, int expected) {
        final int ans = maxDistance(arrays);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Arrays: " + arrays);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(Arrays.asList(Arrays.asList(1, 2, 3), Arrays.asList(4, 5), Arrays.asList(1, 2, 3)), 4);
        testSolution(Arrays.asList(Arrays.asList(1), Arrays.asList(1)), 0);
        testSolution(Arrays.asList(Arrays.asList(1,4), Arrays.asList(0,5)), 4);
    }
}
