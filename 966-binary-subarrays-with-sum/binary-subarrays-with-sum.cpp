class Solution {
public:
    int countAtMost(vector<int>& nums, int x) {
        if (x < 0) return 0;
        int left = 0, currSum = 0, count = 0;
        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            while (currSum > x) {
                currSum -= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};
