#include <iostream>
#include <vector>
#include <queue>

int main() {

    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> gr(n + 2, std::vector<int>(m + 2, -1));
    int inf = 1e8;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> gr[i][j];
            if (gr[i][j] == 1) {
                gr[i][j] = -1;
            } else {
                gr[i][j] = inf;
            }
        }
    }

    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    std::swap(x1, y1);
    std::swap(x2, y2);

    gr[x1][y1] = 0;
    std::queue<std::pair<int, int>> q;
    q.emplace(x1, y1);

    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
            if (gr[x + dx][y + dy] > gr[x][y] + 1) {
                gr[x + dx][y + dy] = gr[x][y] + 1;
                q.emplace(x + dx, y + dy);
            }
        }
    }

    std::cout << ((gr[x2][y2] == -1 || gr[x2][y2] == inf) ? -1 : gr[x2][y2]);


    return 0;
}
