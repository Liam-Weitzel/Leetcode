import java.util.*;
import java.util.stream.*;

// There are n students in a class numbered from 0 to n - 1.
// The teacher gives each student a problem starting with student number 0.
// After that, the teacher restarts the process starting with student 0 again.
//
// Given an integer array chalk, and int k where k is the pieces of chalk to start with.
// When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem.
// However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.
//
// Return the index of the student that will replace the chalk pieces.
//
// Observations:
// It is a medium problem so iterative approach probably won't work. 
// All integers in chalk[i] are positive.
// I am thining binary search over a prefix sum of number of chalk pieces left.

class Solution { // Sep 02, 2024
    public static int chalkReplacer(int[] chalk, int k) {
        int noOfStudents = chalk.length;
        long[] prefixSum = Arrays.stream(chalk).mapToLong(i -> i).toArray();
        for(int i = 1; i < noOfStudents; ++i) prefixSum[i] += prefixSum[i-1];
        k %= prefixSum[noOfStudents-1];
        int l = 0, r = noOfStudents-1;

        while(l < r) {
            int mid = (l+r)/2;
            if(prefixSum[mid] > k) r = mid;
            else l = mid+1;
        }

        return l;
    }

    public static void testSolution(int[] chalk, int k, int expected) {
        Solution solution = new Solution();
        int ans = solution.chalkReplacer(chalk, k);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Chalk: " + Arrays.toString(chalk));
        System.out.println("K: " + k);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution(new int[]{5,1,5}, 22, 0);
        testSolution(new int[]{3,4,1,2}, 25, 1);
    }
}
