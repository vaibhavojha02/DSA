class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
         int low = 0,high = arr.size()-1;
         while(low<high){
            int mid = low + (high-low)/2;
            if(arr[mid]==arr[mid-1])
            {
                if((mid-low-1)%2==0){
                    low = mid+1;
                }
                else{
                    high = mid;
                }
            }
            else if(arr[mid]==arr[mid+1]){
                 if((high-mid-1)%2==0){
                    high = mid-1;
                }
                else{
                    low = mid;
                }
            }
            else{
                return arr[mid];
            }
         }
         return arr[low];
    }
};