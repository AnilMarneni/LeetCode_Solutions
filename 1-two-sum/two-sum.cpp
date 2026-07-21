class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int ele = nums[i];
            int comp = target - ele;
            if(mp.find(comp) != mp.end()){
                return {i, mp[comp]};
            }
            mp[ele] = i;
        }
        return {-1, -1};
    }
};