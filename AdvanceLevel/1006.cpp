#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//have problem
using namespace std;

struct regist{
	string ID;
	string inTime;
	string outTime;
};

vector<regist> reg;


int cmp(const regist &reg1,const regist &reg2) {
	return reg1.inTime < reg2.inTime;
}

int cmp1(const regist &reg1, const regist &reg2) {
	return reg1.outTime > reg2.inTime;
}

int main(int argc, char const *argv[]) {
	int n;
	while (cin >> n) {
		reg.clear();
		for (int i = 0;i < n;i++) {
			regist tmp;
			cin >> tmp.ID >> tmp.inTime >> tmp.outTime;
			reg.push_back(tmp);
		}
		sort(reg.begin(), reg.end(), cmp);
		cout << reg[0].ID << " ";
		sort(reg.begin(), reg.end(), cmp1);
		cout << reg[0].ID << endl;
	}
	return 0;
}
