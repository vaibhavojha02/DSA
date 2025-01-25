class Solution {
public:
    bool check(int n,int m,int k,int x){
        int cnt = 0;
        for(int i =1;i<=n;i++){
            int rem = x/i;
            if(rem==0){
                break;
            }
            else{
                cnt += min(rem,m);
            }

        }
        return cnt >= k; 
    }
    int findKthNumber(int m, int n, int k) {
        long long ans = -1;
        int low = 0,high = m*n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(n,m,k,mid)){
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