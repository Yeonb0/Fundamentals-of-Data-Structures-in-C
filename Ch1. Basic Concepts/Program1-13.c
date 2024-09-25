// 프로그램 1.13: count 문을 가진 프로그램 1.11
float sum(float list[], int n){
  int i, count=1;  // 지정문을 위한 선언
  float tempSum = 0; count++;  // 지정문을 위한 연산
  for(i = 0; i < n; i++)
    count++;  // for 루프 연산
    tempSum += list[i]; count++;  // 지정문을 위한 연산
    count++;  // for 마지막 실행
  count++;  // 반환 위한 명령문
  return tempSum;
}