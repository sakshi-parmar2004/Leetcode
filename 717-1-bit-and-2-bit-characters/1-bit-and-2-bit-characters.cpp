class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0,n=bits.size();
        while(i<bits.size())
        {
            int bit1 = bits[i] +'0';
            if( i==n-1 && bit1=='0')
            {
                return true;
            }
            if(bit1=='0')
            {
                i+=1;
            }
            else
            {
                i+=2;
            }
            

        }
        return false;

    }
};