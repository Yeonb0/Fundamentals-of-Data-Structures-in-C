// 프로그램 1.14: 프로그램 1.13의 단순 버전
float sum(float list[], int n){
  int i, count=0;
  float tempSum = 0;
  for(i = 0; i < n; i++)
    count += 2;
    tempSum += list[i];
  count += 3;
  return tempSum;
}