class Solution {
public:
    int canBeTypedWords(string text, string str) {
        vector<int>arr(26,0);
        for(char i:str)
        {
            arr[i-'a']++;
        }
         
        int count=0;
        bool flag=false;
        for(char ch:text)
        {
            if(ch == ' ')
        {
            if(!flag)count++;
            flag=false;
            continue;

        }
            if(arr[ch-'a']==1)
            {
                flag=true;
            }
            
        }
         if(!flag)count++;
         return count;
    }
};