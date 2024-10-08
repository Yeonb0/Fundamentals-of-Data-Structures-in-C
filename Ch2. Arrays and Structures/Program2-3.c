// 프로그램 2.3: 2차원 배열을 동적으로 생성
int** make2dArray(int rows, int cols){
  // rows x cols 크기의 2차원 배열을 생성
  int **x, i;

  MALLOC(x, rows * sizeof(int *));
  for(i = 0; i < rows; i++)
    MALLOC(x[i], cols * sizeof(int));
  return x;
}