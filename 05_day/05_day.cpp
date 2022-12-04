#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define MOD ((ll)(1e9+7))

#define FILE "demo.in"
//#define FILE "input.in"

void part_1(const string & file);
void part_2(const string & file);
vector<ll> explode(string const & s, char delim);

ll sgn(ll x) {
    return (x > 0) ? 1 : ((x < 0) ? -1 : 0);
}

void part_1(const string & file) {
  ifstream in(file);
  string str;

  map<pair<ll,ll>, ll> m;

  ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  char c;
  while(in >> skipws >> x1 >> c >> y1 >> c >> c >> x2 >> c >> y2) {
    if (x1 != x2 && y1 != y2) continue;
    for(ll i = min(y1, y2); i <= max(y1, y2); ++ i)
      for (ll j = min(x1, x2) ; j <= max(x1, x2); ++ j) 
        m[{j, i}] += 1;
  }

  ll sum = 0;

  for (const auto & [k, v]: m) {
    if (v > 1) sum++;
  }

  cout << "Part 1: " << sum << endl;
}


void part_2(const string & file) {
  ifstream in (file);
  string str;

  map<pair<ll,ll>, ll> m;

  ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  char c;
  while(in >> skipws >> x1 >> c >> y1 >> c >> c >> x2 >> c >> y2) {
    if (x1 == x2 || y1 == y2) {
      for(ll i = min(y1, y2); i <= max(y1, y2); ++ i)
        for (ll j = min(x1, x2) ; j <= max(x1, x2); ++ j) 
          m[{j, i}] += 1;
    } else {
      ll dist = abs(x1 - x2);
      F(dist+1) {
        m[{x1 - (i*sgn(x1-x2)), {y1 - (i*sgn(y1-y2))}}] += 1;
      }
    }
  }

  ll sum = 0;

  for (const auto & [k, v]: m) {
    if (v > 1) sum++;
  }

  cout << "Part 2: " << sum << endl;
}

vector<ll> explode(string const & s, char delim)
{
    vector<ll> res;
    istringstream iss(s);

    for(string token; getline(iss, token, delim);){
      if (token == "x") res.PB(1);
      else res.PB(stoi(token));
    }

    return res;
}

int main(int argc, const char ** argv){
  ios::sync_with_stdio(0);cin.tie(0);
  
  string file = FILE;
  if (argc > 1) {
    file = argv[1];
  }

  part_1(file);
  part_2(file);
  return 0;
}

