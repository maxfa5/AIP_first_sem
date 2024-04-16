#include <math.h>
#include <stdio.h>

int main() {
  double x, angle, answer;
  printf("Введите угол от 0 до Pi/4\n");
  scanf("%lf", &angle);
  printf("Ошибка для функции cos(x) = %lg",
         cos(angle) - (1 - (angle * angle / 2) - (pow(angle, 4) / 4)));
  system("pause");
  return 0;
}