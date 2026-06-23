#include <vector>
#include <iostream>
#include <set>


int main() {
    int num = 0;
    std::cin >> num;
    int inf = 2009000999;
    while (num) {
        int n = 0, m = 0;
        std::cin >> n >> m;
        std::vector<std::vector<std::pair<int, int>>> gr(n);
        std::vector<int> dist(n, inf);
        std::set<std::pair<int, int>> dots;

        for (int i = 0; i < m; ++i) {
            int u = 0, v = 0, w = 0;
            std::cin >> u >> v >> w;
            gr[u].push_back({v, w});
            gr[v].push_back({u, w});
            }
        int start = 0;
        std::cin >> start;

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
        for (int i = 0; i < n; ++i) {
            std::cout << dist[i] << ' ';
        }
        std::cout << '\n';
        --num;
    }

    return 0;
}
