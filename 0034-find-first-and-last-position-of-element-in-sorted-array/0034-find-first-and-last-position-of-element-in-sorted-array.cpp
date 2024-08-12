class Solution {
    private:
    int first(vector<int>&nums,int tar)
    {
        int index = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == tar)
            {
                index = mid;
                high = mid - 1;
            }
            else if(nums[mid] < tar)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return index;
    }
    
    int last(vector<int>&nums,int tar)
    {
        int index = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == tar)
            {
                index = mid;
                low = mid+1;
            }
            else if(nums[mid] < tar)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f1 = first(nums,target);
        int f2 = last(nums,target);
        return {f1,f2};
    }
};