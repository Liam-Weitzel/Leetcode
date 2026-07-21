#include <algorithm>
#include <string>

class Solution { // Jul 21, 2026
private:
    struct Node {
        Node* next;
        int size;
        char val;
    };
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        //10001000 is auctually 110001001
        //after converting the middle 1 we can convert the group of 0s to all 1s
        //we can only do 1 trade (o(n^2) brute force solution?
        //we can create a linkedlist of the different sections (as we dont care about individual chars)
        //then always flip the sections that is surrounded by the greatest number of 0s. A contigious block of 0s is ALWAYS surrounded by 1s due to the augmentation rule.
        //O(n)
        //we can totally skip simulation by just checking for each section of 1: if it has 2 0 section neigbours, and if so, what are there sizes? The sum of their size + the original number of ones is a candidate for the solution

        Node* head = new Node();
        head->val = s[0];
        Node* iter = head;
        for(char i : s) {
            if(iter->val != i) {
                Node* next = new Node();
                iter->next = next;
                iter = iter->next;
            }
            iter->val = i;
            iter->size++;
        }

        int existingOnes = std::count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
        int res = existingOnes;
        int prevSize = 0;
        bool prevGroup = false;
        while(head != nullptr) {
            if(head->val == '0') {
                if(prevGroup) {
                    res = std::max(existingOnes + prevSize + head->size, res);
                    prevSize = head->size;
                } else {
                    prevGroup = true;
                    prevSize = head->size;
                }
            }
            head = head->next;
        }

        return res;
    }
};
