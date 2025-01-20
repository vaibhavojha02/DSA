class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long defaultCost = 0;
        int n = arr.size();
        for(int i =0;i<n;i++){
            defaultCost += abs(arr[i]-brr[i]);
        }
        long long opsCost = k;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        for(int i=0;i<n;i++){
           opsCost += abs(arr[i]-brr[i]);
        }
        return min(opsCost,defaultCost);

    }
};