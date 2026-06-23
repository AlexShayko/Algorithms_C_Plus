#include <vector>
#include <iostream>
#include <set>


int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    int start = 0, end = 0;
    std:: cin >> start >> end;
    int inf = 10000000 + 100;
    std::vector<std::vector<std::pair<int, int>>> gr(n + 1);
    std::vector<int> dist(n + 1, inf);
    std::set<std::pair<int, int>> dots;

    for (int i = 0; i < m; ++i) {
        int u = 0, v = 0, w = 0;
        std::cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
        }

    dots.insert({0, start});
    dist[start] = 0;
    while (!dots.empty()) {
        int cur = dots.begin() ->second;
        dots.erase(dots.begin());
        for (const auto& [to, w] : gr[cur]) {
            if (dist[to] > dist[cur] + w) {
                if (dist[to] != inf) {
                    dots.erase({dist[to], to});
                }
                dist[to] = dist[cur] + w;
                dots.insert({dist[to], to});
            }
        }
    }

    std::cout << (dist[end] == inf ? - 1 : dist[end]);

    return 0;
}
