class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, mid = INT_MAX;
        
        for (int num : nums) {
            if (num <= left) 
                left = num;  // Smallest number found
            else if (num <= mid) 
                mid = num;   // Second smallest number found
            else 
                return true; // A number greater than 'mid' means an increasing triplet exists
        }
        
        return false;
    }
};