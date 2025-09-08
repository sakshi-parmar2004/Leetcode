class Solution {
public:
    bool solve(int num)
    {
        while(num>0)
        {
            int rem= num%10;
            if(rem==0)return 0;
            num=num/10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1;i<n;i++)
        {
            int a =i,b=n-a;
            if(solve(a) && solve(b))
            {
                return {a,b};
            }
        }
        return {};
    }
};