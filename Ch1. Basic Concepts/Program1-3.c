// 프로그램 1.3: swap 함수
void swap(int *x, int *y){
  // both parameters are pointers to ints
  int temp; 
  temp = *x;
  *x = *y;
  *y = temp;
}