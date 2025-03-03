class Solution {
public:
    string findroot(string& word,unordered_set<string>&st){
        for(int l=1;l<=word.length();l++){
            string root =  word.substr(0,l);
            if(st.find(root)!=st.end()){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        stringstream ss(sentence);
        string word;
        string result;
        while(getline(ss,word,' ')){
            result += findroot(word,st) + " ";
        }
        result.pop_back();
        return result;

    }
};