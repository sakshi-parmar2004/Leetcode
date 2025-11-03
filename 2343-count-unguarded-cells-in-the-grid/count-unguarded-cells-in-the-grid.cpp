class Solution {
public:
    void solve(int i,int j,int m , int n,vector<vector<string>>&arr ,set<pair<int,int>>&st,string dir )
    {

if(i<0 || j<0 || i>=m || j>=n)
{
    return ;
}
   if(st.find({i,j})!=st.end())
   {
    return ;
   }
   arr[i][j]="-1";

        if(dir=="d")
        {
                solve(i+1,j,m,n,arr,st,"d");
        }
        else if(dir=="l")
        {
               solve(i-1,j,m,n,arr,st,"l");
        }
        else if(dir=="u")
        {
                solve(i,j-1,m,n,arr,st,"u");
        }
        else 
        {
                       solve(i,j+1,m,n,arr,st,"r");
        }      
        return ;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<string>>arr(m, vector<string>(n));
        set<pair<int,int>>st;
        for(int i=0;i<walls.size();i++)
        {
            int id1 = walls[i][0],id2= walls[i][1];
            arr[id1][id2]="W";
            st.insert({id1,id2});
        }
        for(int i=0;i<guards.size();i++)
        {
            int id1 = guards[i][0],id2= guards[i][1];
            arr[id1][id2]="G";
            st.insert({id1,id2});
        }
        for(int i=0;i<guards.size();i++)
        {
            int id1 = guards[i][0],id2= guards[i][1];
            solve(id1+1,id2,m,n,arr,st,"d");
            solve(id1-1,id2,m,n,arr,st,"l");
             solve(id1,id2-1,m,n,arr,st,"u");
            solve(id1,id2+1,m,n,arr,st,"r");

        }

        int count=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]=="G" || arr[i][j]=="W" || arr[i][j]=="-1"  )
                {
                    continue;
                }
                count++;
            }
        }
        return count;
        
    }
};