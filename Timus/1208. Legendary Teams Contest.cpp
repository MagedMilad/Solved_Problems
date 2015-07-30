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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

struct team {
	int p1, p2, p3;
	team(int p11, int p22, int p33) {
		p1 = p11;
		p2 = p22;
		p3 = p33;
	}
	team() {
		p1 = p2 = p3 = 0;
	}
};

map<string, int> id;
vvi adj;
vector<team> t;
int top = 0, k, mx = -oo , sum;
vector<bool> vis_team, vis_name;

int get_id(string s) {
	if (id.find(s) == id.end())
		id[s] = top++;
	return id[s];
}

bool ok(int u){
	if(vis_name[t[u].p1])
		return false;
	if(vis_name[t[u].p2])
			return false;
	if(vis_name[t[u].p3])
			return false;
	return true;
}

void set_val(int u , int val){
	vis_name[t[u].p1]=val;
	vis_name[t[u].p2]=val;
	vis_name[t[u].p2]=val;
}

void dfs(int u) {
	mx = max(mx,sum);
	for(int i=0;i<sz(adj[u]);i++){
		int v =  adj[u][i];
		if(!vis_team[v] && ok(v)){
			sum++;
			set_val(v,1);
			dfs(v);
			set_val(v,0);
			sum--;
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> k;
	for (int i = 0; i < k; i++) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		int id1 = get_id(s1);
		int id2 = get_id(s2);
		int id3 = get_id(s3);
		t.push_back(team(id1, id2, id3));
	}
	adj.resize(top + 1);

	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			bool ok = true;
			if (t[i].p1 == t[j].p1 || t[i].p2 == t[j].p2 || t[i].p3 == t[j].p3)
				ok = false;
			if (t[i].p3 == t[j].p1 || t[i].p1 == t[j].p2 || t[i].p2 == t[j].p3)
				ok = false;
			if (t[i].p2 == t[j].p1 || t[i].p3 == t[j].p2 || t[i].p1 == t[j].p3)
				ok = false;
			if (ok) {
				adj[i].push_back(j);
//				adj[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < k; i++) {
		vis_team.assign(k + 1, false);
		vis_name.assign(top + 1, false);
		vis_team[i]=1;
		vis_name[t[i].p1]=1;
		vis_name[t[i].p2]=1;
		vis_name[t[i].p3]=1;
		sum=1;
		dfs(i);
	}
	cout << mx << endl;
	return 0;
}

