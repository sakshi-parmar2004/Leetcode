class Solution {
public:
    int bin_len(int n)
    {
        int len=0;
        while(n>0)
        {
            n>>=1;
            len++;
        }
        return len;
    }
    bool solve(int i)
    {
        int l=0,r= bin_len(i)-1;
        while(l<r)
        {
            if(((i>>l)&1) != ((i>>r)&1))
            {
                return false;
            }
            l++;r--;
        }
        return true;

    }
    vector<int> minOperations(vector<int>& nums) {
        
        vector<bool>pre(5050,false);
        for(int i=0;i<5050;i++)
        {
          
          pre[i]=solve(i);

        }
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<nums.size();i++)
        {
            int a = nums[i],b= nums[i],count1=0,count2=0;
            while(a>=0 && !pre[a])
            {
                a--;
                count1++;
            }
            while( b<5050 && !pre[b])
            {
                b++;
                count2++;
            }

            ans[i]=min(count1,count2);
                    }
return ans;

    }
};