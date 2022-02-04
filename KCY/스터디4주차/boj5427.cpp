#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
//string board[1002];
int board[1002][1002];
int dist1[1002][1002]; // ���� ���� �ð�
int dist2[1002][1002]; // ������� �̵� �ð�
int n, m, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for (int tcase = 0; tcase < k; tcase++) {
        bool escape = false;

        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            fill(dist1[i], dist1[i] + m, -1);
            fill(dist2[i], dist2[i] + m, -1);
        }
        /*for (int i = 0; i < n; i++)
            cin >> board[i];*/
        queue<pair<int, int> > Q1;
        queue<pair<int, int> > Q2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                switch (ch)
                {
                case '#':
                    board[i][j] = 1;
                    break;
                case '*':
                    Q1.push({ i,j });
                    dist1[i][j] = 0;
                    break;
                case '@':
                    Q2.push({ i,j });
                    dist2[i][j] = 0;
                    break;
                default:
                    board[i][j] = 0; break;
                }
            }
        }

        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < m; j++) {
        //        cout << board[i][j] << ' ';
        //    }
        //    cout << '\n';
        //}


        // �ҿ� ���� BFS
        while (!Q1.empty()) {
            auto cur = Q1.front();
            Q1.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //������ �����
                if (dist1[nx][ny] >= 0 || board[nx][ny] == 1) continue; //�̹� �湮�߰ų� ���̸�
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q1.push({ nx,ny });
            }
        }

        // ����̿� ���� BFS
        while (!Q2.empty() && (!escape)) {
            auto cur = Q2.front();
            Q2.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // ������ ����ٴ� ���� Ż�⿡ �����ߴٴ� �ǹ�. ť�� �Ÿ� ������ ���Ƿ� ���ʿ� Ż���� �ð��� ����ϸ� ��.
                    cout << dist2[cur.X][cur.Y] + 1 << '\n';
                    escape = true;
                    //return 0;
                    break;
                }
                if (dist2[nx][ny] >= 0 || board[nx][ny] == 1) continue; //�̹� �湮�߰ų� ���̸�
                if (dist1[nx][ny] != 0 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue; // ���� ���� �ð��� ���ǿ� �߰�
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q2.push({ nx,ny });
            }
        }
        if (!escape) cout << "IMPOSSIBLE" << '\n'; // ���⿡ �����ߴٴ� ���� Ż�⿡ ���������� �ǹ�.
    }


}