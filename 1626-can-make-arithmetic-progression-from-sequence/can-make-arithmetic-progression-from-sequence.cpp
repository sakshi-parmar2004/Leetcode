class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        unordered_set<int>st(arr.begin(),arr.end());
       
        int maxi=*max_element(arr.begin(),arr.end());
        int mini=*min_element(arr.begin(),arr.end());
        int n= arr.size();
        if((maxi-mini)%(n-1)!=0)
        {
            return false ;
        }
        int d = (maxi-mini)/(n-1);
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=maxi && st.find(arr[i]+d)==st.end())
            {
                return false;
            }
        }
        return true;
        
    }
};