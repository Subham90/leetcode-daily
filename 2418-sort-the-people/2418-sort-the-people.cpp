class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> v;
        int n = names.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,string>>());
        vector<string>ans;
        for(auto it: v)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};