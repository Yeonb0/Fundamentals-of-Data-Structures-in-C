#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1001

// 프로그램 1.25: 보다 정확한 선택 정렬 함수의 시간 측정 프로그램
void main(){
  int i, n, step = 10;
  int a[MAX_SIZE];
  double duration;

  // times for n = 0, 10, ..., 100, 200, ..., 1000
  printf("    n    repetitions    time\n");
  for(n = 0; n <= 1000; n += step){  // get time for size n
    //get time for size n
    long repetitions = 0;
    clock_t start = clock();
    do{
      repetitions++;

      // initialize with worth-case data
      for(i = 0; i < n; i++)
        a[i] = n - i;
      sort(a, n);
    } while(clock() - start < 1000);
    // repeat until enough time has elapsed
    duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("%6d   %9d   %f\n", n, repetitions, duration);
    if(n == 100) step = 100;
  }
}