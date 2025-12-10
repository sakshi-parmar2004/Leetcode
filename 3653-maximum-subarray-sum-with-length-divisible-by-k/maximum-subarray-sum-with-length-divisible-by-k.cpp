class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }

        long long maxi = LLONG_MIN;
        for(int i=0;i<k;i++)
        {
            long long sum=0;
            for(int j=i;j+k<=n;j+=k)
            {
                long long val = prefix[j+k]-prefix[j];

                sum=max(sum+val, val);
                maxi=max(maxi,sum);
            }
        }
         return maxi;
    }
};