class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n= nums.size(),count=0;
        
       
        int prefix=0;
        int total_sum=nums[0];
        for(int i=1;i<n;i++)
        {
           total_sum+=nums[i];
        }
         if(total_sum==0)return n*2;
       
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            if(nums[i]==0 && prefix==total_sum-prefix)
            {
                  count+=2;
            }
            else if(nums[i]==0 && (prefix+1 == total_sum-prefix|| prefix==total_sum-prefix+1))
            {
                count+=1;
            }
        }
       
        return count;


    }
};