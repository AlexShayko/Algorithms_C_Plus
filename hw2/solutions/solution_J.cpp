#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <iomanip>

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    int inf = 100000 + 1000;
    std::vector<std::vector<std::pair<int, int>>> gr(n + 1);
    std::set<std::pair<int, int>> dots;
    double counter = 0;
    double sum = 0;
    for (int i = 0; i < m; ++i) {
        int from = 0, to = 0, w = 0;
        std::cin >> from >> to >> w;
        gr[from].push_back({to, w});
        }
    for (int start = 1; start < n + 1; ++start) {
        std::vector<int> dist(n + 1, inf);
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
        for (int el : dist) {
            if (el != inf && el != 0) {
                counter += 1;
                sum += el;
            }
        }
    }
    std::cout << std::fixed << std::setprecision(6) << sum/counter;
    return 0;
}
