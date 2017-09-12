#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Student {
	string name;
	string cId;
	int grade;
};

int main() {
	int n; cin >> n;
	vector<Student*> ar(101);
	for (int i = 0; i < n; i++) {
		Student s;
		cin >> s.name >> s.cId >> s.grade;
		ar[s.grade] = new Student(s);
	}

	int downB, upB; cin >> downB >> upB;
	bool printFlag = true;
	for (int i = min(100, upB); i >= max(0, downB); i--) {
		if (ar[i] != NULL) {
			printFlag = false;
			cout << ar[i]->name << " " << ar[i]->cId << "1\n";
		}
	}
	if (printFlag) {
		cout << "NONE" << endl;
	}
	system("PAUSE");
	return 0;
}