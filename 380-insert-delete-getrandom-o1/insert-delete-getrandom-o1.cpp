class RandomizedSet {
public:
    unordered_map<int,int> mp;  // value -> index in arr
    vector<int> arr;

    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false; // already present
        }
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false; // not present
        }
        int index = mp[val];
        int lastVal = arr.back();

        // move last element to 'index'
        arr[index] = lastVal;
        mp[lastVal] = index;

        arr.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int idx = rand() % arr.size();
        return arr[idx];
    }
};
