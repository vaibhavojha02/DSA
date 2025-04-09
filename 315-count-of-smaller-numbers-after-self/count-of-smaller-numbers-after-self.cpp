#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());

        ordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int idx = st.order_of_key(temp[i].second); // O(log n)
            res[temp[i].second] = st.size() - idx;
            st.insert(temp[i].second);
        }

        return res;
    }
};
