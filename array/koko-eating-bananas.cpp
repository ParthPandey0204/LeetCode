class Solution {
public:
    bool checkingrateofbananaseaten(vector<int> piles, int mid, int h){
        long long hours = 0;
        for(int i = 0; i < piles.size() ; i++){
            hours += piles[i]/mid;
            piles[i] %= mid;
            if(piles[i] > 0) hours++;
            if(hours > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while( low <= high){
            int mid = (low+high)/2;
            if( checkingrateofbananaseaten(piles,mid,h)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }

};