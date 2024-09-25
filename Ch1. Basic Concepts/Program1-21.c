// 프로그램 1.21: 행렬의 곱셈 함수
#define MAX_SIZE 100
void prod(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols, int cols2){
  int i, j, k;
  for(i = 0; i < rows; i++)
    for(j = 0; j < cols2; j++){
      c[i][j] = 0;
      for(k = 0; k < cols; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
}