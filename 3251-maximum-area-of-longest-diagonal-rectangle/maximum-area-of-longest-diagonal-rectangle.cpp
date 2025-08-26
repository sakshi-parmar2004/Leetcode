class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int area=-1;
        double maxi=-1;
        for(int i=0;i<arr.size();i++)
        {
            int len = arr[i][0], wid=arr[i][1] ;
            int val = len*len + wid*wid;
            double diag = sqrt(val);
            if(diag>maxi)
            {
                
                maxi=max(maxi,diag);
                area= len*wid;
            }
            else if(diag==maxi)
            {
                area= max(area, len*wid);
            }

        }
        return area;
        
    }
};