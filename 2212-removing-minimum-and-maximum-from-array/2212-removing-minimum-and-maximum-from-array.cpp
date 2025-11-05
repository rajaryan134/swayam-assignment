class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0, maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        int deleteFromFront = max(maxIndex, minIndex) + 1;
        int deleteFromBack = n - min(maxIndex, minIndex);
        int deleteFromBothSide = (min(maxIndex, minIndex) + 1) + (n - max(maxIndex, minIndex));
        return min({deleteFromBothSide, deleteFromFront, deleteFromBack});
    }
};