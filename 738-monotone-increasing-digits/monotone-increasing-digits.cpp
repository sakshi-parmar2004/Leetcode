class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10)return n;
        string str = to_string(n);
        int index=str.length();

        for(int i=index-1;i>0;i--)
        {
            if(str[i]<str[i-1])
            {
                index=i;
                str[i-1]--; 
            }
        }

        for(int i=index;i<str.length();i++)
        {
            str[i]='9';
        }
        int N = stoi(str);
        return N;

        
    }
};