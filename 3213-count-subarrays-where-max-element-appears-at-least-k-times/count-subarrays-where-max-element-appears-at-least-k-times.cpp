class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int i=0,j=0 , n= nums.size(),maxi=-1;
        for(int i:nums)
       {
          maxi=max(maxi,i);
       }
       int count=0;
       while(j<n)
       {
          if(nums[j]==maxi)
          {
             count++;
          }
         
          while(count==k)
          {
            ans+=n-j;
            if(nums[i]==maxi)count--;
            i++;
          }
          j++;
         
       }
     return ans;
    }
};