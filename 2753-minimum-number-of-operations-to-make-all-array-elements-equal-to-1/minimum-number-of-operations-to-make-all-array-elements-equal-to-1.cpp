class Solution {
public:
    int minOperations(vector<int>& nums) {
        int mini=INT_MAX,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)count++;
            int data= nums[i];
            for(int j=i;j<nums.size();j++)
            {
                
                data= gcd(data,nums[j]);
                if(data==1)
                {
                    mini=min(mini,j-i+1);
                }
                
            }
        }
        if(mini==INT_MAX)return -1;

       if(count>0)return nums.size()-count;

       
       int ops =nums.size()-1;
       ops+= mini-1;
        return ops;

        
    }
};