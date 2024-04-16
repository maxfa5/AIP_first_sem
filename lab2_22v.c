#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  double x11, y11, x12, y12, x21, y21, x22, y22;
  printf(
      "введите координаты крайних точек: x11, y11, x12, y12, x21, x21, x22, "
      "y22: ");
  if(scanf("%lf%lf%lf%lf %lf%lf%lf%lf", &x11, &y11, &x12, &y12, &x21, &y21, &x22,
        &y22)!=8){
          printf("Error input!");
          system("pause");
          exit(1);
        }
  if ((x11 == x21 && y11 == y21 && x12 == x22 && y12 == y22)) {
    printf("Отрезки лежат на одной прямой");
    system("pause");
    exit(1);
  }

  //в случае ввода справо на лево меняем точки местами
  if (x11 > x12 || (x21 > x22)){ 
      double tmp;
      if(x11 > x12 ){
      tmp = x12, x12 = x11, x11 = tmp;
      tmp = y12, y12 = y11, y11 = tmp;
      }
      if (x21 > x22){
     tmp = x22, x22 = x21, x21 = tmp;
     tmp = y22, y22 = y21, y21 = tmp;
    }
  }


  double k1, k2, b1, b2;
  if (x11 - x12 == 0) {
    k1 = 0;
  }

  if (x21 - x22 == 0) {
    k2 = 0;
  }
  k1 = (y11 - y12) / (x11 - x12);
  k2 = (y21 - y22) / (x21 - x22);

  b1 = y12 - k1 * x12;
  b2 = y22 - k2 * x22;
  double peresechenie = (-b2 + b1) / (k2 - k1);

  if (isinf(peresechenie) || isnan(peresechenie)) {
    printf("Точка пересечания отсутсвует");
    system("pause");
    exit(1);
  }
  if (peresechenie >= x11 && peresechenie <= x12 && peresechenie >= x21 &&
      peresechenie <= x22) {
    printf("Точка пересечения отрезков: (%lg; %lg)\n", peresechenie, k1 * peresechenie + b1);
  } else {
    printf("Точка пересечания отсутсвует");
  }
  system("pause");
  return 0;
}