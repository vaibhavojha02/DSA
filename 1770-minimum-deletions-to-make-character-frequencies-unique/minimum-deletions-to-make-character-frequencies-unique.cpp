class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int ops = 0;
        for (auto i : freq) {
            cout << i << " ";
        }
        cout<<endl;
        int number_to_be_present = freq[0] - 1;
        for (int i = 1; i < 26; i++) {
            if (freq[i] == 0)
                break;
            cout<<number_to_be_present<<endl;
            if(number_to_be_present<0){
                ops++;
                continue;
            }
            //if number_to_be_present < 0 which means now we only have to make that frequency equal to zero because we cannot further decrease beyond 0
        
            if (freq[i] != number_to_be_present) {
                if (freq[i] <= number_to_be_present){
                    number_to_be_present = max(freq[i] - 1,0);
                } else {
                    ops += abs(freq[i] - number_to_be_present);
                    number_to_be_present = max(0,number_to_be_present-1);
                }
            }
            else{
                number_to_be_present = max(0,number_to_be_present-1);
            }
        }
        return ops;
    }
};