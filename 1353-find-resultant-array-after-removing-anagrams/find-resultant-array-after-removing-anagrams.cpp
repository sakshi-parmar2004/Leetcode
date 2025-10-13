class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int j=1;
        while(j<words.size())
        {
             string data1 = words[j-1];
    string data2 = words[j];

    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

            if(data1 == data2)
            {
            words.erase(words.begin()+ j);
            }
            else
            {
                j++;
            }
           
        }
        return words;
    }
};