class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor2 = 0;
        for(int i =0;i<nums2.size();i++){
            xor2 ^= nums2[i];
        }      
        int n = nums2.size();
        int ans = 0;
        for(int i =0;i<nums1.size();i++){
            if(n%2==0){
                ans ^= xor2;
            }
            else{
                ans ^=(nums1[i]^xor2);
            }
        }
        return ans;
        
    }
};