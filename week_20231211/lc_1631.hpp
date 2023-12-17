class Solution {
public:
    struct Node {
        int _x, _y, _val;
        Node(int x, int y, int v): _x(x), _y(y), _val(v) {}
        bool operator < (const Node& rhs) const {
            return _val > rhs._val;
        }
    };

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool inside(int x, int y, int r, int c) {
        return x >= 0 && x < r && y >= 0 && y < c;
    }

    int bfs(vector<vector<int>>& graph) {
        priority_queue<Node> q;
        q.push(Node(0, 0, 0));
        int r = graph.size(), c = graph[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        while(!q.empty()){
            Node tmp = q.top();
            vis[tmp._x][tmp._y] = 1;
            // cout << tmp._x << " " << tmp._y << " " << tmp._val << endl;
            q.pop();
            if(tmp._x == r-1 && tmp._y == c-1){
                return tmp._val;
            }
            for(int i = 0; i < 4; ++i){
                int nx = dx[i] + tmp._x;
                int ny = dy[i] + tmp._y;
                if(inside(nx, ny, r, c) && !vis[nx][ny]){
                    q.push(Node(nx, ny, max(tmp._val, abs(graph[nx][ny] - graph[tmp._x][tmp._y]))));
                }
            }
        }
        return 0;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = bfs(heights);
        return ans;
    }
};