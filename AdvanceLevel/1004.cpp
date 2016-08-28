#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <string.h>

using namespace std;

#define SIZE 10000

struct node {
	string ID;
	node *child[SIZE];
	node(string id) {
		ID = id;
		memset(child, NULL, sizeof(child));
	}
};

int ans[SIZE];
int n, m;
map<string, node*> dict;



int main(int argc, char const *argv[]) {
	while (cin >> n >> m) {
		dict.clear();

		for (int i = 0;i<m;i++) {
			string id;int k;cin >> id >> k;
			node* temp;
			if (dict.count(id)) {
				temp = dict[id];
			}
			else {
				temp = new node(id);
				dict[id] = temp;
			}

			for (int j = 0;j < k;j++) {
				string subId;cin >> subId;
				if (dict.count(subId)) {
					temp->child[j] = dict[subId];
				}
				else {
					temp->child[j] = new node(subId);
					dict[subId] = temp->child[j];
				}
			}
		}

		queue<node*> q;
		q.push(dict["01"]);

		int floor = 0;
		int limit = 1;
		int curCount = 0;
		int counter = 0;

		while (!q.empty()) {
			node* cur = q.front();
			q.pop();
			counter++;
			for (int i = 0;cur->child[i] != NULL;i++) {
				if (cur->child[i] == NULL) {
					++ans[floor];
				}
				else {
					q.push(cur->child[i]);
					++curCount;
				}
			}

			if (cur->child[0] == NULL) {
				++ans[floor];
			}

			if (counter == limit) {
				counter = 0;
				limit = curCount;
				curCount = 0;
				++floor;
			}
		}
		for (int i = 0;i < floor - 1;i++) {
			cout << ans[i] << " ";
		}
		cout << ans[floor - 1] << endl;
	}
	return 0;
}
