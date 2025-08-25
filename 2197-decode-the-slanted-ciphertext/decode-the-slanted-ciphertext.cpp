class Solution {
public:
    string decodeCiphertext(string str, int rows) {
        int length = str.length();
        int col = length/rows , ind=0;
        vector<vector<char>>temp(rows,vector<char>(col));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                temp[i][j]= str[ind];
                ind++;

            }
        }
        map<int,string>mp;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                mp[i-j]+=temp[i][j];

            }
        }
        string ans="";
        for(auto &i:mp)
        {
            if(i.first>0)
            {
                break;
            }
            reverse(i.second.begin(),i.second.end());
            
            ans+=i.second;
            
        }

        reverse(ans.begin(),ans.end());
        int len=ans.length();
       for(int i=len-1;i>=0;i-- )
       {
        if(ans[i]!=' ')
        {
            break;
        }
        len--;
       }
        return ans.substr(0,0+len);

    }
};