// 프로그램 2.12 : 스트링 삽입 함수
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void strnins(char *s, char *t, int i){
  // 문자열 s의 i번째 위치에 문자열 t를 삽입
  char string[MAX_SIZE], *temp = string;
  if (i < 0 || i > strlen(s)){
    fprintf(stderr, "잘못된 삽입 위치\n");
    exit(1);
  }
  if (!strlen(s))
    strcpy(s, t);
  else if (strlen(t)){ 
    strncpy(temp, s, i);
    strcpy(temp, t);
    strcpy(temp, s+i);
    strcpy(s, string);
  }
}