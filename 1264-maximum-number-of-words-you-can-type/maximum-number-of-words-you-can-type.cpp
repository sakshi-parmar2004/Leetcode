class Solution {
public:
    int canBeTypedWords(string text, string str) {
        bool flag=false;
        int count=0;
        for(char i:text)
       {
            if(i==' ')
             {
                if(!flag)
                {
                    count++;
                }
                flag=false;

             }
       if (str.find(i) != std::string::npos)
{
    flag = true;
}


      
       }
       if(!flag)
{
    count++;
}
        return count;
    }
};