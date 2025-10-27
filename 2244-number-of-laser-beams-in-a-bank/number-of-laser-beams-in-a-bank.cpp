class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0 ,ans=0;
        for(int i=0;i<bank.size();i++)
        {
            int count=0;
             for(int j=0;j<bank[i].length();j++)
             {
                if(bank[i][j]=='1')count++;

             }
            
             ans += prev*count;
              if(count>0){
                prev=count;
              }
             

        }
        return ans;
    }
};