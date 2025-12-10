class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>one,two;
        int sum=0;
        for(int i:nums)
        {
            if(i%3==1)
            {
               one.push_back(i);
            }
            else if(i%3==2)
            {
                two.push_back(i);
            }
            sum+=i;
        }
        int rem =sum%3;
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        int ans=0;
        if(rem==0)return sum ;
        if(rem==1 )
        {
           int sm1=sum,sm2=sum;
           if(!one.empty())
           {
             sm1-=one[0];
             ans = max(ans,sm1);
           }
            
            if(two.size()>=2)
            {
                sm2-= two[0];
                sm2-=two[1];
                ans=max(ans,sm2);
            }

            return ans;

        }
        else if(rem==2)
        {
            int sm1=sum,sm2=sum;
            if(one.size()>=2)
            {
                sm1-=one[0];
                sm1-=one[1];
                ans=max(sm1,ans);
            }
            if(!two.empty())
            {
                ans= max(ans, sm2-two[0]);
            }
            return ans;
        }
        return 0;
        
    }
};