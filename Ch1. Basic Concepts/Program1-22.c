// 프로그램 1.22: 행렬의 전치 함수
#define MAX_SIZE 100
void transpose(int a[][MAX_SIZE]){
  int i, j, temp;
  for(i = 0; i < MAX_SIZE; i++)
    for(j = i + 1; j < MAX_SIZE; j++){
      SWAP(a[i][j], a[j][i], temp);
    }
}