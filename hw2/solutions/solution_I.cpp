#include <vector>
#include <iostream>
#include <set>
#include <map>

struct trip {
    int t_0 = 0;
    int to = 0;
    int t_1 = 0;

};

int main() {
    int n = 0;
    std::cin >> n;
    int start = 0, end = 0;
    std::cin >> start >> end;
    int inf = 10000000 + 100;
    std::vector<std::vector<trip>> gr(n + 1);
    std::vector<int> dist(n + 1, inf);
    std::set<std::pair<int, int>> dots;

    int r = 0;
    std::cin >> r;

    for (int i = 0; i < r; ++i) {
        int from, t_0, to, t_1;
        std::cin >> from >> t_0 >> to >> t_1;
        gr[from].push_back({t_0, to, t_1});
        }

    dots.insert({0, start});
    dist[start] = 0;
    while (!dots.empty()) {
        int cur = dots.begin() ->second;
        dots.erase(dots.begin());
        for (const auto& [t_0, to, t_1] : gr[cur]) {
            if (dist[to] > t_1 && dist[cur] <= t_0) {
                if (dist[to] != inf) {
                    dots.erase({dist[to], to});
                }
                dist[to] = t_1;
                dots.insert({dist[to], to});
            }
        }
    }

    std::cout << (dist[end] == inf ? - 1 : dist[end]);

    return 0;
}
