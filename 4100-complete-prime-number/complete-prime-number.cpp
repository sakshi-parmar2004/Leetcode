class Solution {
public:
    bool isPrime(int n)
    {
        if(n==1)return false;
        if(n==2 || n==3)return true;
        int range = sqrt(n);
        for(int i=2;i<range+1;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
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