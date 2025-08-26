class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n =nums.size();
         vector<int>ans(n,-1);
         long long sum=0,i=0,j=0,wind=2*k+1;
         while(j<n)
         {
            sum+=nums[j];

            if(j-i+1== wind)
            {
                int val = sum/(2*k+1);
                int ind= i+k;
                ans[ind]=val;
                sum-=nums[i];
                i++;
            }
            j++;
         }
         return ans;

        
    }
};