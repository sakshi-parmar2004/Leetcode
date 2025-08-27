class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int i=0,j=0 ,n=nums.size();
        deque<int>q;
        vector<int>ans;
        while(j<nums.size())
        {
           
            
            while(!q.empty() && nums[j]>q.back())
            {
                q.pop_back();
            }
            q.push_back(nums[j]);
            
            

            if(j-i+1==k)
            {
                ans.push_back(q.front());
                if(nums[i]==q.front())
                {
                    q.pop_front();
                      
                }
                
                i++;
               
            }
            j++;

        }
        
        return ans;
    }
};