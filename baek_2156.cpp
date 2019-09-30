#include<iostream>
using namespace std;


int findMax(int a, int b, int c) {
	if (a > b && a > c)
		return a;
	else if (b > a && b > c)
		return b;
	else 
		return c;
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int* dp = new int[n];
	for (int i = 0; i < n; i++) {
		if (i == 0)
			dp[i] = a[i];
		else if (i == 1)
			dp[i] = a[i - 1] + a[i];
		else if (i == 2)
			dp[i] = findMax(dp[i - 1], a[i] + dp[i - 2], a[i - 1] + a[i]);
		else 
			dp[i] = findMax(dp[i - 1], a[i] + dp[i - 2], a[i] + a[i - 1] + dp[i - 3]);
	}
	cout << dp[n - 1];
	return 0;
}