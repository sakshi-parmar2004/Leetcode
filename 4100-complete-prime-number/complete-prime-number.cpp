class Solution {
public:
    bool isPrime(int n)
    {
        vector<bool>sieve(n+1,true);
        sieve[0]=false;
        sieve[1]=false;
        for(int i=2;i*i<=n;i++)
        {
               for(int k=i;k<=n;k+=i)
               {
                sieve[k]=false;
               }
        }
        return sieve[n];
    }
    bool completePrime(int num) {
        
        if(num<10)return isPrime(num);
        int new_num=0;
        int place=1;
        int rem=0;
        int num2=0;
        while(num>0)
        {
            rem = num%10;
            num2=num2*10+rem;
            new_num= rem*place+new_num;
            cout<<"new_num ="<<new_num<<endl;
            if(!isPrime(new_num))
            {
                return false;
            }
            place*=10;
            num/=10;
        }
        place=1;
        cout<<"num2 ="<<num2<<endl;
        new_num=0;
        while(num2>0)
        {
            rem = num2%10;
            new_num= new_num*10+rem;
            cout<<"new_num2 ="<<new_num<<endl;
            if(!isPrime(new_num))
            {
                return false;
            }
           
            num2/=10;
        }
               return true;
    }
};