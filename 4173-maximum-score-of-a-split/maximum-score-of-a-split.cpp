class Solution {
public:
    long long maximumScore(vector<int>& nums) {
       int n= nums.size();
        
        vector<int>suffix_Min(n);
        suffix_Min[n-1]=nums[n-1];
        long long sum=0;
        for(int i=n-2;i>=0;i--)
        {
            suffix_Min[i]=min(suffix_Min[i+1],nums[i+1]);
        
        }
        
        long long score=LLONG_MIN;
        for(int i=0;i<n-1;i++)
        {
             sum+=nums[i];
            score=max(score, sum-suffix_Min[i]);
           
        }
        return score;
        
    }
};