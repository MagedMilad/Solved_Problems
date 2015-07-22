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

#define N 1050
#define oo 1000000000
#define clr(v, d) memset(v, d, sizeof(v))


int n, m, source, sink;

int G[N][N], F[N][N];

int pi[N];
int CurrentNode[N];

int Queue[N];

int d[N];
int numbs[N];

int nk, np , flow=0;
void init() {
	flow = 0;
	for(int i=0;i<1025;i++){
		pi[i]=0;
		CurrentNode[i]=0;
		Queue[i]=0;
		d[i]=0;
		numbs[i]=0;
		for(int j=0;j<1025;j++)
			G[i][j]=0;
	}
	for (int i = 1; i <= nk; i++)
		cin >> G[source][i] , flow +=G[source][i];
	for (int i = nk + 1; i <= nk + np; i++) {
		int size;
		cin >> size;
		for (int j = 0; j < size; j++) {
			int c;
			cin >> c;
			G[c][i] = 1;
		}
		G[i][sink] = 1;
	}
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

// Main
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
		}
		else {
			CurrentNode[i] = 1;

			if (Retreat(i) == 0)
				break;

		}

	}

	return flow;
}

int main() {
//	freopen("in.txt", "r", stdin);
	while (cin >> nk >> np) {
		if (np == 0 && nk == 0)
			break;
		source = 0;
		sink = np + nk + 1;
		n = sink + 1;
		init();
		int ans = find_max_flow();
		if (ans == flow) {
			printf("1\n");
			for (int i = 1; i <= nk; i++) {
				int size = G[i][source];
				for (int j = nk+1; j <= nk+np; j++) {
					if (F[i][j] && G[j][i]) {
						printf("%d", j-nk);
						size--;
						if (size)
							printf(" ");
					}
				}
				printf("\n");
			}
		} else
			printf("0\n");
	}

	return 0;
}
