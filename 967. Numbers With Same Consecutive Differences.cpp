class Solution {
public:
    void solve(int currNumber, int n, int k, vector<int> &ans)
    {
        if(n==1)
        {
            ans.push_back(currNumber);
            return;
        }
        for(int i=0;i<=9;i++)
        {
            int lastdigit = currNumber%10;
            if(abs(lastdigit - i)==k)
            {
                solve(currNumber*10 + i, n-1, k, ans);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            solve(i,n,k,ans);
        }
        return ans;
    }
};