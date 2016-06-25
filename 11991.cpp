// 11991.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int len, query;
	while (cin >> len >> query) {
		map<int, vector<int>> m;
		for (int i = 1; i <= len; i++) {
			int num;
			cin >> num;
			if (m.find(num) == m.end()) {
				vector<int> v = { i };
				m.insert(make_pair(num, v));
			}
			else {
				m.find(num)->second.push_back(i);
			}
		}
		for (int j = 0; j < query; j++) {
			int k, v;
			cin >> k >> v;
			if (m.find(v) != m.end()) {
				if (m.find(v)->second.size() >= k) {
					cout << m.find(v)->second[k - 1] << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	
	//system("pause");
    return 0;
}


