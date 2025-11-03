class Solution {
public:
    void solve(int i,int j,int m , int n,vector<vector<string>>&arr ,set<pair<int,int>>&st )
    {
        for(int ind=i+1;ind<m;ind++)
        {
            if(st.find({ind,j})!=st.end())
            {
                break;
            }
            arr[ind][j]="-1";
        }
        for(int ind=j+1;ind<n;ind++)
        {
            if(st.find({i,ind})!=st.end())
            {
                break;
            }
            arr[i][ind]="-1";
        }
         for(int ind=i-1;ind>=0;ind--)
        {
            if(st.find({ind,j})!=st.end() )
            {
                break;
            }
            arr[ind][j]="-1";
        }
        for(int ind=j-1;ind>=0;ind--)
        {
            if(st.find({i,ind})!=st.end())
            {
                break;
            }
            arr[i][ind]="-1";
        }
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
            
            solve(id1,id2,m,n,arr,st);
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