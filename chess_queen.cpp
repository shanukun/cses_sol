#include <bits/stdc++.h>

using namespace std;

const int n = 8;
char mat[n][n];
int col[n], dig1[2 * n], dig2[2 * n];
int cnt = 0;

void q(int r) {
    if (r == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (col[i] || dig1[7 + i - r] || dig2[r + i] || mat[r][i] == '*')
            continue;
        col[i] = dig1[7 + i - r] = dig2[r + i] = 1;
        q(r + 1);
        col[i] = dig1[7 + i - r] = dig2[r + i] = 0;
    }
}

int main() {
    int st = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j], st += mat[i][j] == '*';
    q(0);
    cout << cnt;
}

