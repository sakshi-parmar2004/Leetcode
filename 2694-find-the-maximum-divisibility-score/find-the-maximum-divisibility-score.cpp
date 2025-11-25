class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans=0,result=INT_MAX;
       
        
            for(int j=0;j<divisors.size();j++)
            {
                int count=0;
                 for(int i=0;i<nums.size();i++)
        {
                if(nums[i]%divisors[j]==0)
                {
                    count++;
                }

            }
            if(count==ans)
            {
              
                result=min(result,divisors[j]);
            }
            if(count>ans)
            {
                  ans=count;
                  result=divisors[j];
            }
            
        }
        return result;
        
    }
};