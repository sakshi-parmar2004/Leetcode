class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        int vowel =0, consonants=0;
        for(char i:s)
            {
                mp[i]++;
            }

        for(auto it:mp)
            {
                char ch = it.first;
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                {
                    vowel=max(vowel,it.second);
                }
                else
                {
                    consonants= max(consonants, it.second);
                }
            }

        return vowel + consonants;
        
    }
};