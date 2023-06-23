
#include <bits/stdc++.h>
using namespace std;

enum class VertexStatus {
    Undiscovered,
    Discovered,
    Finished
};

bool has_cycle(int start, const std::vector<std::vector<int>>& adj_list, std::vector<VertexStatus>& status) {
    status[start] = VertexStatus::Discovered;
    for (int neighbor : adj_list[start]) {
        if (status[neighbor] == VertexStatus::Undiscovered) {
            if (has_cycle(neighbor, adj_list, status)) {
                return true;
            }
        } else if (status[neighbor] == VertexStatus::Discovered) {
            return true;
        }
    }
    status[start] = VertexStatus::Finished;
    return false;
}

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj_list(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u].push_back(v);
    }
    std::vector<VertexStatus> status(n+1, VertexStatus::Undiscovered);
    bool has = false;
    for (int i = 1; i <= n; i++) {
        if (status[i] == VertexStatus::Undiscovered) {
            has |= has_cycle(i, adj_list, status);
        }
    }
    std::cout << (has ? "YES" : "NO") << std::endl;
    return 0;
}