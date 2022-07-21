#include <iostream>
#include <cmath>

bool is_coprime(int x, int y) { // 서로소이면 true, 아니면 false를 반환하는 함수
  int min;
  if (x >= y) {
    min = y;
  } else {
    min = x;
  }
  for (int i = 2; i <= min; i++) {
    if (x % i == 0 && y % i == 0) {
      return false;
    }
  }
  return true;
}

int main_() {
  int gcd, lcm;
  std::cin >> gcd >> lcm;
  int mult = lcm / gcd;
  int a;
  for (int i = 1; i <= sqrt(mult); i++) {
    if (mult % i == 0 && is_coprime(i, mult/i)) {
      a = i;
    }
  }
  std::cout << a*gcd << " " << mult/a*gcd << "\n";
}