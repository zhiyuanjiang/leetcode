#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    bool isRobotBounded(string instructions) {
        if(instructions.length() == 0) return true;
        int direct = 0;
        for(auto ch : instructions){
            if(ch == 'L') direct++;
            if(ch == 'R') direct--;
        }
        direct = abs(direct);
        if(direct % 4 != 0) return true;
        int x, y, d;
        x = y = d = 0;
        for(auto ch : instructions){
            if(ch == 'G'){
                x += dx[d];
                y += dy[d];
            }
            if(ch == 'L'){
                d = (d+1)%4;
            }
            if(ch == 'R'){
                d = (d-1+4)%4;
            }
        }
        if(x == 0 && y == 0) return true;
        return false;
    }
};