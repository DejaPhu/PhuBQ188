#include<bits/stdc++.h>
using namespace std;

const int MAX = 1001;
vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX];

void bfs(int start, int target, int n) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == target) {
            return; // Tìm thấy đích
        }
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void printPath(int start, int target) {
    if (!visited[target]) {
        cout << -1;
        return;
    }
    
    vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " ";
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        
        // Reset đồ thị
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        
        // Đọc danh sách cạnh
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        // Reset mảng visited và parent
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        
        // Thực hiện BFS
        bfs(s, t, n);
        
        // In kết quả
        printPath(s, t);
        cout << endl;
    }
    
    return 0;
}
