class Solution {
public:
    bool check(vector<int>& aph, int k) {
        for(int i = 0; i < 26; ++i){
            if(aph[i] != 0 && aph[i] != k){
                return false;
            }
        }
        return true;
    }

    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        vector<int> pos;
        for(int i = 1; i < n; ++i){
            if(abs(word[i]-word[i-1]) > 2){
                pos.push_back(i);
            }
        }
        pos.push_back(n);
        int l = 0, r = 0;
        int ans = 0;
        for(auto v : pos){
            l = r, r = v;
            for(int i = 0; i < 26; ++i){
                vector<int> aph(26, 0);
                int len = (i+1)*k;
                if(len > r-l) break;
                for(int j = l; j < l+len; ++j){
                    aph[word[j]-'a']++;
                }
                if(check(aph, k)) ans++;
                for(int j = l+len; j < r; ++j){
                    aph[word[j]-'a']++;
                    aph[word[j-len]-'a']--;
                    if(check(aph, k)) ans++;
                }
            }
        }
        return ans;
    }
};