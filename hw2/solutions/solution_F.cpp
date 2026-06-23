#include <iostream>
#include <vector>
#include <set>

int main() {

    int n = 0, s = 0, f = 0;
    std::cin >> n >> s >> f;
    std::vector<std::vector<std::pair<int, int>>> gr(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int num = 0;
            std::cin >> num;
            if (num != -1) {
                gr[i].emplace_back(num, j);
            }
        }
    }
    int inf = 1e9;
    std::vector<int> dist(n + 1, inf);
    std::set<std::pair<int, int>> st;
    st.insert({0, s});

    while (!st.empty()) {
        auto [d, v] = *st.begin();
        st.erase(st.begin());

        for (auto[w, to] : gr[v]) {
            if (dist[to] > d + w) {
                st.erase({dist[to], to});
                dist[to] = d + w;
                st.insert({dist[to], to});
            }
        }
    }

    std::cout << ((dist[f] == inf) ? -1 : dist[f]);

    return 0;
}
