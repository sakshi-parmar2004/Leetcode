class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char>st={'a','e','i','o','u'};
        int vowels=0;
        for(char i:s)
        {
            if(st.find(i)!=st.end())
            {
                vowels++;
            }
        }
        if(vowels==0)return false;
        return true;
    
    }
};