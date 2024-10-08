#define MAX_TERMS 101
#include <stdio.h>
typedef struct {
  int row;
  int col;
  int value;
} term;

// 프로그램 2.11 : storeSum 함수
void storeSum(term d[], int *totalD, int row, int column, int *sum){
  // *sum != 0 이면, 그 행 및 열 위치와 함께 행렬 d의 *totalD+1 원소에 저장
  if (*sum){
    if (*totalD < MAX_TERMS){
      d[++*totalD].row = row;
      d[*totalD].col = column;
      d[*totalD].value = *sum;
      *sum = 0;
    } else {
      fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
      exit(1);
    }
  }
}