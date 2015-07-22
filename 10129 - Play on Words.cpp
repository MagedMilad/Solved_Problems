//============================================================================
// Name        : Practice.cpp
// Author      :
// Version     :
// Copyri   :
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
typedef pair<ll, ll> ii;
typedef vector<vector<ii> > vii;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > grix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = (ll) 1e9 + 1;
const double eps = 1e-9;
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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int parent[30], in[30], out[30];

void init() {
	for (int i = 0; i < 30; i++)
		parent[i] = i, in[i] = 0, out[i] = 0;
}

int find(int i) {
	if (parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
}

bool union_find(int u, int v) {
	int ru = find(u);
	int rv = find(v);
	if (ru == rv)
		return false;
	parent[ru] = rv;
	return true;
}

int main() {
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
	int t;
	cin >> t;
	while (t--) {
		init();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			int u = s[0] - 'a';
			int v = s[sz(s) - 1] - 'a';
			out[u]++;
			in[v]++;
			union_find(u, v);
		}
		int roots = 0;
		for (int i = 0; i < 30; i++) {
			if (in[i] + out[i] && parent[i] == i)
				roots++;
		}
		bool ok = true;
		if(roots > 1)
			ok = false;
		int start=0 , end=0;
		for(int i=0;i<30 && ok;i++){
			if(in[i]!=out[i]){
				if(in[i]+1 == out[i])
					start++;
				else if(out[i]+1 == in[i])
					end++;
				else{
					ok=false;
					break;
				}
			}
		}
		if(start && end && start+end > 2)
			ok = false;
		if(ok)
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}

















