#include <math.h>
#include <stdio.h>

int main() {
  double x, y, dx, degree, angle;
  double ans, s, ds;
  int count;
  printf(
      "Введите размеры стола (x,y), расстояние от угла до шара (dx) и "
      "значение угла удара в градусах (degree): \n");
  scanf("%lf%lf%lf%lf", &x, &y, &dx, &degree);
  angle = degree * M_PI / 180;
  s = 2 * y / tan(angle);
  count = (int)((s + dx) / x);
  ds = s - count * x + dx;
  ans = x * (count % 2) + pow(-1, count) * ds - dx;
  ans = fabs(ans);
  printf("Мяч ударится на расстоянии  %lf от изначальной позиции\n", ans);
  system("pause");
  return 0;
}