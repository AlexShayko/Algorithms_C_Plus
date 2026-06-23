#include <vector>
#include <iostream>
#include <set>

class Edges {
public:
    int from = 0;
    int to = 0;
    int w = 0;
};

std::vector<std::vector<int>> gr;
std::vector<int> neg;

std::istream& operator >>(std::istream& is, Edges& edge) {
    is >> edge.from >> edge.to >> edge.w;
    return is;
}

void dfs(int v) {
    neg[v] = 1;
    for (int to : gr[v]) {
        if (neg[to] != 1) {
            dfs(to);
        }
    }
}

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    gr.resize(n);
    neg.assign(n, 0);
    int inf = 2 * 100000000;
    std::vector<Edges> edges(m);
    for (auto& e : edges) {
        std::cin >> e;
        gr[e.from].push_back(e.to);
    }
    std::vector<int> dist(n, inf);
    dist[0] = 0;
    bool isRelax = true;
    for (int k = 1; (k <= n) && isRelax; ++k) {
        isRelax = false;
        for (auto& [f, t, w] : edges) {
            if (dist[f] == inf) continue;
            if ((dist[t] > dist[f] + w) && (k < n)) {
                dist[t] = dist[f] + w;
                isRelax = true;
            }
            if ((dist[t] > dist[f] + w) && (k == n)) {
                neg[f] = 1;
                neg[t] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (neg[i] == 1) {
            dfs(i);
        }
    }

    for (int i = 1; i < n; ++i) {
        if (neg[i] == 0) {
            std::cout << dist[i] << '\n';
        } else {
            std::cout << "-inf" << '\n';
        }
    }

    return 0;
}
