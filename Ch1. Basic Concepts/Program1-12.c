//프로그램 1.12: 리스트에 있는 수를 합산하기 위한 순환 함수
float rsum(float list[], int n){
  if(n) return rsum(list, n-1) + list[n-1];
  return 0;
}