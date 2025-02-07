class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,set<int>>color;
        unordered_map<int,int>ball;
        int n = queries.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(ball.find(x)!=ball.end()){
                int in_color = ball[x];
                color[in_color].erase(x);
                if(color[in_color].size()==0){
                    color.erase(in_color);
                }
                ball.erase(x);
            }
            ball[x] = y;
            color[y].insert(x);
            int temp = color.size();
            res[i] = temp;
        }
        return res;
    }
};