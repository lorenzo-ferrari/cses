#include <vector>
#include <iostream>
using namespace std;

const int LEV = 35;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector <int> to(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &to[i]);
    
    // build the sparse table
    vector <vector<int>> table(LEV, vector <int> (n + 1));
    {
        for (int i = 1; i <= n; i++) {
            table[0][i] = i;
            table[1][i] = to[i];
        }
        for (int i = 2; i < LEV; i++)
            for (int j = 1; j <= n; j++)
                table[i][j] = table[i - 1][table[i - 1][j]];
    }

    while (q--) {
        // query
        int x, k;
        scanf("%d%d", &x, &k);

        while (k) {
            int steps = 0;
            while (steps < LEV - 1 && (1 << (steps) <= k))
                steps++;
            x = table[steps][x];
            k -= (1 << (steps - 1));
        }

        printf("%d\n", x);
    }


}
