#include <stdio.h>
#include <stdlib.h>

int main() {
  int countDigit, sum;
  printf("Введите количество цифр и их сумму: ");
  while ((scanf("%d%d", &countDigit, &sum) != 2 && countDigit < 0 && sum < 0)) {
    printf("Неверный ввод чисел!\n");
    fflush(stdin);
  }

  if ((countDigit * 9) < sum || sum == 0) {
    printf("Чисел с суммой цифр %d и количеством %d не существует\n", sum,
           countDigit);
    system("pause");
    exit(1);
  }

  int i = 0, start = 1, end = 1, count = 0;

  //создание диапозона
  for (i = 1; i < countDigit; i++) {
    start *= 10;
  }
  end = start * 10 - 1;

  //проходим по диапозону и считаем сумму цифр числа
  for (i = start; i <= end; i++) {
    int tmp = i;
    int tmp_sum = 0;
    //нахождение суммы числа
    while (tmp > 0) {
      tmp_sum += tmp % 10;
      tmp = tmp / 10;
    }
    if (tmp_sum == sum) {
      count++;
      printf("Число%6d : %d\n", count, i);
    }
  }
  if (count == 0) {
    printf("Чисел с суммой цифр %d и количеством %d не найденно", sum,
           countDigit);
  }
  system("pause");
  return 0;
}