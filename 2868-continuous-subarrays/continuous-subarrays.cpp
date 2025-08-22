class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> order;
        long long i=0,j=0 , n=nums.size() , ans=0;
        while(j<n)
        {
            order[nums[j]]++;
            int maxi = order.rbegin()->first;
            int mini = order.begin()->first;
            while(abs(maxi-mini)>2)
            {
                order[nums[i]]--;
                if(order[nums[i]]==0)
                {
                    order.erase(nums[i]);
                }
                maxi = order.rbegin()->first;
                mini = order.begin()->first;
                i++;
                
            }
            ans+=(j-i+1);
            j++;

        }
        return ans;
        
    }
};