#include<bits/stdc++.h>
using namespace std;

const int MAX = 1001;
vector<int> adj[MAX];
bool visited[MAX];
int component[MAX]; // Lưu thành phần liên thông của mỗi đỉnh
int comp_id;

void dfs(int u, int comp_id) {
    visited[u] = true;
    component[u] = comp_id;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, comp_id);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        // Reset đồ thị
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        
        // Đọc danh sách cạnh
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Đánh dấu các thành phần liên thông
        memset(visited, false, sizeof(visited));
        comp_id = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                comp_id++;
                dfs(i, comp_id);
            }
        }
        
        // Xử lý truy vấn
        int Q;
        cin >> Q;
        while (Q--) {
            int x, y;
            cin >> x >> y;
            if (component[x] == component[y]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
