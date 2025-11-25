class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0,count=0;
        for(int i:nums)
        {
            if(i%6==0)
            {
            count++;
            sum+=i;
            }
        }
        if(count==0)return 0;
        return sum/count;
        
    }
};