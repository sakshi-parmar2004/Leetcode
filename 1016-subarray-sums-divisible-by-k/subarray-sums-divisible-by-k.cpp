class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        //the solution is based on the understading that the diff of two number if divided by k is 
        //a then the differnce between the twoo num will be divisible by k

        unordered_map<int,int>mp;
        int count=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum%k==0)
            {
                count++;
            }
            int rem= sum%k;
            if(rem<0)
            {
                rem+=k;
            }
            if(mp.find(rem)!=mp.end())
            {
                count+=mp[rem];
            }
            mp[rem]++;

        }
        return count;
        
    }
};