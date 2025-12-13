class Solution {
public:
    long long maxPoints(vector<int>& nums1, vector<int>& nums2, int k) {
        
        long long sum=0;
        for(int i:nums2)
        {
            sum+=i;
        }
        vector<int>arr;
        for(int i=0;i<nums1.size();i++)
        {
            int ele=(nums1[i]-nums2[i]);
            arr.push_back(ele);
        }
       sort(arr.begin(), arr.end(), greater<int>());

     
        int n=nums2.size();
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        
        long long maxi=0,sum2=0;
        for(int i=k;i<n;i++)
        {
            sum2+=arr[i];
            if(sum2<0)
            {
                sum2=0;
            }
            maxi=max(maxi,sum2);
        }
        
        return sum+maxi;
    }
};