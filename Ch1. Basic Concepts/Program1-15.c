// 프로그램 1.15: count 문이 첨가된 프로그램 1.12
float rsum(float list[], int n){
  int count = 1;
  count++;  // if 문을 위한 명령문
  if (n) {
    count++; // 반환과 rsum의 호출을 위한 명령문
    return rsum(list, n-1) + list[n-1];
  }
  count++;  // 반환을 위한 명령문
  return 0;
}