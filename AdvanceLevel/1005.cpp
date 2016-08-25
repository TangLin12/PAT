#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

#define SIZE 505

string num[10] = { "zero","one","two","three","four","five","six","seven","eight","nine"};

string n;

void solve() {
  int ans=0;
  for(int i=0;i<n.length();i++){
    ans+=(n[i]-'0');
  }
  if(ans==0){
    cout<<num[0]<<endl;
  }else{
    stack<int> s;
    while(ans){
      s.push(ans%10);
      ans/=10;
    }
    cout<<num[s.top()];
    s.pop();
    while(!s.empty()){
      cout<<" "<<num[s.top()];
      s.pop();
    }
    cout<<endl;
  }
}

int main(int argc, char const *argv[]) {
	while (cin >> n) {
		solve();
	}
	return 0;
}
