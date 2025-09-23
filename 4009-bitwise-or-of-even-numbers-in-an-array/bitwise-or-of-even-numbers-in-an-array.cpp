class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans=0,i=0;
      
        while(i<nums.size())
        {
            if(nums[i]%2==0)
            {
                ans|=nums[i];
              
            }
            i++;
            
        }
        return ans;
    }
};