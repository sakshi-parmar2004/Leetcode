class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR=0;
        for(int i:nums)
        {
            XOR^=i;
        }
        int k=0;
        while(!(XOR&1))
        {
            XOR>>=1;
            k++;
        }
        int first=0,second=0;
        for(int i:nums)
       {
          if( (i>>k )&1)
          {
              first^=i;
          }
          else
          {
            second^=i;
          }
       }
       return {first,second};

    }
};