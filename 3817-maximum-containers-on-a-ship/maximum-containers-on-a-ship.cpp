class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {  
        int can_place = maxWeight/w;
        int spaces = n*n;
        return min(can_place,spaces);
    }
};