class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> freq;
        int left = 0;
        int maxNum = 0;
        for(int right = 0; right < n; right++){
            freq[fruits[right]]++;
            while(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            maxNum = max(maxNum, right - left + 1);
        }
        return maxNum;
    }
};