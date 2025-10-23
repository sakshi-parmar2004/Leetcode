class Solution {
public:
    bool hasSameDigits(string s) {
        
        int n= s.length();
        while( s.length()!=2)
        {
          string str="";
          for(int i=1;i<s.length();i++)
          {
              int sum = s[i]-'0' + s[i-1]-'0';
              char digit = (sum%10)+'0';
              str+=digit;

          }
          s= str;

        }
        return s[0]==s[1];
    }
};