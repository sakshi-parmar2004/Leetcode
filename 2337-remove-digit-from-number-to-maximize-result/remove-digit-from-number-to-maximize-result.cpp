class Solution {
public:
    string removeDigit(string number, char digit) {
       string ans="",maxi="";
        for(int i=0;i<number.size();i++)
        {
            string str =number;
            if(number[i]==digit)
            {
                str.erase(i,1);
              
               if(str>maxi)
               {
                maxi= str;

               }



            }
        }
    return maxi;  
    }
};