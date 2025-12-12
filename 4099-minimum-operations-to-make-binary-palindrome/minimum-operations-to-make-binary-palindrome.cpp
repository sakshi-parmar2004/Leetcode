class Solution {
public:
    bool pallindromic(string s)
    {
        int len= s.length()/2;
        int n= s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]!=s[n-1-i])
            {
                return false;
            }

        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> arr ;
        for(int i=1;i<=5000;i++)
        {
            string bin = std::bitset<32>(i).to_string();
             bin.erase(0, bin.find('1'));  // remove leading zeros
             if(pallindromic(bin))
             {
                arr.push_back(i);
             }

        }
    

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            auto it = lower_bound(arr.begin(), arr.end(), x);

            int best = INT_MAX;

            // candidate 1: smallest >= x
            if (it != arr.end())
                best = min(best, abs(x - *it));

            // candidate 2: largest < x
            if (it != arr.begin()) {
                int prev = *(it - 1);
                best = min(best, abs(x - prev));
            }

            ans[i] = best;
        }

        return ans;
    }
};
