#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> sizes;
std::vector<int> parent;

int find(int v) {
    if (parent[v] == v) {
        return v;
    }
    parent[v] = find(parent[v]);
    return parent[v];
}

bool unite(int a, int b) {
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) {
        return false;
    }
    if (sizes[p_a] < sizes[p_b]) {
        std::swap(p_a, p_b);
    }
    parent[p_b] = p_a;
    sizes[p_a] += sizes[p_b];
    return true;
}

int main() {

    int n = 0;
    std::cin >> n;
    parent.resize(n);
    sizes.assign(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    std::vector<std::pair<int, std::pair<int, int>>> prices;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = 0;
            std::cin >> num;
            if (num == 0) {
                unite(i, j);
            } else if (i < j) {
                prices.push_back({num, {i, j}});
            }
        }
    }

    std::sort(prices.begin(), prices.end());

    int sum = 0;

    for (int i = 0; i < prices.size(); ++i) {
        int cost = prices[i].first;
        int from = prices[i].second.first;
        int to = prices[i].second.second;

        if (unite(from, to)) {
            sum += cost;
        }
    }

    std::cout << sum;

    return 0;


}
