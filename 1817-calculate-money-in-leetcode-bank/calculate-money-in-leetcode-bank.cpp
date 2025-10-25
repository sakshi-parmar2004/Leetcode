class Solution {
public:
    int totalMoney(int n) {
       
       int week_days= n/7;
       int remaining_days= n%7;
      int total = week_days*28;
       if(week_days>1)
       {
          total+= ((week_days*(week_days-1))/2)*7;
       }

       int monday= week_days+1;
       int end_day = monday+ remaining_days-1;
       int sum =  end_day*(end_day+1)/2- (monday-1)*(monday)/2;
       return total+sum;

        
    }
};