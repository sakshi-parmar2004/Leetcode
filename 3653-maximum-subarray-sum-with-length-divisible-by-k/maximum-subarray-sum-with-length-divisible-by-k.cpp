class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long >prefix_arr(n+1,0);
        long long res= LONG_MIN,sum=0;
        prefix_arr[0]=0;
        for(int i=0;i<n;i++)
        {
           prefix_arr[i+1]=prefix_arr[i]+nums[i];
        }

        for(int i=0;i<k;i++)
        {
            sum=0;
            for(int j=i;j+k<=n;j+=k)
            {
                long long data = prefix_arr[j+k]-prefix_arr[j];
                sum= max(sum+data,data);
                res= max(res, sum);
            }
        }
        return res;
        
    }
}; 