class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n= nums.size(),count=0;
        vector<int>prefix(n,0);
       
        prefix[0]=nums[0];
        int total_sum=nums[0];
        for(int i=1;i<n;i++)
        {
           prefix[i]=prefix[i-1]+nums[i];
           total_sum+=nums[i];
        }
         if(total_sum==0)return n*2;
       
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==0 && prefix[i-1]==total_sum-prefix[i-1])
            {
                  count+=2;
            }
            else if(nums[i]==0 && (prefix[i-1]+1 == total_sum-prefix[i-1] || prefix[i-1]==total_sum-prefix[i-1]+1))
            {
                count+=1;
            }
        }
       
        if(nums[0]==0 && total_sum==1 )count+=1;
        if(nums[n-1]==0 && total_sum==1)count+=1;
        
        return count;


    }
};