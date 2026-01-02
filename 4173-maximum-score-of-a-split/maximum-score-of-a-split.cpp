class Solution {
public:
    long long maximumScore(vector<int>& nums) {
       int n= nums.size();
        vector<long long>prefix_sum(n);
        vector<int>suffix_Min(n);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        suffix_Min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix_Min[i]=min(suffix_Min[i+1],nums[i+1]);
        }
        

        long long score=LLONG_MIN;
        for(int i=0;i<n-1;i++)
        {
            score=max(score, prefix_sum[i]-suffix_Min[i]);
        }
        return score;
        
    }
};