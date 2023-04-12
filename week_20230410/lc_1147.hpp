#pragma once
#include <iostream>
#include <string>

using namespace std;

/*
    exp: "ghiabcdefhelloadamhelloabcdefghi" 7
*/

class Solution {
public:
    int longestDecomposition(string text) {
        if(text.length() == 0) return 0;
        int pos = 0;
        for(int i = 1; i <= text.length()/2; ++i){
            bool flag = false;
            for(int j = 0; j < i; ++j){
                if(text[j] != text[text.length()-i+j]){
                    flag = true;
                    break;
                }
            }

            if(!flag){
                pos = i;
                break;
            }
        }
        int ans = 0;
        // cout << pos << endl;
        if(pos != 0){
            ans += 2 + longestDecomposition(text.substr(pos, text.length()-2*pos));
        }else{
            return 1;
        }
        return ans;
    }
};