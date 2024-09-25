#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1001

// 프로그램 1.24: 선택 정렬 함수의 첫 번째 시간 측정 프로그램
void main(){
  int i, n, step = 10;
  int a[MAX_SIZE];
  double duration;
  clock_t start;

  // times for n = 0, 10, ..., 100, 200, ..., 1000
  printf("    n    time\n");
  for(n = 0; n <= 1000; n += step){  // get time for size n

    // initialize with worth-case data
    for(i = 0; i < n; i++)
      a[i] = n - i;  

    start = clock();
    sort(a, n);
    duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("%5d %f\n", n, duration);
    if(n == 100) step = 100;
  }
}