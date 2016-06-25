// 11997.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item {
	int s, b;
	Item(int s, int b) : s(s), b(b) {}
	bool operator < (const Item& rhs) const {
		return s > rhs.s;
	}
};

void merge(int* A, int* B, int* C, int n) {
	priority_queue<Item> q;
	for (int i = 0; i < n; i++) {
		q.push(Item(A[i] + B[0], 0));
	}
	for (int i = 0; i < n; i++) {
		Item item = q.top();
		q.pop();
		C[i] = item.s;
		int b = item.b;
		if (b + 1 < n) {
			q.push(Item(item.s - B[b] + B[b + 1], b + 1));
		}
	}
}

int main()
{
	int k;
	const int maxn = 765;
	while (cin >> k) {
		int arr[maxn][maxn];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				cin >> arr[i][j];
			}
			sort(arr[i], arr[i] + k);
		}
		for (int i = 1; i < k; i++) {
			merge(arr[0], arr[i], arr[0], k);
		}

		cout << arr[0][0];
		for (int i = 1; i < k; i++) {
			cout << " ";
			cout << arr[0][i];
		}
		cout << endl;
		//system("pause");
		
	}
	return 0;
}



