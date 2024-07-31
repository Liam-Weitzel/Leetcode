import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.*;

class Solution { // Jul 31, 2024
    public static int minHeightShelves(final int[][] books, final int shelfWidth) {

        Arrays.sort(books, new java.util.Comparator<int[]>() {
            public int compare(final int[] a, final int[] b) {
                return Integer.compare(b[1], a[1]);
            }
        });

        int currShelfHeight = 0;
        int totalHeight = 0;
        final AtomicInteger currSpaceLeftOnShelf = new AtomicInteger(shelfWidth);
        final Set<int[]> usedBooks = new HashSet<>();

        while(usedBooks.size() != books.length) {
            final Optional<int[]> nextBook = Arrays.stream(books)
                .filter(x -> !usedBooks.contains(x))
                .filter(x -> currSpaceLeftOnShelf.get() >= x[0])
                .findFirst();

            if(nextBook.isPresent()) {
                usedBooks.add(nextBook.get());
                currSpaceLeftOnShelf.addAndGet(-nextBook.get()[0]);
                if(currShelfHeight < nextBook.get()[1]) currShelfHeight = nextBook.get()[1];
            } else {
                totalHeight += currShelfHeight;
                currShelfHeight = 0;
                currSpaceLeftOnShelf.set(shelfWidth);
            }
        }
        totalHeight += currShelfHeight;

        return totalHeight;
    }

    public static void testSolution(final int[][] books, final int shelfWidth, final int expected) {
        final int ans = minHeightShelves(books, shelfWidth);

        if(ans == expected) System.out.println("\033[1;32m"); //color output text green
        else System.out.println("\033[1;31m"); //color output text red

        System.out.println("Books: " + books);
        System.out.println("ShelfWidth: " + shelfWidth);
        System.out.println("Output: " + ans);
        System.out.println("Expected: " + expected + "\033[0m");
    }

    public static void main(final String[] args) {
        testSolution(new int[][]{{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}}, 4, 6);
        testSolution(new int[][]{{1,3},{2,4},{3,2}}, 6, 4);
    }
}
