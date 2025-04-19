class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<pair<int, int>, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({{intervals[i][0], intervals[i][1]}, i});
        }
        vector<int> res(n);
        sort(temp.begin(), temp.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto i : temp) {
            cout << "{{" << i.first.first << " " << i.first.second << "} {"
                 << i.second << "}},";
        }
        for (int i = 0; i < n - 1; i++) {
            int curridx = temp[i].second;
            int nextidx = temp[i + 1].second;
            int nextstart = temp[i + 1].first.first;
            int currend = temp[i].first.second;
            if(currend <= temp[i].first.first){
                res[curridx] = curridx;
                continue;
            }
             while (!pq.empty()) {
                    if (pq.top().first <= nextstart) {
                        res[pq.top().second] = nextidx;
                        pq.pop();
                    } else {
                        break;
                    }
            }
            if (nextstart >= currend) {
                res[curridx] = nextidx;

            } else {
                pq.push({currend, curridx});
            }
        }
        while (!pq.empty()) {
            res[pq.top().second] = -1;
            pq.pop();
        }
        if (temp[n - 1].first.first >= temp[n - 1].first.second) {
            res[temp[n - 1].second] = temp[n - 1].second;
        } else {
            res[temp[n - 1].second] = -1;
        }
        return res;
    }
};