class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n= s.length();
        vector<int>arr(n);
        for(int i=0;i<shifts.size();i++)
        {
            int l = shifts[i][0];
            int r= shifts[i][1];
            int dir = shifts[i][2];
            if(dir==0)
            {
                 arr[l]-=1;
            }
            else
            {
                arr[l]+=1;
            }

            if(r+1<n)
            {
                //-ve and the -ve from 0
                if(dir==0)
            {
                 arr[r+1]+=1;
            }
            else
            {
                arr[r+1]-=1;
            }

            }
            
        }
        for(int i=1;i<n;i++)
        {
            arr[i]+=arr[i-1];
          
        }
        for(int i=0;i<n;i++)
        {
            s[i] = 'a' + ((s[i] - 'a' + arr[i]) % 26 + 26) % 26;

        }
        return s;
       
        
    }
};