import java.util.*;
import java.util.stream.*;

class Solution { // Aug 09, 2024
    public static int numMagicSquaresInside(int[][] grid) {
        Set<String> magicSquares = new HashSet<>();

        magicSquares.add(Arrays.deepToString(new int[][]{
                {4, 9, 2},
                {3, 5, 7},
                {8, 1, 6}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {8, 3, 4},
                {1, 5, 9},
                {6, 7, 2}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {6, 1, 8},
                {7, 5, 3},
                {2, 9, 4}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {2, 7, 6},
                {9, 5, 1},
                {4, 3, 8}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {2, 9, 4},
                {7, 5, 3},
                {6, 1, 8}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {6, 1, 8},
                {7, 5, 3},
                {2, 9, 4}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {4, 3, 8},
                {9, 5, 1},
                {2, 7, 6}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {8, 1, 6},
                {3, 5, 7},
                {4, 9, 2}}));

        magicSquares.add(Arrays.deepToString(new int[][]{
                {6, 7, 2},
                {1, 5, 9},
                {8, 3, 4}}));

        int res = 0;
        for(int i = 1; i < grid.length-1; i++) {
            for(int j = 1; j < grid[0].length-1; j++) {
                if(grid[i][j] == 5) {
                    int[][] curr = new int[][]{
                        {grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]},
                        {grid[i][j-1], grid[i][j], grid[i][j+1]},
                        {grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]}
                    };

                    // printSquare(curr);
                    // System.out.println(isMagic(curr));

                    if(magicSquares.contains(Arrays.deepToString(curr))) res++;
                }
            }
        }

        return res;
    }

    public static boolean isMagic(int[][] square) {
        int magicSum = 15;

        // Check rows
        for (int i = 0; i < 3; i++) {
            if (square[i][0] + square[i][1] + square[i][2] != magicSum) {
                return false;
            }
        }

        // Check columns
        for (int i = 0; i < 3; i++) {
            if (square[0][i] + square[1][i] + square[2][i] != magicSum) {
                return false;
            }
        }

        // Check diagonals
        if (square[0][0] + square[1][1] + square[2][2] != magicSum) {
            return false;
        }
        if (square[0][2] + square[1][1] + square[2][0] != magicSum) {
            return false;
        }

        return true;
    }

    public static void printSquare(int[][] square) {
        for (int[] row : square) {
            System.out.println(Arrays.toString(row));
        }
    }

    public static void testSolution(int[][] grid, int expected) {
        final int ans = numMagicSquaresInside(grid);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Grid: ");
        printSquare(grid);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new int[][]{{4,3,8,4},{9,5,1,9},{2,7,6,2}}, 1);
        testSolution(new int[][]{{8}}, 0);
        testSolution(new int[][]{{4,5,1,5,3,8,1,9,2},{6,4,10,1,8,4,3,5,6},{4,2,5,8,0,5,10,4,8},{6,9,2,4,7,6,6,7,2},{8,0,5,10,0,0,1,5,9},{2,6,8,1,9,8,8,3,4},{5,9,9,7,10,1,7,2,4},{7,5,4,11,3,6,9,10,6},{3,6,6,6,5,11,2,1,5}}, 1);
    }
}
