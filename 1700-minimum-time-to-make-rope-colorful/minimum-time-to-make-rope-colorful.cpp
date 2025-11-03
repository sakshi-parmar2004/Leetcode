class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0,j=1,ans=0;
        while(j<colors.length() )
        {

            if(colors[j-1]==colors[j])
            {
                ans+=min(neededTime[i],neededTime[j]);
                if(neededTime[j]>=neededTime[i])
                {
                       i=j;
                }
            }
            else
            {
                i=j;
            }
            j++;
        }
        return ans;
    }
};