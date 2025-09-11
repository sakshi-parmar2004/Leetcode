class Solution {
public:
    string sortVowels(string s) {
        unordered_set<int>st={'a','e','i','o','u','A','E','I','O','U'};
        string ans =s;
        string str="";
        for(char i:s)
        {
            if(st.find(i)!=st.end())
            {
                str+=i;
            }
        }
        
        sort(str.begin(),str.end());
        int k=0;
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s[i])!=st.end())
            {
                ans[i]=str[k++];
            }
        }
        return ans;
        
    }
};