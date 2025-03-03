class Solution {
public:
    int findSmallerinRight(vector<int>& heaters, int ele) {
        int low = 0, high = heaters.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (heaters[mid] < ele) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;  // `high` points to the last element < ele, or -1 if none exist
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m = heaters.size();
        vector<int> ans(houses.size(), INT_MAX);

        sort(heaters.begin(), heaters.end());

        for (int i = 0; i < houses.size(); i++) {
            int ceil = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            int floor = findSmallerinRight(heaters, houses[i]);

            if (ceil < m) // Valid upper bound heater exists
                ans[i] = min(ans[i], heaters[ceil] - houses[i]);
            if (floor >= 0) // Valid lower bound heater exists
                ans[i] = min(ans[i], houses[i] - heaters[floor]);
                cout<<ans[i]<<" ";
        }

        return *max_element(ans.begin(), ans.end());
    }
};
