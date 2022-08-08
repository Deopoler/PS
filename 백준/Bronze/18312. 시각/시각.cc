#include <bits/stdc++.h>

using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  int count = 0;
  for (int h = 0; h <= n; h++) {
    for(int m1 = 0; m1 < 6; m1++) {
      for(int m2 = 0; m2 < 10; m2++) {
        for(int s1 = 0; s1 < 6; s1++) {
          for(int s2= 0; s2 < 10; s2++) {
            if((h/10==k || h%10==k || m1==k || m2 ==k || s1==k || s2 == k)) count ++;
          }
        }
      }
    }
  }

  cout << count << "\n";
}