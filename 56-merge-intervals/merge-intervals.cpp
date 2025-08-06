class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
         vector<vector<int>>ans;
         if(arr.empty())return ans;
         ans.push_back(arr[0]);
         int n= arr.size();
         for(int i=1;i<n;i++)
         {
            int first =arr[i][0];
            
            int last = ans.back()[1];
            if(last>=first)
            {
             ans.back()[1]= max(arr[i][1], ans.back()[1]);

            }
            else
            {
             ans.push_back(arr[i]);
            }

         }
         return ans;

        
    }
};