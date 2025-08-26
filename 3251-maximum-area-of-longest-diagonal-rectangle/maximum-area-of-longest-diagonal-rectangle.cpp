class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int area=-1;
        int maxi=-1;
        for(int i=0;i<arr.size();i++)
        {
            int len = arr[i][0], wid=arr[i][1] ;
            int val = len*len + wid*wid;
            
            if(val>maxi)
            {
                
                maxi=max(maxi,val);
                area= len*wid;
            }
            else if(val==maxi)
            {
                area= max(area, len*wid);
            }

        }
        return area;
        
    }
};