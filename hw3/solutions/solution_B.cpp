#include <vector>
#include <iostream>

class Edges {
public:
    int from = 0;
    int to = 0;
    int w = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    int inf = 1e9;
    std::vector<int> dist(n + 1, inf);
    dist[1] = 0;
    bool isRelax = true;
    for (int k = 0; (k < n - 1) && isRelax; ++k) {
        isRelax = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (dist[j] == inf) continue;
                int w = ((179 * j + 719 * i) % 1000) - 500;
                if (dist[i] > dist[j] + w) {
                    dist[i] = dist[j] + w;
                    isRelax = true;
                }
            }
        }
    }

    std::cout << dist[n];
    return 0;
}
