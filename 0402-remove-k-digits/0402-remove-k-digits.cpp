class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(auto it: num)
        {
            while(!st.empty() and k>0 and st.top() > (it-'0'))
            {
                st.pop();
                k--;
            }
            if(!st.empty() || (it-'0')!=0)
            {
                st.push(it-'0');
            }
        }
        
        while(k>0 and !st.empty())
        {
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty())
        return "0";
        else
        return ans;
    }
};