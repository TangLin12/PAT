#include <iostream>
#include <vector>

using namespace std;

#define SIZE 505
#define MAX 1000000

int n, m, startPoint, endPoint;
int team[SIZE];
vector<int> path;
int numPath, minPath, maxTeam;
int map[SIZE][SIZE];
int vis[SIZE];

void DFS(int now) {
  if (now == endPoint) {
    int curTeam = 0, curPath = 0;
    for (int i = 0;i<path.size();i++) {
      curTeam += team[path[i]];
    }
    for (int i = 0;i<path.size() - 1;i++) {
      curPath += map[path[i]][path[i + 1]];
    }
    if (curPath<minPath) {
      numPath = 1;
      minPath = curPath;
      maxTeam = curTeam;
    }
    else if (curPath == minPath) {
      numPath++;
      if (curTeam>maxTeam) {
        maxTeam = curTeam;
      }
    }
  }

  for (int i = 0;i<n;i++) {
    if (map[now][i] != -1) {
      if (!vis[i]) {
        vis[i] = 1;
        path.push_back(i);
        DFS(i);
        path.pop_back();
        vis[i] = 0;
      }
    }
  }
}

void solve() {
  for (int i = 0;i<n;i++) {
    for (int j = 0;j<n;j++) {
      map[i][j] = -1;
    }
  }

  for (int i = 0;i<n;i++) {
    cin >> team[i];
  }
  int a, b, l;
  for (int i = 0;i<m;i++) {
    cin >> a >> b >> l;
    map[a][b] = map[b][a] = l;
  }

  path.clear();
  numPath = 0;
  minPath = MAX;
  maxTeam = -1;

  vis[startPoint] = 1;
  path.push_back(startPoint);
  DFS(startPoint);

  path.pop_back();
  vis[startPoint] = 0;

  cout << numPath << " " << maxTeam << endl;
}

int main(int argc, char const *argv[]) {
  while (cin >> n >> m >> startPoint >> endPoint) {
    solve();
  }
  return 0;
}
