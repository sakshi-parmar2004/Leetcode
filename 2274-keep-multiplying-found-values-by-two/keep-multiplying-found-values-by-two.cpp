class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(),nums.end());
        int og=original;
        while(st.find(og)!=st.end())
        {
            og*=2;
        }
        return og;
        
    }
};