// 프로그램 1.18: 프로그램 1.17의 단순화
#define MAX_SIZE 100
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rows, int cols){
  int i, j, count = 1;
  for(i = 0; i < rows; i++){
    for(j = 0; j < cols; j++){
      c[i][j] = a[i][j] + b[i][j];
      count += 2;
    }
    count += 2;  
  }
  count++;  // 반환을 위한 명령문
}