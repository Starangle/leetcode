#define target first
#define label second
#define RED 1
#define BLUE 0
#define N 1000

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> red_edges, vector<vector<int>> blue_edges) {
        vector<pair<int, int>> graph[n];
        for(auto item : red_edges)
            graph[item[0]].push_back({item[1], RED});

        for(auto item : blue_edges)
            graph[item[0]].push_back({item[1], BLUE});

        int vis[N][N][2]{0};
        queue<pair<int, int>> q;
        q.push({0, -1});
        vector<int> ans(n, -1);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto front = q.front();
                q.pop();
                ans[front.first] = ans[front.first] == -1 ? level : ans[front.first];
                if(front.second == -1 || front.second == RED) {
                    for(auto item : graph[front.first]) {
                        int nxt = item.target;
                        int c = item.label;
                        if((c == BLUE || front.second == -1) && !vis[front.first][nxt][c]) {
                            vis[front.first][nxt][c] = 1;
                            q.push({nxt, c});
                        }
                    }
                }

                if(front.second == -1 || front.second == BLUE) {
                    for(auto item : graph[front.first]) {
                        int nxt = item.target;
                        int c = item.label;
                        if((c == RED || front.second == -1) && !vis[front.first][nxt][c]) {
                            vis[front.first][nxt][c] = 1;
                            q.push({nxt, c});
                        }
                    }
                }
            }
            level++;
        }

        return ans;

    }
};