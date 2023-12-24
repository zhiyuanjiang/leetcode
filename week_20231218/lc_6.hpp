class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.length();
        vector<vector<int>> g(numRows);
        int k = 0;
        while(k < n){
            for(int i = 0; i < numRows-1; ++i){
                if(k < n){
                    g[i].emplace_back(s[k]);
                    cout << i << " " << n << " " << k << endl;;
                }else{
                    cout << n << " " << k << "fuck" << endl;;
                    break;
                }
                ++k;
                
            }
        
            for(int i = 0; i < numRows-1; ++i){
                if(k < n){
                    g[numRows-i-1].emplace_back(s[k]);
                }else{
                    cout << "fuck" << endl;
                    break;
                }
                k++;
            }  
            
        }
        std::string ans = "";
        for(int i = 0; i < numRows; ++i){
            for(auto& ch : g[i]){
                ans += ch;
            }
        }
        return ans;
    }
};