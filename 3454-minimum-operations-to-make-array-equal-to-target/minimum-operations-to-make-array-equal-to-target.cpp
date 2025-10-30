class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<long long> diff(n ,0);
      
        for (int i = 0; i < n; i++) {
            diff[i] =  target[i]-nums[i];
           
        }
        long long ops = abs(diff[0]);
        for(int i=1;i<n;i++)
        {
            if((diff[i-1]>0 && diff[i]<0) || (diff[i-1]<0 && diff[i]>0))
            {
                ops+=(long long) abs(diff[i]);
            }
            else if(abs(diff[i])>abs(diff[i-1]))
            {
                ops+=(long long) abs(diff[i]-diff[i-1]);

            }

        }
        return ops;

       
    }
};
