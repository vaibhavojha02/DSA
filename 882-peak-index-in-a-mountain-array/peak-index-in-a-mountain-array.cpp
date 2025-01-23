class Solution {
public:
    int n ;
    bool check(int x,vector<int>&arr){
        if(x ==n-1 || arr[x] > arr[x+1]){
            return 1;
        }
        else{
            return 0;
        }
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        n = arr.size();
        int low = 0,high = arr.size()-1;
        int ans = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid,arr)==true){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};