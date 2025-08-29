class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_number_n=n/2;
        if(n%2!=0)
        {
            odd_number_n+=1;
            
        }
        long long even_number_n=n/2;

        long long odd_number_m=m/2;
        if(m%2!=0)
        {
            odd_number_m+=1;
            
        }
        long long even_number_m=m/2;

        long long answer = odd_number_n * even_number_m + even_number_n*odd_number_m;
        return answer;


        
    }
};