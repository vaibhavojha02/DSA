class Solution {
public:
    int numberOfSpecialChars(string word) {
      int n = word.size();
      vector<int>upper(26,-1);
      vector<int>lower(26,-1);
      for(int i = n-1;i>=0;i--){
         if(isupper(word[i])){
            upper[word[i]-'A'] = i;
         }
         else{
            if(lower[word[i]-'a'] == -1){
                lower[word[i]-'a'] = i;
            }
         }
         
      }
      int result = 0;
      for(int i =0;i<26;i++){
        if(upper[i] !=-1  && lower[i] != -1  && upper[i] > lower[i]){
           result++;
        }
        cout<<upper[i]<<" "<<lower[i]<<endl;
      }
      return result;
    }
};