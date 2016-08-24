#include <iostream>
#include<cstdio>
using namespace std;

#define SIZE 1001

double a[SIZE], b[SIZE];

int main(int argc, char const *argv[]) {
	int n;cin >> n;
	for (int i = 0;i<n;i++) {
		int k; double v;
		cin >> k >> v;
		a[k] = v;
	}
	cin >> n;
	for (int i = 0;i<n;i++) {
		int k; double v;
		cin >> k >> v;
		b[k] = v;
	}
	int ans = 0;
	for (int i = 0;i<SIZE;i++) {
		a[i] += b[i];
		if (a[i]) {
			ans++;
		}
	}
	cout << ans;
	for (int i = SIZE - 1;i >= 0;i--) {
		if (a[i]) {
			printf(" %d %.1lf", i, a[i]);
		}
	}
	return 0;
}
