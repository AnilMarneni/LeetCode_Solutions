class Solution {
public:
    void solve(int n, int& k, int& count, string& curr, string& res){
        if(curr.size() == n){
            count++;
            if(count == k){
                res = curr;
            }
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch){
                continue;
            }

            //Do
            curr.push_back(ch);
            //Explore
            solve(n, k, count, curr, res);
            //Undo
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string res = "";
        int count = 0;
        solve(n, k, count, curr, res);

        return res;
    }
};