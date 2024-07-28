import java.util.*;

class Solution {
    private static int ETA(Integer currTime, Integer time, Integer change) {
        boolean green = (Math.floor(currTime/change)%2 == 0);
        if(green) return currTime + time;
        Integer timeRemainingUntilGreen = change-(currTime%change);
        return currTime + timeRemainingUntilGreen + time;
    }

    public static int secondMinimum(int n, int[][] edges, int time, int change) {
        ArrayList<ArrayList<Integer>> edgesList = new ArrayList<>();
        Map<Integer, ArrayList<Integer>> adjacencyMap = new HashMap<>();
        for(int i = 0; i < edges.length; i++) {
            ArrayList<Integer> pair = new ArrayList<>();
            pair.add(edges[i][0]);
            pair.add(edges[i][1]);
            edgesList.add(pair);
        }

        edgesList.forEach(i -> {
            adjacencyMap.put(i.get(0), adjacencyMap.getOrDefault(i.get(0), new ArrayList<Integer>()));
            adjacencyMap.get(i.get(0)).add(i.get(1));

            adjacencyMap.put(i.get(1), adjacencyMap.getOrDefault(i.get(1), new ArrayList<Integer>()));
            adjacencyMap.get(i.get(1)).add(i.get(0));
        });

        Queue<ArrayList<Integer>> q = new LinkedList<>();
        Set<ArrayList<Integer>> s = new HashSet<>();
        ArrayList<Integer> first = new ArrayList<>();
        first.add(1);
        first.add(0);
        q.add(first);
        s.add(first);
        
        Integer optimal = -1;
        while(!q.isEmpty()) {
            ArrayList<Integer> front = q.poll();
            if(front.get(0) == n) {
                if(optimal != -1 && front.get(1) != optimal) return front.get(1);
                else optimal = front.get(1);
            }
            
            adjacencyMap.get(front.get(0)).forEach(i -> {
                ArrayList<Integer> next = new ArrayList<>();
                next.add(i);
                next.add(ETA(front.get(1), time, change));
                if(!s.contains(next)) {
                    q.add(next);
                    s.add(next);
                }
            });
        }

        return 0;
    }

    public static void testSolution(int n, int[][] edges, int time, int change, int expected) {
        Integer ans = secondMinimum(n, edges, time, change);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("N: " + n);
        System.out.println("Edges: " + edges);
        System.out.println("Time: " + time);
        System.out.println("Change: " + change);

        System.out.println("Output: " + ans);

        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(String[] args) {
        testSolution(5, new int[][]{{1,2},{1,3},{1,4},{3,4},{4,5}}, 3, 5, 13);
        testSolution(2, new int[][]{{1,2}}, 3, 2, 11);
    }
}
