class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int rungss = 0;
        int height = 0;
        for(int i = 0 ; i<rungs.size() ; i++){
            if(rungs[i]-height<=dist){
                height = rungs[i];
                continue;
            }
            else{
                int max_req = ceil((rungs[i]-height)/dist*1.0);
                if(height+max_req*dist == rungs[i]){
                    rungss += (max_req-1);
                    
                }
                else{
                     rungss += max_req;
                     
                }
                height = rungs[i];
            }
        }
        return rungss;
    }
};