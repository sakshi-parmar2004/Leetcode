class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>arr;
        int new_n =-( n/2);
        for(int i= new_n ;i<=n/2;i++ )
        {
            if((n)%2==0)
            {
                if(i==0)
                {
                    continue;
                }
            }
            arr.push_back(i);
        }
        return arr;
        
    }
};