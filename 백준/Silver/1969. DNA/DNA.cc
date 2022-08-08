#include <bits/stdc++.h>

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;

  string dna[n];
  for(int i = 0; i < n; i++){
    cin >> dna[i];
  }

  int hdist = 0;
  string result;
  for (int i = 0; i < m; i++) {
    map<char, int> count;
    for(int j = 0; j < n; j++) {
      count[dna[j][i]]++;
    }
    char max;
    int max_value = 0;
    for(auto [key, value]: count) {
      if(value > max_value) {
        max = key;
        hdist += max_value;
        max_value = value;
      }
      else {
        hdist += value;
      }
    }
    result.push_back(max);
    
  }

  cout << result << "\n";
  cout << hdist << "\n";
}