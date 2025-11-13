#include<bits/stdc++.h>
using namespace std;

const int MAX = 1001;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        // Reset đồ thị
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        
        // Đọc danh sách cạnh
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Reset mảng visited
        memset(visited, false, sizeof(visited));
        
        int count = 0; // Đếm số thành phần liên thông
        
        // Duyệt qua tất cả các đỉnh
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i); // Duyệt toàn bộ thành phần liên thông chứa i
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
