#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string s;
ll ans = 0;
stack<char> st;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  int sz = s.length();
  for (int i = 0; i < sz; i++) {
    if (s[i]=='(')
      st.push(s[i]);
    else {
      if (s[i-1] == '(') { // �������� ���
        st.pop(); // �տ��� ������ �����ϰ� stack�� s[i]�� �־����Ƿ� pop
        ans+=st.size(); // ������ ������ŭ ans�� �߰�
      }
      else { // ������ ���� ���
        st.pop();  // ������ ������ 1 ����
        ans++; // ���� 1���� ���ܵ� �Ͱ� ������ ��Ȳ�̹Ƿ� ans�� 1 �߰�
      }
    }
  }
  cout << ans << "\n";
  return 0;
}