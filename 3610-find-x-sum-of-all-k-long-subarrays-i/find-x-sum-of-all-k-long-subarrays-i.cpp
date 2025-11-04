class Solution {
public:
   int solve(int start,int end,int x,vector<int>& nums)
   {
    unordered_map<int,int>mp;
    priority_queue<pair<int,int>>pq;
     for(int i=start;i<=end;i++)
     {
        mp[nums[i]]++;
     }
     for(auto i:mp)
     {
        pq.push({i.second,i.first});
     }

     int ans=0,count=0;
     while(!pq.empty() && count<x)
     {
        int a=pq.top().first;
        int b= pq.top().second;
        ans+= a*b;
        pq.pop();
        count++;
     }
     return ans;

   }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n= nums.size();
    int length= n-k+1;
    vector<int>ans(length);
    
    
    for(int i=0;i<length;i++)
    {
        ans[i]= solve(i,i+k-1,x,nums);
    }
    return ans;

    }
};