class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int days = n / 4;
        int evenDays = (days+1) / 2;
        int oddDays = days - evenDays;
        int i = n - 1;
        long long ans = 0;
        if(evenDays==0){
            return pizzas[i];
        }
        // evenDays
        while (evenDays > 0) {
            ans += pizzas[i];
            evenDays--;
            i--;
        }
        i -= 1;
        while (oddDays > 0){
            ans += pizzas[i];
            oddDays--;
            i -= 2;
        }
        return ans;
    }
};