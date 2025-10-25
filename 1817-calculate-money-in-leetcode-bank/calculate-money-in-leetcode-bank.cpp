class Solution {
public:
    int totalMoney(int n) {
       
       int x =n/7;
       n=n%7;
       long long monday=1 , days=1 ;
       long long ans=0;
       while(days<=x)
       {
          long long end_day= monday+6;
          long long sum = end_day*(end_day+1)/2- (monday-1)*(monday)/2;
          ans+= sum;
        monday++;
        days++;
       }
       int end_day = monday+ n-1;
       int sum =  end_day*(end_day+1)/2- (monday-1)*(monday+1-1)/2;
       return ans+sum;

        
        
    }
};