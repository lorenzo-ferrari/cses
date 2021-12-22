#include <stack>
#include <array>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
#define MAXN 1000

int main() {
    int n, m, xa, ya;
    char c;
    bool g[MAXN][MAXN]{};
    char t[MAXN][MAXN]{};
    scanf("%d %d", &n, &m);
    
    queue <array<int, 3>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &c);
            while (c != '#' && c != '.' && c != 'M' && c != 'A') scanf("%c", &c);
            //printf("%c", c);
            g[i][j] = (c != 'M' && c != '#');
            if (c == 'M') Q.push({i, j, 0});
            if (c == 'A') {xa = i; ya = j;}
        }
        //printf("\n");
    }
    //printf("%d %d\n", xa, ya);
    //printf("%d\n", (int)g[2][7]); return 0;
    t[xa][ya] = 'X';
    Q.push({xa, ya, 1});
    while (!Q.empty()) {
        int x = Q.front()[0];
        int y = Q.front()[1];
        int b = Q.front()[2];

        Q.pop();

        if (b && (x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
            //printf("reached line 35\n");
            //return 0;
            stack <char> st;
            /*
            if (x == 0) st.push('U');
            else if (y == 0) st.push('L');
            else if (x == n - 1) st.push('D');
            else if (y == m - 1) st.push('R');
            /*/

            while (x != xa || y != ya) {
                //printf("%d %d\n", x, y);
                if (t[x][y] == 'U') st.push('D');
                if (t[x][y] == 'D') st.push('U');
                if (t[x][y] == 'L') st.push('R');
                if (t[x][y] == 'R') st.push('L');

                if (t[x][y] == 'U') x--;
                else if (t[x][y] == 'D') x++;
                else if (t[x][y] == 'L') y--;
                else if (t[x][y] == 'R') y++;
                else break;
            }

            printf("YES\n");
            printf("%d\n", (int)st.size());
            while (!st.empty()) {
                printf("%c", st.top());
                st.pop();
            }
            printf("\n");
            return 0;
        }

        if (x > 0 && g[x - 1][y] && !t[x - 1][y]) {
            if (!b) g[x - 1][y] = false;
            if (b) t[x - 1][y] = 'D';
            Q.push({x - 1, y, b});
        }
        if (y > 0 && g[x][y - 1] && !t[x][y - 1]) {
            if (!b) g[x][y - 1] = false;
            if (b) t[x][y - 1] = 'R';
            Q.push({x, y - 1, b});
        }
        if (x < n - 1 && g[x + 1][y] && !t[x + 1][y]) {
            if (!b) g[x + 1][y] = false;
            if (b) t[x + 1][y] = 'U';
            Q.push({x + 1, y, b});
        }
        if (y < m - 1 && g[x][y + 1] && !t[x][y + 1]) {
            if (!b) g[x][y + 1] = false;
            if (b) t[x][y + 1] = 'L';
            Q.push({x, y + 1, b});
        }
    }

    printf("NO\n");
}
