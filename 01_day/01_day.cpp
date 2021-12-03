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

// #define FILE "demo.in"
#define FILE "input.in"

void part_1(const string & file);
void part_2(const string & file);
vector<ll> explode(string const & s, char delim);

void part_1(const string & file) {
  ifstream in(file);

  ll i = 0, j = -1, cnt = 0;
  while (in >> i) {
    if (j != -1 && i > j) {
      cnt ++;
    }
    j = i;
  }

  cout << "Part 1: " << cnt << endl;
}


void part_2(const string & file) {
  ifstream in (file);

  ll x[3], i = 0, j = 0, sum = 0, cnt = 0;
  in >> x[0] >> x[1] >> x[2];
  sum = x[0] + x[1] + x[2];
  while (in >> j) {
    if (sum-x[i%3]+j > sum) {
      cnt ++;
    }

    x[(i++)%3] = j;
  }


  cout << "Part 2: " << cnt << endl;
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

