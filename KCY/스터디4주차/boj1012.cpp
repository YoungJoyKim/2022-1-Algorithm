#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[52][52];

bool vis[52][52]; // 해당 칸을 방문했는지 여부를 저장
int n, m, k, tc; // n = 행의 수, m = 열의 수, k = 배추 개수, tc = 테스트케이스 개수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> tc;
    for (int tcount = 0; tcount < tc; tcount++) {
        cin >> n >> m >> k;
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[x][y] = 1;
        }

        int num = 0; //필요한 벌레의 수

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0 || vis[i][j]) continue; //해당 좌표에 배추가 없거나 방문을 했을 경우 continue
                num++; //벌레 +1
                queue<pair<int, int>> Q;
                vis[i][j] = 1; //방문했음을 표시
                Q.push({ i,j });
                while (!Q.empty()) { //BFS 시작.
                    //area++;
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                        Q.push({ nx,ny });
                    }

                }
            }
        }

        cout << num << '\n';

        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, false);
        }
    }
}