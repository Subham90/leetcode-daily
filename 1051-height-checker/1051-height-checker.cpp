class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int>newheights = heights;
        sort(newheights.begin(),newheights.end());
        int n = heights.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(heights[i]!=newheights[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};