class Solution {
public:
   
    bool comp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        else{
            return a[1]<b[1];
        }
    }
    
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(),meetings.end(),[&](vector<int>&a,vector<int>&b){
            return comp(a,b);
        });
        int day =1;
        int ans =0;
        for(int i =0;i<meetings.size();i++)
        {
           if(meetings[i][0]>day)
           {
             if(i==0) ans += meetings[i][0] - day;
             else{ans += meetings[i][0] - day-1;}
             day = meetings[i][1];
           }
           else
           {
             if(meetings[i][1]>day)day = meetings[i][1];
           }

        }
        ans += days-day;
        return ans;
    }
};