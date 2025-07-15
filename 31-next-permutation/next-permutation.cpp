class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //find the break point
        int n=nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index=i;
                break;

            }

        }
        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
        for(int i=n-1;i>index;i--)
       {
           if(nums[index]<nums[i])
           {
               swap(nums[i],nums[index]);
               break;
           }
       }
       sort(nums.begin()+index+1,nums.end());
        }
        
    }
};