class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(int i=0;i<bills.size();i++)
        {
            int rem = bills[i] - 5;
            if(rem == 15)
            {
                if(ten >= 1 and five >= 1)
                {
                    ten--;
                    five--;
                }
                else if(five >= 3)
                {
                    five-=3;
                }
                else
                {
                    return false;
                }
            }
            else if(rem == 5)
            {
                ten++;
                if(five >= 1)
                {
                    five--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                five++;
            }
        }
        return true;
    }
};