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
ll space(const string& str);
set<ll> checkRows(const vector<vector<vector<ll>>> & v, const set<ll> & exclude);
set<ll> checkColumns(const vector<vector<vector<ll>>> & v, const set<ll> & exclude);
ll count(const vector<vector<vector<ll>>> & v, ll board);

void part_1(const string & file) {
  ifstream in(file);
  string str;

  vector<vector<vector<ll>>> boards;
  getline(in, str);
  vector<ll> bingo = explode(str, ',');
  in.ignore(1, '\n');

  vector<vector<ll>> tmp;
  while(getline(in, str)) {
    if (str.length() == 0) {
      boards.push_back(tmp);
      tmp.clear();
      continue;
    }
    vector<ll> line = explode(str, ' ');
    tmp.emplace_back(std::move(line));
  }

  ll res = 0, last = 0;
  for(const auto & num: bingo) {
    last = num;
    FOR(i, 0, boards.size()) {
      FOR(j, 0, boards[i].size()) {
        FOR (l, 0, boards[i][j].size()) {
          if (boards[i][j][l] == num) {
            boards[i][j][l] = -1;
          }
        }
      }
    }

    set<ll> rows = checkRows(boards, {});
    set<ll> columns = checkColumns(boards, {});
    rows.insert(columns.begin(), columns.end());

    if (rows.size() > 0) {
      ll board = *rows.begin();
      res = count(boards, board);
      break;
    }
  }

  cout << "Part 1: " << last * res << endl;
}


void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<vector<vector<ll>>> boards;
  getline(in, str);
  vector<ll> bingo = explode(str, ',');
  in.ignore(1, '\n');

  vector<vector<ll>> tmp;
  while(getline(in, str)) {
    if (str.length() == 0) {
      boards.push_back(tmp);
      tmp.clear();
      continue;
    }
    vector<ll> line = explode(str, ' ');
    tmp.emplace_back(std::move(line));
  }

  ll res = 0, last = 0;
  set<ll> exclude;
  for(const auto & num: bingo) {
    last = num;
    FOR(i, 0, boards.size()) {
      FOR(j, 0, boards[i].size()) {
        FOR (l, 0, boards[i][j].size()) {
          if (boards[i][j][l] == num) {
            boards[i][j][l] = -1;
          }
        }
      }
    }

    set<ll> rows = checkRows(boards, exclude);
    set<ll> columns = checkColumns(boards, exclude);
    rows.insert(columns.begin(), columns.end());

    bool found = false;
    for(auto & ex: rows) {
      exclude.insert(ex);

      if (exclude.size() == boards.size()) {
        res = count(boards, ex);
        found = true;
        break;
      }
    }
    if (found) break;
  }

  cout << "Part 2: " << res * last << endl;
}

vector<ll> explode(string const & s, char delim)
{
    vector<ll> res;
    istringstream iss(s);

    for(string token; getline(iss, token, delim);){
      if (token.length() == 0 || space(token) >= 1) continue;
      res.PB(stoi(token));
    }

    return res;
}

set<ll> checkRows(const vector<vector<vector<ll>>> & v, const set<ll> & exclude) {
  set<ll> res;
  FOR(i, 0, v.size()) {
    if (exclude.count(i)) continue;
    FOR(j, 0, v[i].size()) {
      bool bingo = true;
      FOR(l, 0, v[i][j].size()) 
        if (v[i][j][l] != -1) { bingo = false; break; }
      if (bingo) res.insert(i);
    }
  }
  return res;
}

set<ll> checkColumns(const vector<vector<vector<ll>>> & v, const set<ll> & exclude) {
  set<ll> res;
  FOR(i, 0, v.size()) {
    if (exclude.count(i)) continue;
    FOR(j, 0, v[i].size()) {
      bool bingo = true;
      FOR(l, 0, v[i][j].size()) 
        if (v[i][l][j] != -1) { bingo = false; break; }
      if (bingo) res.insert(i);
    }
  }
  return res;
}

ll count(const vector<vector<vector<ll>>> & v, ll board) {
  ll cnt = 0;
    FOR(j, 0, v[board].size()) 
      FOR(l, 0, v[board][j].size()) 
        if (v[board][j][l] != -1) cnt += v[board][j][l];
  return cnt;
}


ll space(const string& str)
{
    ll count = 0;
    ll length = str.length();
    FOR(i, 0, length)
      if (isspace(str[i])) count++;
    return count;
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

