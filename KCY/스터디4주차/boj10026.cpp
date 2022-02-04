#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[102][102];
bool vis[102][102];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�

int get_area_count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                cnt++;
                queue<pair<int, int>> Q;
                Q.push({ i,j });
                vis[i][j] = 1;
                while (!Q.empty()) {
                    auto cur = Q.front(); 
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({ nx,ny });
                    }
                }
            }
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int count_1 = get_area_count(); //���ϻ����� �ƴ� ���

    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + n, false); //�湮 �迭 �ʱ�ȭ
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'R')
                board[i][j] = 'G'; //�������� �ʷϻ����� ���� ����.
    }

    int count_2 = get_area_count(); //���ϻ����� ���
    cout << count_1 << " " << count_2;

}