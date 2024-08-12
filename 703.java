import java.util.*;
import java.util.stream.*;

class KthLargest { // Aug 12, 2024
    private PriorityQueue<Integer> minHeap;
    private int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        minHeap = new PriorityQueue<>(k);
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.offer(num);
            } else if (num > minHeap.peek()) {
                minHeap.offer(num);
                if (minHeap.size() > k) {
                    minHeap.poll();
                }
            }
        }
    }
    
    public int add(int val) {
        if (minHeap.size() < k) {
            minHeap.offer(val);
        } else if (val > minHeap.peek()) {
            minHeap.offer(val);
            minHeap.poll();
        }
        return minHeap.peek();
    }
}

class Main {
    public static void testSolution(String[] methods, int[][][] params, int[] expected) {
        KthLargest obj = new KthLargest(1, new int[]{1});
        int[] ans = new int[methods.length];
        for (int i = 0; i < methods.length; i++) {
            String method = methods[i];
            if(method.equals("KthLargest")) {
                obj = new KthLargest(params[i][0][0], params[i][1]);
                ans[i] = -1;
            } else if (method.equals("add")) {
                ans[i] = obj.add(params[i][0][0]);
            }
        }

        if(Arrays.equals(ans, expected)) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.print("Methods: ");
        for (String i : methods) {
            System.out.print(i + ", ");
        }
        System.out.println();

        System.out.print("Params: ");
        for (int[][] i : params) {
            System.out.print("[");
            for(int[] j : i) {
                System.out.print("[");
                for(int x : j) {
                    System.out.print(x + ", ");
                }
                System.out.print("],");
            }
            System.out.print("],");
        }
        System.out.println();

        System.out.print("Output: ");
        for (int i : ans) {
            System.out.print(i + ", ");
        }
        System.out.println();

        System.out.print("Expected: ");
        for (int i : expected) {
            System.out.print(i + ", ");
        }
        System.out.println("\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new String[]{"KthLargest","add","add","add","add","add"}, new int[][][]{{{3},{4,5,8,2}},{{3}},{{5}},{{10}},{{9}},{{4}}}, new int[]{-1, 4, 5, 5, 8, 8});
    }
}
