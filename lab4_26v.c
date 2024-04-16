#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE  6084 /* 4056 + 2028 */

int main() {
  int N = 0, lenght_of_group = 0;
  printf("Введите размер массива от 0 до %d: ", MAX_ARRAY_SIZE);
  while ((scanf("%d", &N) != 1) || N < 0 || N > MAX_ARRAY_SIZE) {
    printf("Неверный ввод чисел!\n");
    printf("Введите размер массиваот 0 до %d: ", MAX_ARRAY_SIZE);
    fflush(stdin);
    scanf("%*[^\r\n]");
  }
  int arr[MAX_ARRAY_SIZE] = {0};
  int i;
  for (i = 0; i < N; i++) {
    scanf("%*[^\r\n]");
    printf("Введите значение для эллемента arr[%d]: ", i);
    while (scanf("%d", (arr + i)) != 1) {
      scanf("%*[^\r\n]");
      printf("Неверный ввод чисел!\n");
      printf("Введите значение для эллемента arr[%d]: ", i);
      fflush(stdin);
    }
  }

  printf("Введите размер группы: ");
  scanf("%*[^\r\n]");
  while ((scanf("%d", &lenght_of_group) != 1 || lenght_of_group > 15  || lenght_of_group < 2)) {
    printf("Неверный ввод чисел!\n");
    printf("Введите размер группы от 2 до 15: ");
    fflush(stdin);
    scanf("%*[^\r\n]");
  }
  int res_arr_size, offset = 0, flag_small_array = 0;
  if (lenght_of_group > N) { /*вычисление размера итогового массива*/
    res_arr_size = lenght_of_group + 1;
    flag_small_array++;
  } else {
    res_arr_size = N + N / lenght_of_group + (N % lenght_of_group);
  }

  for (i = lenght_of_group; i <= res_arr_size; i += lenght_of_group + 1) {
    int obj = 0;
    int j, nod = arr[i - 1];
    for (j = i - lenght_of_group; j < i - 1; j++) { /* Нахождение НОДа*/
      int tmp_a = arr[j];
      while (nod && tmp_a && nod % tmp_a != 0) {
        if (tmp_a > nod) {
          int tmp = nod;
          nod = tmp_a;
          tmp_a = tmp;
        }
        int tmp = nod - tmp_a;
        nod = tmp_a;
        tmp_a = tmp;
      }
      nod = tmp_a;
    }
    obj = nod;
    offset++;
    for (j = N + offset; j > i; j--) { /*смещение массива */
      arr[j] = arr[j - 1];
    }
    arr[j] = obj; /*вставка НОД в конец группы*/
  }

  int count = 0;
  for (i = 0; i < res_arr_size; i++) {
    printf("%d\n", arr[i]);
    count++;
    if (count == lenght_of_group + 1) {
      printf("________\n");
      count = 0;
    }
  }
  printf("вывод окончен\n");
  system("pause");
  return 0;
}