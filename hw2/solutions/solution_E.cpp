#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <string>


int main() {
    int n = 0, s = 0, m = 0;
    std::cin >> n >> s >> m;
    std::vector<std::vector<int>> gr(n + 1);
    int inf = 2*n;
    std::queue<int> q;

    for (int i = 0; i < m; ++i) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        gr[v].push_back(u);
    }

    std::vector<int> dist(n + 1, inf);
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : gr[cur]) {
            if (dist[to] > dist[cur] + 1) {
                dist[to] = dist[cur] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        std::cout << (dist[i] == inf ? -1 : dist[i]) << ' ';
    }

    return 0;
}
