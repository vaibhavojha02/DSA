class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> rooms;
        for (int i = 0; i < n; i++)
            rooms.push(i);

        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        map<int, int> mp;  // Changed back to map<int, int> for room count

        int i = 0;
        while (i < meetings.size()) {
            long long start_time = meetings[i][0];  // Changed to long long
            long long end_time = meetings[i][1];    // Changed to long long

            while (!pq.empty() && start_time >= pq.top().first) {
                int available_room_id = pq.top().second;
                pq.pop();
                rooms.push(available_room_id);
            }

            if (!rooms.empty()) {
                int room = rooms.top();
                rooms.pop();
                pq.push({end_time, room});
                mp[room] += 1;
            } else {
                long long time_required_to_finish = pq.top().first;  // Changed to long long
                int room = pq.top().second;
                pq.pop();
                pq.push({time_required_to_finish + (end_time - start_time), room});
                mp[room] += 1;
            }
            i++;
        }

        int ans = 0;
        int room_no = -1;
        for (auto &entry : mp) {
            cout << entry.first << " " << entry.second << " ";
            if (entry.second > ans) {  
                // Ensuring smallest room index is returned in case of tie
                ans = entry.second;
                room_no = entry.first;
            }
        }
        return room_no;
    }
};
