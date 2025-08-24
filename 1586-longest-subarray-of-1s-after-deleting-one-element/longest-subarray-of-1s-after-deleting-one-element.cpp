class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix;
        vector<int>suffix(n,0);
        int count=0,count1=0;
        for(int i:nums)
        {
            if(i==0)
            {
                 prefix.push_back(count);
                count=0;
                continue;

            }
            count1++;
            count++;
            prefix.push_back(count);

        }
        int ans=0,sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0)
            {

               ans = max(ans, prefix[i] +sum);
               sum=0;
               continue;
            }
            sum++;
            
        }
        
        if(count1==n)return n-1;
        return ans;
        
    }
};