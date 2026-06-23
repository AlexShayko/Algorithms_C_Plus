#include <vector>
#include <iostream>
#include <set>

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::set<int>> gr(n + 1);

    for (int i = 0; i < m; ++i) {
        int from = 0, to = 0;
        std::cin >> from >> to;
        if (!(from == to)) {
            if (from < to) {
                gr[from].insert(to);
            } else {
                gr[to].insert(from);
            }
        }
    }
    int counter_ed = 0;
    for (int i = 1; i < n + 1; ++i) {
        if (gr[i].size() != 0) {
            counter_ed += gr[i].size();
        }
    }
    std::cout << n << ' ' << counter_ed << '\n';
    for (int i = 1; i < n; ++i) {
        if (gr[i].size() != 0) {
            for (auto el : gr[i]) {
                std::cout << i << ' ' << el << '\n';
            }
        }
    }

    return 0;
}
