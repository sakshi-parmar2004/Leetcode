class Solution {
public:
    long long maxProduct(vector<int>& nums) {

      
        for(int i=0;i<nums.size();i++)
        {
           nums[i]= labs(nums[i]);

        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans = (1LL)*nums[n-2]*nums[n-1]*1e5;
        return ans;

        
    }
};