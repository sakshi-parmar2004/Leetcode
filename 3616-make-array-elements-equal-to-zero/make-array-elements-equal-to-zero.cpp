class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n= nums.size(),count=0;
        vector<int>prefix(n,0),suffix(n,0);
        if(n==1 && nums[0]==0)return 2;
        if(n==1 && nums[0]>1)return 0;
        prefix[0]=nums[0],suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
           prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
           suffix[i]=suffix[i+1]+nums[i];
        }

        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==0 && prefix[i-1]==suffix[i+1])
            {
                  count+=2;
            }
            else if(nums[i]==0 && (prefix[i-1]+1 == suffix[i+1] || prefix[i-1]==suffix[i+1]+1))
            {
                count+=1;
            }
        }

        if(nums[0]==0 && (prefix[n-1]==0) )count+=2;
        
        if(nums[0]==0 && (prefix[n-1]==1) )count+=1;

         if(nums[n-1]==0 && (prefix[n-1]==0) )count+=2;
         if(nums[n-1]==0 && (suffix[0]==1) )count+=1;
        
        return count;


    }
};