class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int cnt=0;
        while(ans!=0)
        {
            int mod = ans%2;
            if(mod!=0){
                cnt++;
            }
            ans/=2;
        }
        return cnt;
    }
};