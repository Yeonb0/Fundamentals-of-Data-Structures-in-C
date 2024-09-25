// 프로그램 1.11: 리스트에 있는 수를 합산하기 위한 반복 함수
float sum(float list[], int n){
  int i;
  float tempSum = 0;
  for(i = 0; i < n; i++)
    tempSum += list[i];
  return tempSum;
}