class Solution {
public:
    int numOfSubarrays(vector<int>& arr){
       int mod = 1e9+7;
       int oddCount = 0, evenCount =1;
       int res = 0;
       int sum  = 0;
       for(int i=0;i<arr.size();i++){
          sum += arr[i];
          if(sum%2==0){
             res += oddCount;
             evenCount++;
          }
          else{
            res += evenCount;
            oddCount++;
          }
          res %= mod;
       }
       return res;
    }
};