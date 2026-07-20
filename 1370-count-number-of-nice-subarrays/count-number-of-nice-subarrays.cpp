class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n = nums.size();
        int odds = 0;
        int count = 0;
        int left = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] % 2 != 0){
                odds++;
            }
            while(odds > k){
                if(nums[left] % 2 != 0){
                    odds--;
                }
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};