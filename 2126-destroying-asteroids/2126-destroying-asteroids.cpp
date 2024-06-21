class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        bool f=0;
        long long int ans = mass;
        for(auto it: asteroids)
        {
            if(it<=ans)
            {
                ans+=it;
            }
            else
            {
                f=1;
                break;
            }
        }
        if(f)
            return 0;
        else
            return 1;
    }
};