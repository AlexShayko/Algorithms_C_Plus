#include <vector>
#include <iostream>
#include <set>

class Edges {
public:
    int from = 0;
    int time_f = 0;
    int to = 0;
    long long time_to = 0;
};

std::istream& operator >>(std::istream& is, Edges& edge) {
    is >> edge.from >> edge.time_f >> edge.to >> edge.time_to;
    return is;
}

int main() {
    int n = 0;
    std::cin >> n;
    int start = 0, end = 0;
    std::cin >> start >> end;
    int num = 0;
    std::cin >> num;
    long long inf = 1e18;
    std::vector<Edges> edges(num);
    for (auto& e : edges) {
        std::cin >> e;
    }
    std::vector<long long> dist(n + 1, inf);
    dist[start] = 0;
    bool isRelax = true;
    for (int k = 0; (k < num) && isRelax; ++k) {
        isRelax = false;
        for (auto& [f, f_t, t, t_t] : edges) {
            if (dist[f] == inf) continue;
            if ((dist[f] <= f_t) && (dist[t] > t_t)) {
                dist[t] = t_t;
                isRelax = true;
            }
        }
    }

    std::cout << dist[end];

    return 0;
}
