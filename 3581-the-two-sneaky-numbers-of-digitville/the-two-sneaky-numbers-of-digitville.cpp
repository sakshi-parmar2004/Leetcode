class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
         vector<int>ans;
         unordered_set<int>st;
        for(int i:nums)
        {
            if(st.find(i)!=st.end())
            {
                ans.push_back(i);
            }
            st.insert(i);
        }
        return ans;
        
    }
};