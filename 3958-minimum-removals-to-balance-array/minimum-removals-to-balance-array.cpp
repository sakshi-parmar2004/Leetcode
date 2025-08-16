class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int i=0,j=0 ,mini=INT_MAX,n = nums.size();
        while(j<nums.size())
        {
            double value = (double) nums[j]/nums[i];

            if(value<=k)
            {
                mini=min(mini, n-(j-i+1));
            }
            else
           {
              i++;
           }
           j++;
        }
        return mini;
        
    }
};