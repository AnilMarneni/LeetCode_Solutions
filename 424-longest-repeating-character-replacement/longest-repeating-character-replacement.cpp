class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxFreq = 0;
        int maxLen = 0;
        int left = 0;
        int freq[26] = {0};
        for(int right = 0; right < n; right++){
            int ch = s[right] - 'A';
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);
            int winLen = right - left + 1;
            while(winLen - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
                winLen = right - left + 1;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};