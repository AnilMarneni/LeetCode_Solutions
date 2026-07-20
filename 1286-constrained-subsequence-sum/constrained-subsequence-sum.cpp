class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> res(nums);
        int maxR = res[0];

        for (int i = 0; i < n; i++) {
            while (!deq.empty() && deq.front() < i - k) {
                deq.pop_front();
            }

            if (!deq.empty()) {
                res[i] = max(res[i], nums[i] + res[deq.front()]);
            }

            while (!deq.empty() && res[deq.back()] <= res[i]) {
                deq.pop_back();
            }

            deq.push_back(i);
            maxR = max(maxR, res[i]);
        }

        return maxR;
    }
};
