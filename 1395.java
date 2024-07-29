import java.util.*;
import java.util.stream.*;

class Solution { // Jul 29, 2024
    public static int numTeams(int[] rating) {
        int n = rating.length;

        int numTeams = IntStream.range(0, n).map(j -> {
            int lessLeft = (int) IntStream.range(0, j).filter(i -> rating[i] < rating[j]).count();
            int greaterLeft = (int) IntStream.range(0, j).filter(i -> rating[i] > rating[j]).count();

            int lessRight = (int) IntStream.range(j + 1, n).filter(k -> rating[k] < rating[j]).count();
            int greaterRight = (int) IntStream.range(j + 1, n).filter(k -> rating[k] > rating[j]).count();

            return lessLeft * greaterRight + greaterLeft * lessRight;
        }).sum();

        return numTeams;
    }

    public static void testSolution(int[] rating, int expected) {
        Integer ans = numTeams(rating);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Rating: " + rating);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution(new int[]{2,5,3,4,1}, 3);
        testSolution(new int[]{2,1,3}, 0);
        testSolution(new int[]{1,2,3,4}, 4);
    }
}
