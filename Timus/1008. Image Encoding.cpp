//============================================================================
// Name        : Practice.cpp
// author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

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

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > grix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1000000007;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define clr(v, d) memset(v, d, sizeof(v))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).real(),(a).imag())
#define angle(a) atan2((a).imag() , (a).real())
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(v,m) (conj((v)/(m))*m)
#define dist(a,b) (sqrt(pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0)))
//#define distsqr(a,b) (((a)*(conj(a))).real())
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

bool a[50][50];

bool ok(int x , int y){
	 return x > 0 && x <= 10 && y > 0 && y <= 10 ;
}


void solve1(ii p) {
	printf("%d %d\n",p.first,p.second);
	queue<ii> q;
	q.push(p);
	a[p.first][p.second] = 0;
	while (!q.empty()) {
		ii cur = q.front();
		q.pop();
		if (ok(cur.first+1 , cur.second) && a[cur.first + 1][cur.second]) {
			q.push(ii(cur.first + 1, cur.second));
			a[cur.first + 1][cur.second] = 0;
			printf("R");
		}
		if (ok(cur.first , cur.second+1) && a[cur.first][cur.second + 1]) {
			q.push(ii(cur.first, cur.second + 1));
			a[cur.first][cur.second + 1] = 0;
			printf("T");
		}

		if (ok(cur.first-1 , cur.second) && a[cur.first - 1][cur.second]) {
			q.push(ii(cur.first - 1, cur.second));
			a[cur.first - 1][cur.second] = 0;
			printf("L");
		}
		if (ok(cur.first , cur.second-1) && a[cur.first][cur.second - 1]) {
			q.push(ii(cur.first, cur.second - 1));
			a[cur.first][cur.second - 1] = 0;
			printf("B");
		}
		if ((int)q.size())
			printf(",\n");
		else
			printf(".\n");
	}
}

void solve2(ii p) {
	vector<ii> sol;
	sol.push_back(p);
	queue<ii> q;
	q.push(p);

	while (!q.empty()) {
		ii cur = q.front();
		q.pop();
		string str;
		getline(cin, str);
		char dir;
		ss s(str);
		while (s >> dir) {
			if (dir == '.' || dir == '.')
				break;
			if (dir == 'R') {
				sol.push_back(ii(cur.first + 1, cur.second));
				q.push(ii(cur.first + 1, cur.second));
			}
			if (dir == 'T') {
				sol.push_back(ii(cur.first, cur.second+1));
				q.push(ii(cur.first, cur.second+1));
			}
			if (dir == 'L') {
				sol.push_back(ii(cur.first - 1, cur.second));
				q.push(ii(cur.first - 1, cur.second));
			}
			if (dir == 'B') {
				sol.push_back(ii(cur.first , cur.second-1));
				q.push(ii(cur.first, cur.second-1));
			}
		}
	}
	sort(all(sol));
	printf("%d\n",sz(sol));;
	for(int i=0;i<sz(sol);i++){
		printf("%d %d\n",sol[i].first,sol[i].second);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	string str;
	getline(cin,str);
	ss s(str);
	int x,y;
	s>>x;
	if(s>>y){
		solve2(ii(x,y));
		return 0;
	}
	int n = x;
	ii p;
	for(int i=0;i<n;i++){
		cin>>x>>y;

		if(i==0)
			p=ii(x,y);
		a[x][y]=1;
	}
	solve1(p);
	return 0;
}


















