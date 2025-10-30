class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
       
        long long ops = abs(target[0]-nums[0]);
        int prev= target[0]-nums[0];
        for(int i=1;i<n;i++)
        {
            int cur = target[i]-nums[i];
            if((prev>0 && cur<0) || (prev<0 && cur>0))
            {
                ops+=(long long) abs(cur);
            }
            else if(abs(cur)>abs(prev))
            {
                ops+=(long long) abs(cur-prev);

            }
            prev=cur;

        }
        return ops;

       
    }
};
