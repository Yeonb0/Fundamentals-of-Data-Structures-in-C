// 프로그램 2.2: 주소로 접근되는 1차원 배열
void print1(int *ptr, int rows){
  // 포인터를 사용해 1차원 배열을 출력
  int i;
  printf("Address Contents\n");
  for(i = 0; i < rows; i++)
    printf("%8u%5d\n", ptr + i, *(ptr + i));
  printf("\n");
}