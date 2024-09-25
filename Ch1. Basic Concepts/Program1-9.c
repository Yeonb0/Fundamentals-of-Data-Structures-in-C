// 프로그램 1.9: 순환 순열 생성기
void perm(char *list, int i, int n){
  int j, temp;
  if(i == n){
    for(j = 0; j <= n; j++)
      printf("%c", list[j]);
    printf("\n");
  } else {
    for(j = i; j <= n; j++){
      SWAP(&list[i], &list[j]);
      perm(list, i + 1, n);
      SWAP(&list[i], &list[j]);
    }
  }
}