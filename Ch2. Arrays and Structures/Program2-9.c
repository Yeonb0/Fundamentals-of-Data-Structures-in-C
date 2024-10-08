#define MAX_COL 101

// 프로그램 2.9 : 희소 행렬의 빠른 전치
typedef struct {
  int row;
  int col;
  int value;
} term;

void fastTranspose(term a[], term b[]){
  // a를 전치시켜 b에 저장
  int rowTerms[MAX_COL], startingPos[MAX_COL];
  int i, j, numCols = a[0].col, numTerms = a[0].value;
  b[0].row = numCols;
  b[0].col = a[0].row;
  b[0].value = numTerms;
  if (numTerms > 0){  // 0이 아닌 행렬
    for (i = 0; i < numCols; i++)
      rowTerms[i] = 0;
    for (i = 1; i <= numTerms; i++)
      rowTerms[a[i].col]++;
    startingPos[0] = 1;
    for (i = 1; i < numCols; i++)
      startingPos[i] = startingPos[i-1] + rowTerms[i-1];
    for (i = 1; i <= numTerms; i++){
      j = startingPos[a[i].col]++;
      b[j].row = a[i].col;
      b[j].col = a[i].row;
      b[j].value = a[i].value;
    }
  }
}