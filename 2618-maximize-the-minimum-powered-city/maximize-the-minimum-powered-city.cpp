class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long right = LLONG_MAX, left = 0;
        long long best = 0;
        
        while(left<=right){
            long long mid = left+(right-left)/2;
            if(isPossible(mid,stations,r,k)){
                best = mid;
                left = mid+1;
            }else{
                right = mid - 1;
            }
        }
        return best;
    }
    


    bool isPossible(long long min_power, vector<int> stations, int r, int k){
        long long cur_power = 0,power_needed=0;
        int n = stations.size();
        for (int i = 0; i <= r; i++) cur_power += stations[i];

        int left = 0, right = r;
        for (int i = 0; i < n; i++){
            if (i-left>r){
                cur_power -= stations[left];
                left ++;
            }
            if (right-i<r and right<n-1){
                right ++;
                cur_power += stations[right];
            }

            if (cur_power < min_power){
                power_needed = min_power-cur_power;
                if (k<power_needed) return false;
                stations[right] += power_needed;
                cur_power += power_needed;
                k -= power_needed;
            }
        }
        return true;
    }
};