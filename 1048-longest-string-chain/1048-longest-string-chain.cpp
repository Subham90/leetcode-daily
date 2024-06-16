class Solution {
public:
    static bool compare(string &s1,string &s2)
    {
        return s1.size() < s2.size();
    }
    bool checkPossible(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1)
        {
            return false;
        }
        
        int i=0,j=0;
        while(i<s1.size() and j<s2.size())
        {
            if(s1[i] == s2[j])
            {
                i++;j++;
            }
            else 
            {
                i++;
            }
        }
        
        if(j==s2.size())
            return true;
        else
            return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(checkPossible(words[i],words[prev]) && 1+dp[prev] > dp[i])
                {
                    dp[i] = 1+dp[prev];
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};