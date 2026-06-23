#include <vector>
#include <iostream>

std::vector<std::vector<int>> gr;
std::vector<int> used;
std::vector<int> parents;

void dfs_dist(int v, int counter) {
    used[v] = counter;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs_dist(to, counter + 1);
        }
    }
}

void dfs_dist2(int v, int counter, int p) {
    used[v] = counter;
    parents[v] = p;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs_dist2(to, counter + 1, v);
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    gr.resize(n + 1);
    used.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int from = 0, to = 0;
        std::cin >> from >> to;
        gr[from].push_back(to);
        gr[to].push_back(from);
    }

    dfs_dist(1, 1);
    int max = 1;
    for (int i = 1; i < n + 1; ++i) {
        if (used[i] > used[max]) {
            max = i;
        }
    }
    parents.resize(n + 1);
    used.assign(n + 1, 0);
    dfs_dist2(max, 1, -1);
    for (int i = 1; i < n + 1; ++i) {
        if (used[i] > used[max]) {
            max = i;
        }
    }
    int diam = used[max] - 1;
    int steps = diam / 2;
    if (diam % 2 == 0) {
        std::cout << steps << ' ' << 1 << ' ';
        int counter = 0;
        while (counter != steps) {
            max = parents[max];
            counter += 1;
        }
        std::cout << max;
    } else {
        std::cout << steps + 1 << ' ' << 2 << ' ';
        int counter = 0;
        while (counter != steps) {
            max = parents[max];
            counter += 1;
        }
        std::cout << ((max < parents[max]) ? max : parents[max]) << ' ' << ((max > parents[max]) ? max : parents[max]);
    }
    return 0;
}
