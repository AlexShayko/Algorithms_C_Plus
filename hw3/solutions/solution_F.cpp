#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n = 0;
    std::cin >> n;

    long long inf = 1e18;

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = 0;
            std::cin >> num;

            if (num == 0) {
                dp[i][j] = inf;
            } else {
                dp[i][j] = num;
            }
        }

        if (dp[i][i] == inf || dp[i][i] > 0) {
            dp[i][i] = 0;
        }
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dp[i][k] != inf && dp[k][j] != inf)
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) std::cout << ' ';

            if (dp[i][j] == inf) {
                std::cout << 0;
            } else {
                bool neg = false;

                for (int k = 0; k < n; ++k) {
                    if (dp[i][k] != inf && dp[k][k] < 0 && dp[k][j] != inf) {
                        neg = true;
                    }
                }

                std::cout << (neg ? 2 : 1);
            }
        }

        std::cout << '\n';
    }

    return 0;
}
