class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        int n = asteroids.size();
        for(int i=0;i<n;i++)
        {
            if(asteroids[i] > 0)
            {
                v.push_back(asteroids[i]);
            }
            else
            {
                while(!v.empty() && v.back()>0 and abs(asteroids[i]) > v.back())
                {
                    v.pop_back();
                }
                
                if(!v.empty() && v.back() == abs(asteroids[i]))
                {
                    v.pop_back();
                }
                else if(v.empty() || v.back() < 0)
                {
                    v.push_back(asteroids[i]);
                }
            }
        }
        return v;
    }
};