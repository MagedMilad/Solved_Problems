#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

#define clr(v, d) memset(v, d, sizeof(v))
#define sz(v) ((int)v.size())

#define N 1300
#define oo 1000000000
int n, m, source, sink;
int G[N][N], F[N][N];
int pi[N];
int CurrentNode[N];
int Queue[N];
int d[N];
int numbs[N];
map<string, int> name;
map<string, int> party;
map<string, int> club;
string str;

void init() {
	clr(G, 0);
	clr(F, 0);
	clr(pi, 0);
	clr(Queue, 0);
	clr(numbs, 0);
	int last = 1;
	source = 0;
	name.clear();
	party.clear();
	club.clear();
	while (getline(cin, str) && sz(str)) {
		stringstream s(str);
		string n, p, c;
		s >> n >> p;
		name[n] = last++;
		if (party.find(p) == party.end())
			party[p] = last++;
		G[name[n]][party[p]] = 1;
		while (s >> c) {
			if (club.find(c) == club.end())
				club[c] = last++;
			G[club[c]][name[n]] = 1;
		}
	}
	sink = last;
	n = last + 1;
	int flow = (sz(club) - 1) / 2;
	for (map<string, int>::iterator it = club.begin(); it != club.end(); it++)
		G[source][it->second] = 1;
	for (map<string, int>::iterator it = party.begin(); it != party.end(); it++)
		G[it->second][sink] = flow;

}

int rev_BFS() {
	int i, j, head(0), tail(0);
	for (i = 0; i < n; i++)
		numbs[d[i] = n]++;
	numbs[n]--;
	d[sink] = 0;
	numbs[0]++;
	Queue[++tail] = sink;
	while (head != tail) {
		i = Queue[++head];
		for (j = 0; j < n; j++) {
			if (d[j] < n || G[j][i] == 0)
				continue;
			Queue[++tail] = j;
			numbs[n]--;
			d[j] = d[i] + 1;
			numbs[d[j]]++;
		}
	}
	return 0;
}

int Augment() {
	int i, j, tmp, width(oo);
	for (i = sink, j = pi[i]; i != source; i = j, j = pi[j]) {
		tmp = G[j][i];
		if (tmp < width)
			width = tmp;
	}
	for (i = sink, j = pi[i]; i != source; i = j, j = pi[j]) {
		G[j][i] -= width;
		F[j][i] += width;
		G[i][j] += width;
		F[i][j] -= width;
	}
	return width;
}

int Retreat(int &i) {
	int tmp;
	int j, mind(n - 1);
	for (j = 0; j < n; j++)
		if (G[i][j] > 0 && d[j] < mind)
			mind = d[j];
	tmp = d[i];
	numbs[d[i]]--;
	d[i] = 1 + mind;
	numbs[d[i]]++;
	if (i != source)
		i = pi[i];
	return numbs[tmp];
}

int find_max_flow() {
	int flow(0), i, j;
	rev_BFS();
	for (i = 0; i < n; i++)
		CurrentNode[i] = 1;
	i = source;
	for (; d[source] < n;) {
		for (j = CurrentNode[i]; j < n; j++)
			if (G[i][j] > 0 && d[i] == d[j] + 1)
				break;
		if (j < n) {
			CurrentNode[i] = j;
			pi[j] = i;
			i = j;
			if (i == sink) {
				flow += Augment();
				i = source;
			}
		} else {
			CurrentNode[i] = 1;
			if (Retreat(i) == 0)
				break;
		}
	}
	return flow;
}

int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	int tc;
	cin >> tc;
	getline(cin, str);
	getline(cin, str);
	while (tc--) {
		init();
		int f = find_max_flow();
		if (f != sz(club)) {
			printf("Impossible.\n");
		} else {
			for (map<string, int>::iterator it1 = club.begin();
					it1 != club.end(); it1++) {
				for (map<string, int>::iterator it2 = name.begin();
						it2 != name.end(); it2++) {
					if (G[name[it2->first]][club[it1->first]]) {
						printf("%s %s\n", it2->first.c_str(),
								it1->first.c_str());
						break;
					}
				}
			}
		}
		if (tc)
			printf("\n");
	}
	return 0;
}
