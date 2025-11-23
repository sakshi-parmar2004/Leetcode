class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        vector<int>arr1,arr2;
        for(int i:nums)
        {
          sum+= i;
          if(i%3==0)continue;
          if(i%3==1)
          {
            arr1.push_back(i);
          }
          else
          {
            arr2.push_back(i);
          }
        }

        if(sum%3==0)return sum;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        if(sum%3==1)
        {
            int op1=0,op2=0;
            if(arr1.size()>0)
            {
            op1 = sum-arr1[0];
            }
            if(arr2.size()>1)
            {
            op2= sum-arr2[0]-arr2[1];
            }
           return max(op1,op2);
        }
    
        else
        {
             int op1=0,op2=0;
            if(arr1.size()>1)
            {
             op1 = sum-arr1[0]-arr1[1];
            }
            if(arr2.size()>0)
            {
                 op2= sum-arr2[0];
            }
           return max(op1,op2);


        }
        return 0;
    }
};