#include<bits/stdc++.h>
using namespace std;

void dfs(vector< vector<int> > &graph, vector<int> & visited,  int x, int &cnt ) {
	visited[x] = 1;
	cnt++;
	for ( auto it : graph[x]) {
		if (visited[it]) continue;
		dfs(graph, visited, it , cnt );
	}
}

long long templeRun( vector< pair<int, int>  > &edges, int n, int e, long long x, long long y) {
	if ( x <= y) {
		return x * n;
	}

	vector< vector<int > >  graph;
	graph.resize(n + 1);
	int noOfComponents = 0;
	for (int i = 0; i < e; i++) {
		int a = edges[i].first;
		int b = edges[i].second;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> sizeOfComponent, visited(n + 1);
	for ( int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			int cnt = 0;
			dfs(graph , visited, i, cnt);
			noOfComponents++;
			sizeOfComponent.push_back(cnt);
		}
	}
	long long ans = 0;
	for ( auto it : sizeOfComponent) {
		ans = ans + x + (y * (it - 1));
	}
	return ans ;

}
int main() {
	int n, e, x, y, a, b, tests;
	cin >> tests;
	while (tests--) {
		cin >> n >> e  >> x >> y;

		vector< pair<int, int> > edges;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			edges.push_back({a, b});
		}

		long long ans = templeRun(edges, n, e, x, y);
		cout << ans << endl;

	}
}
