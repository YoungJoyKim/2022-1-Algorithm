#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
int board[502][502];

bool vis[502][502]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
int n , m ; // n = ���� ��, m = ���� ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�

int main(void) {

    ios::sync_with_stdio(false); //iostream�� stdio�� ���۸� ����ȭ��Ű�°� false�� �ٲ㼭, �̱� �����常 ����Ͽ� ���� �ӵ� ����.
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    int mx = 0; //�׸��� �ִ�
    int num = 0; //�׸��� ��

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue; //�ش� ��ǥ�� �׸��� �ƴϰų� �湮�� ���� ��� continue
            num++; //�׸��� ���� +1
            queue<pair<int, int>> Q;
            vis[i][j] = 1; //�湮������ ǥ��
            Q.push({ i,j });
            int area = 0; //�׸��� ũ��
            while (!Q.empty()) { //BFS ����.
                area++;
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
                    Q.push({ nx,ny });
                }

            }
            mx = max(mx, area);
        }
    }
    
    cout << num << '\n' << mx;
   
}