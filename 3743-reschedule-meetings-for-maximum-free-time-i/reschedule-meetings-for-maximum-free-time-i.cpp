class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int start =0;
        vector<int>free;
        for(int i=0;i<startTime.size();i++)
        {
            int freeTime = startTime[i]-start;
            start =endTime[i];
            free.push_back(freeTime);

        }
        if(start!=eventTime)
        {
            int freeTime = eventTime-start;
            free.push_back(freeTime);
        }

        int i=0,j=0,n=free.size(),maxi=-1,sum=0;
        while(j<n)
        {
            sum+=free[j];
            maxi=max(maxi,sum);
            if(j-i+1==k+1)
            {
                sum-=free[i];
                i++;
            }
            j++;

        }
        return maxi;
        
    }
};