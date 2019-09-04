#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;


bool check(double x, double y, double c, double target) {
  
  if(x <= target || y <= target) return true;
  double left_x = c * target / pow(x * x - target * target, 0.5);
  double left_y = c * target / pow(y * y - target * target, 0.5); 
  
  //printf("left : %lf, right : %lf\n", left_x, left_y);
  if(left_x + left_y >= target) {
    return true;
  } else {
    return false;
  }
}

int main() {
  double x, y, c;
  scanf("%lf %lf %lf", &x, &y, &c);


  double left = 0.0;
  double right = max(x, y);
  double answer = 0.0;
  while(left <= right) {
    double mid = (left + right) / 2.0;
    //printf("lmr : %lf, %lf, %lf\n", left, mid, right);
    if(check(x, y, c, mid)) {
      right = mid - 0.00001;
      answer = mid;
    } else {
      left = mid + 0.00001;
    }
  }

  printf("%.3lf", answer);
}