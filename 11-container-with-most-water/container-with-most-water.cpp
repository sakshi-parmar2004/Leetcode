class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0,n= nums.size(),j=n-1,result=0;
        while(i<j)
        {
            result = max(result, (j-i)*min(nums[j],nums[i]));
            if(nums[i]<nums[j])
            {
                i++;
            }
            else
            {
                j--;
            }

        }
        return result;

        
    }
};