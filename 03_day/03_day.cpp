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

ll toRemove(ll i, ll j) {
  if (j < i) return 1;
  return 0;
}

void part_1(const string & file) {
  ifstream in(file);
  vector<string> strs;
  string str;

  while (in >> str) {
    strs.emplace_back(str);
  }

  ll size = str.length(), gamma = 0, epsilon = 0;
  
  FOR(j,0,size) {
    ll b[2] = {0,0};
    FOR(i,0,strs.size()) b[strs[i][j] - '0'] ++;
    if (b[0] < b[1]) gamma += 1; 
    else epsilon += 1;
    gamma <<= 1;
    epsilon <<= 1;
  }

  cout << "Part 1: " << (gamma>>1)*(epsilon>>1) << endl;
}


void part_2(const string & file) {
  ifstream in (file);
  vector<string> oxygen, scrubber;
  string str;

  while (in >> str) {
    oxygen.emplace_back(str);
    scrubber.emplace_back(str);
  }

  ll size = str.length();
  
  FOR(j,0,size) {
    ll b[2] = {0,0};
    FOR(i,0,oxygen.size()) b[oxygen[i][j]-'0'] ++;
    oxygen.erase(remove_if(oxygen.begin(), oxygen.end(), [j, b](const string & i) { return i[j] == toRemove(b[0], b[1]) + '0';}), oxygen.end());
    if (oxygen.size() == 1) break;
  }

  FOR(j,0,size) {
    ll b[2] = {0,0};
    FOR(i,0,scrubber.size()) b[scrubber[i][j] - '0'] ++;
    scrubber.erase(remove_if(scrubber.begin(), scrubber.end(), [j, b](const string & i) { return i[j] == !toRemove(b[0], b[1]) + '0';}), scrubber.end());
    if (scrubber.size() == 1) break;
  }

  ll ox = 0, scr = 0;
  FOR(i, 0, size) {
    ox += oxygen[0][i] - '0';
    scr += scrubber[0][i] - '0';
    ox <<= 1;
    scr <<= 1;
  }
  cout << "Part 2: " << (ox>>1) * (scr>>1) << endl;
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
