class Solution {
public:
    struct Node {
        int _val = 0, _direct = 0, _pos = 0;
        Node() {}
        Node(int val, int direct, int pos) : _val(val), _direct(direct), _pos(pos) {}
        bool operator < (const Node& rhs) {
            if(_pos == rhs._pos){
                return _direct > rhs._direct;
            }
            return _pos < rhs._pos;
        } 
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<Node> data;
        for(auto& tmp : trips){
            data.emplace_back(tmp[0], 0, tmp[1]);
            data.emplace_back(tmp[0], 1, tmp[2]);
        }
        sort(data.begin(), data.end());
        int ans = 0;
        for(auto& tmp : data){
            if(tmp._direct == 0){
                ans += tmp._val;
                if(ans > capacity){
                    return false;
                }
            }else{
                ans -= tmp._val;
            }
        }
        return true;
    }
};