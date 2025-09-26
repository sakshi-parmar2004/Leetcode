class Solution {
public:
    int bin_search(int l ,int r ,int target, vector<int>& nums )
    {
        int result= r+1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]>=target)
            {
                result = mid;
                r=mid-1;
            }
            else
            {

                l=mid+1;
            }
        }
        return result;
    


    }
    int triangleNumber(vector<int>& nums) {
        int n= nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)continue;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]==0)continue;
                int target = nums[i]+nums[j];
                int index = bin_search(j+1,n-1,target,nums);

                ans += (index-(j+1));
            }
        }
        return ans;
    }
};