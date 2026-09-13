#include <vector>

class Solution { // Sep 13, 2026
public:
  int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {

    //Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
    // 1 1 0     0 0 0
    // 0 1 0     0 1 1
    // 0 1 0     0 0 1

    std::vector<std::vector<int>> img1Padded(img1.size()*3, std::vector<int>(img1[0].size()*3, 0));
    for(int row = 0; row < img1.size(); ++row) {
      int newRow = row + img1.size();
      for(int col = 0; col < img1[row].size(); ++col) {
        int newCol = col + img1[row].size();
        img1Padded[newRow][newCol] = img1[row][col];
      }
    }

    // 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0
    // 0 0 0 1 1 0 0 0 0
    // 0 0 0 0 1 0 0 0 0
    // 0 0 0 0 1 0 0 0 0
    // 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0

    // then take image 2 and translate each 1 to another 1 in image 1. We can safely skip 0's -> easier version first where we simply check all positions
    // see which one has the greatest overlap using bitwise and -> or not :)

    int res = 0;
    for(int row = 0; row < img1Padded.size(); row++) {
      for(int col = 0; col < img1Padded[row].size(); col++) {
        //we assume that this is the top left of img 2 and count overlapping ones...
        int count = 0;
        int img2RealRow = 0;
        for(int img2row = row; img2row < std::min(img1Padded.size(), img2.size()+row); ++img2row) {
          int img2RealCol = 0;
          for(int img2col = col; img2col < std::min(img1Padded[row].size(), img2[0].size()+col); ++img2col) {
            if(img1Padded[img2row][img2col] == img2[img2RealRow][img2RealCol] && img1Padded[img2row][img2col] == 1) count++;
            img2RealCol++;
          }
          img2RealRow++;
          res = std::max(count, res);
        }
      }
    }
    
    // I am aware this is the brute force solution and there is probably a more efficient way to do this.
    // But it isn't TLE :)

    return res;
  }
};
