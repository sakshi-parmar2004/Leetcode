class Solution {
public:
    double profit(int x,int y)
   {
       double value1 = (double)x/y;
        double value2= (double)(x+1)/(y+1);
         double value = value2-value1;
         return value;
   }
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        int n= classes.size();
        priority_queue<pair<double,array<int,2>>>pq;
        double total=0;
        for(int i=0;i<n;i++)
        {
            int x = classes[i][0],y= classes[i][1];
            total+= (double)x/y;
            pq.push({profit(x,y),{x,y}});
        }
        while(k--)
        {
            auto [cur_profit ,arr] = pq.top();
            pq.pop();
            total+= cur_profit;
            pq.push({profit(arr[0]+1,arr[1]+1),{ arr[0]+1,arr[1]+1}});

        }
        return (double)total/n;


        
    }
};