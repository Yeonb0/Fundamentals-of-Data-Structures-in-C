// 프로그램 1.16: 행렬의 덧셈
#define MAX_SIZE 100
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols){
  int i, j;
  for(i = 0; i < rows; i++)
    for(j = 0; j < cols; j++)
      c[i][j] = a[i][j] + b[i][j];
}