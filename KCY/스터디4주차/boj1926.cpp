#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502];

bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n , m ; // n = 행의 수, m = 열의 수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int main(void) {

    ios::sync_with_stdio(false); //iostream과 stdio의 버퍼를 동기화시키는걸 false로 바꿔서, 싱글 스레드만 사용하여 연산 속도 줄임.
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    int mx = 0; //그림의 최댓값
    int num = 0; //그림의 수

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue; //해당 좌표가 그림이 아니거나 방문을 했을 경우 continue
            num++; //그림의 개수 +1
            queue<pair<int, int>> Q;
            vis[i][j] = 1; //방문했음을 표시
            Q.push({ i,j });
            int area = 0; //그림의 크기
            while (!Q.empty()) { //BFS 시작.
                area++;
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
            mx = max(mx, area);
        }
    }
    
    cout << num << '\n' << mx;
   
}