#include <stdio.h>
#include <stdlib.h>

int main(){
  // 프로그램 1.1: 메모리의 할당과 반환
  int i, *pi;
  float f, *pf;
  pi = (int *)malloc(sizeof(int));
  pf = (float *)malloc(sizeof(float));
  *pi = 1024;
  *pf = 3.14;
  printf("an integer = %d, a float = %f\n", *pi, *pf);
  free(pi);
  free(pf);

  return 0;
}