#include <iostream>

using namespace std;

int n;int now;
int cur;int time;

int main(int argc, char const *argv[]) {
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin>>cur;
      time+=(cur>now)? (cur-now)*6:(now-cur)*4;
    }
    time+=n*5;
    cout<<time<<endl;
  }
  return 0;
}
