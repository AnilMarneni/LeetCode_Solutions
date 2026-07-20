class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int definite = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                definite += customers[i];
            }
        }

        int extra = 0;
        int maxExtra = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 1){
                extra += customers[i];
            }
            if(i >= minutes && grumpy[i - minutes] == 1){
                extra -= customers[i - minutes];
            }
            maxExtra = max(extra, maxExtra);
        }

        return definite + maxExtra;
    }
};