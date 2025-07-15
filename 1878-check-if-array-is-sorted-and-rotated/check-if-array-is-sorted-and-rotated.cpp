class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        reverse(nums.begin(), nums.begin()+count+1);
        reverse(nums.begin()+count+1, nums.end());
        for(int i=nums.size()-1;i>0;i--)
        {
           if(nums[i]>nums[i-1])
           {
            return false;
           }
           
        }
        return true;


        
    }
};