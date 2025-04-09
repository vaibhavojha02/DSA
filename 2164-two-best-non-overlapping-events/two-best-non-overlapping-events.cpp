class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; //{endtime,value};
        int maxi = 0, maxele = 0;

        for (int i = 0; i < events.size(); i++) {

            while (!pq.empty() && pq.top().first < events[i][0]) {
                maxele = max(maxele, pq.top().second);
                pq.pop();
            }
            maxi = max(maxi, maxele + events[i][2]);
            pq.push({events[i][1], events[i][2]});
        }
        return maxi;
    }
};