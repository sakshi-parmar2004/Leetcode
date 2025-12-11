class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        sort(buildings.begin(),buildings.end());
        unordered_map<int,vector<vector<int>>>x_dir;
        unordered_map<int,vector<vector<int>>>y_dir;
        for(auto i:buildings)
        {
            int x= i[0],y=i[1];
            x_dir[x].push_back({x,y});
            y_dir[y].push_back({x,y});
        }
        int count=0;
        for(int i=0;i<buildings.size();i++)
        {
            int x= buildings[i][0],y= buildings[i][1];
            if( x_dir[x].front()!=buildings[i] && x_dir[x].back()!=buildings[i] 
            &&  y_dir[y].front()!=buildings[i] &&  y_dir[y].back()!=buildings[i])
            {
                count++;
            }

        }
    return count;
    }
};