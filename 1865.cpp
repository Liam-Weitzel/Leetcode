#include <unordered_map>
#include <vector>

class FindSumPairs { // Jul 06, 2025
private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> nums2freq;
    int n1;
    int n2;

public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) :
        nums1(nums1), nums2(nums2), n1(nums1.size()), n2(nums2.size())
    {
        for(int i : nums2) nums2freq[i]++;
    }
    
    void add(int index, int val) {
        nums2freq[nums2[index]]--;
        nums2[index] += val;
        nums2freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        for(int i = 0; i < n1; i++) count += nums2freq[tot - nums1[i]];
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
