#include <vector>
#include <iostream>

class Edges {
public:
    int from = 0;
    int to = 0;
    int w = 0;
};

std::istream& operator >>(std::istream& is, Edges& edge) {
    is >> edge.from >> edge.to >> edge.w;
    return is;
}

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    int inf = 30000;
    std::vector<Edges> edges(m);
    for (auto& e : edges) {
        std::cin >> e;
    }
    std::vector<int> dist(n + 1, inf);
    dist[1] = 0;
    bool isRelax = true;
    for (int k = 0; (k < n - 1) && isRelax; ++k) {
        isRelax = false;
        for (auto& [f, t, w] : edges) {
            if (dist[f] == inf) continue;
            if (dist[t] > dist[f] + w) {
                dist[t] = dist[f] + w;
                isRelax = true;
            }
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        std::cout << dist[i] << ' ';
    }

    return 0;
}
