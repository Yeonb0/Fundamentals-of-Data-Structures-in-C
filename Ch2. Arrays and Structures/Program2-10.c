// 프로그램 2.10 : 희소 행렬의 곱셈
#define MAX_TERMS 101

typedef struct {
  int row;
  int col;
  int value;
} term;

void matrixMult(term a[], term b[], term d[]){
  // 두 희소행렬을 곱한다.
  int i, j, column, totalB = b[0].value, totalD = 0;
  int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;
  int colsB = b[0].col;
  int rowBegin = 1, row = a[1].row, sum = 0;
  term newB[MAX_TERMS];
  if (colsA != b[0].row){
    fprintf("Incompatible matrices\n");
    exit(1);
  }
  fastTranspose(b, newB);
  // 경계 조건 설정
  a[totalA+1].row = rowsA;
  newB[totalB+1].row = colsB;
  newB[totalB+1].col = 0;
  for(i=1; i<=totalA;){
    column = newB[1].row;
    for(j=1; j<=totalB+1;){  // a의 행과 b의 열을 곱함
      if(a[i].row != row){
        storeSum(d, &totalD, row, column, &sum);
        i = rowBegin;
        for(; newB[j].row == column; j++)
          ;
        column = newB[j].row;
      } 
      else if(newB[j].row != column){
        storeSum(d, &totalD, row, column, &sum);
        i = rowBegin;
        column = newB[j].row;
      } 
      else switch (COMPARE(a[i].col, newB[j].col)){
        case -1: // a의 다음 항으로 이동
          i++; break;  
        case 0:  // 항을 더하고, a와 b를 다음 항으로 이동
          sum += (a[i++].value * newB[j++].value); break;
        case 1:  // b의 다음 항으로 이동
          j++;
      }
    }  // for j 끝
    for(; a[i].row == row; i++)
      ;
    rowBegin = i;
    row = a[i].row;
  }  // for i 끝
  d[0].row = rowsA;
  d[0].col = colsB;
  d[0].value = totalD;
}