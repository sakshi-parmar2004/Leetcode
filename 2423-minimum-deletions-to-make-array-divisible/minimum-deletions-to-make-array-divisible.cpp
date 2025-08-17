class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int size = numsDivide.size();
        for(int i:numsDivide)
        {
            mini=min(mini,i);
        }
        for(int i=0;i<nums.size();i++)
        {
            bool flag= true;
            int ele =  nums[i];
            if(ele>mini)
            {
                break;
            }
            for(int j=0;j<=size/2;j++)
            {
                if(numsDivide[j]%ele!=0 || numsDivide[size-j-1]%ele!=0)
                {
                   flag=false;
                   break;
                }
            }
            if(flag)
            {return i;}
        }
        return -1;

        
    }
};