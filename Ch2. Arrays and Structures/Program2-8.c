// 프로그램 2.8 : 희소 행렬의 전치
typedef struct {
  int row;
  int col;
  int value;
} term;

void transpose(term a[], term b[]){
  // a를 전치시켜 b를 생성
  int n, i, j, currentb;
  n = a[0].value;  // 총 원소 수
  b[0].row = n;  // b의 행 수 = a의 열 수
  b[0].col = a[0].row;  // b의 열 수 = a의 행 수
  b[0].value = n;
  if (n > 0){  // 0이 아닌 행렬
    currentb = 1;
    for (i = 0; i < a[0].col; i++)  // a에서 열별 전치
      for (j = 1; j <= n; j++)  // 현재의 열로부터 원소를 찾음
        if (a[j].col == i){  // 현제 열에 있는 원소를 b에 첨가
          b[currentb].row = a[j].col;
          b[currentb].col = a[j].row;
          b[currentb].value = a[j].value;
          currentb++;
        }
  }
}

