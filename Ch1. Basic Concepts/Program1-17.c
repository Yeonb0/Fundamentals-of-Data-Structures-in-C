// 프로그램 1.17: count 문이 첨가된 행렬의 덧셈
#define MAX_SIZE 100
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols){
  int i, j, count = 1;
  for(i = 0; i < rows; i++){
    count++;  // i for 문을 위한 명령문
    for(j = 0; j < cols; j++){
      count++;  // j for 문을 위한 명령문
      c[i][j] = a[i][j] + b[i][j];
      count++;  // 덧셈을 위한 명령문
    }
    count++;  // j for 문의 마지막 명령문
  }
  count++;  // i for 문의 마지막 명령문
  count++;  // 반환을 위한 명령문
}