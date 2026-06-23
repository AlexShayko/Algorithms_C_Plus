#include <vector>
#include <iostream>
class Edges {
public:
    int to = 0;
    int w = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<Edges>> edges(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = 0;
            std::cin >> num;
            if (num != 100000) {
                edges[i].push_back({j, num});
            }
        }
    }
    int inf = 10000001;
    std::vector<int> dist(n, inf);
    std::vector<int> bf_parent(n, -1);
    int last_relaxed = -1;

	for (int i = 0; i < n; ++i) dist[i] = 0;
    bool isCycle = false;

    for (int k = 1; k <= n; ++k) {
        last_relaxed = -1;
        for (int i = 0; i < n; ++i) {
            for (auto& v : edges[i]) {
                if (dist[i] == inf) continue;
                if (dist[v.to] > dist[i] + v.w) {
                    dist[v.to] = dist[i] + v.w;
                    bf_parent[v.to] = i;
                    if (k == n) {
                        isCycle = true;
                        last_relaxed = v.to;
                    }
                }
            }
        }
    }

    if (isCycle) {
        int x = last_relaxed;
        for (int i = 0; i < n; ++i) x = bf_parent[x];

        std::vector<int> cycle;
        int cur = x;
        do {
            cycle.push_back(cur);
            cur = bf_parent[cur];
        } while (cur != x);
        cycle.push_back(x);

        std::cout << "YES\n";
        std::cout << cycle.size() << "\n";
        for (int i = (int)cycle.size() - 1; i >= 0; --i) {
            if (i != (int)cycle.size() - 1) std::cout << ' ';
            std::cout << cycle[i] + 1;
        }
        std::cout << "\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}
