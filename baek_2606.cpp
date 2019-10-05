#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include<stack>

#define MAX 100

int adj[100][100]; //����Ǿ��ִ� ���� �����ϴ� �����迭

int cnt=0; //������ pc ��
int com[100];
using namespace std;
void dfs(stack<int> &st) {
	int top = st.top();
	for (int i = 0; i < MAX; i++) {
		if (adj[top][i] == 1 && !com[i]) {
			st.push(i);
			adj[top][i] = 0;
			adj[i][top] = 0;
			com[i] = 1;
			cnt++;
			dfs(st);
		}
	}
	st.pop();
}
int main() {
	stack<int> st; //����� �� push
	int c, n;  //��ǻ�� ��, ����Ǿ��ִ� �� ��
	scanf("%d %d", &c, &n);
	for (int i = 0; i < n; i++) {
		int a, b; //��ǻ�� ��ȣ��
		scanf("%d %d", &a, &b);
		adj[a - 1][b - 1] = 1;
		adj[b - 1][a - 1] = 1;
	}
	st.push(0);
	com[0] = 1;
	dfs(st);
	printf("%d", cnt);
	return 0;
}