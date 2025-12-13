class Solution {
public:
    long long maxPoints(vector<int>& nums1, vector<int>& nums2, int k) {
        
        long long sum=0;
        for(int i:nums1)
        {
            sum+=i;
        }
        vector<int>arr;
        for(int i=0;i<nums2.size();i++)
        {
            int ele=(nums2[i]-nums1[i]);
            arr.push_back(ele);
        }
sort(arr.begin(), arr.end(), greater<int>());

        int len= nums1.size()-k;
        if(len==0)return sum;
        long long maxi=0,sum2=0;
        for(int i=0;i<len;i++)
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