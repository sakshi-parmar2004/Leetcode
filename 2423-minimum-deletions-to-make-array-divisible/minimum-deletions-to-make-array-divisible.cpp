class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int mini= numsDivide[0];
        int size = numsDivide.size();
        for(int i=1;i<size;i++)
        {
            mini=gcd(mini,numsDivide[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
           if(mini%nums[i]==0)
           {
            return i;
           }
        }
        return -1;

        
    }
};