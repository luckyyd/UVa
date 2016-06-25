#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int cas;
	while (cin >> cas) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool isStack = true, isQueue = true, isPQ = true;
		while (cas > 0) {
			cas--;
			int op, num;
			cin >> op >> num;
			if (op == 1) {
				s.push(num);
				q.push(num);
				pq.push(num);
			}
			else if (op == 2) {
				if (s.empty() || (!s.empty() && s.top() != num)) {
					isStack = false;
				}
				else {
					s.pop();
				}
				if (q.empty() || (!q.empty() && q.front() != num)) {
					isQueue = false;
				}
				else {
					q.pop();
				}
				if (pq.empty() || (!pq.empty() && pq.top() != num)) {
					isPQ = false;
				}
				else {
					pq.pop();
				}
			}
		}
		if (isStack && (!isQueue && !isPQ)) {
			cout << "stack" << endl;
		}
		else if (isQueue && (!isStack && !isPQ)) {
			cout << "queue" << endl;
		}
		else if (isPQ && (!isStack && !isQueue)) {
			cout << "priority queue" << endl;
		}
		else if (!isPQ && !isStack && !isQueue) {
			cout << "impossible" << endl;
		}
		else {
			cout << "not sure" << endl;
		}
	}
    return 0;
}
