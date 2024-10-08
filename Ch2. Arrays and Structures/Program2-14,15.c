#include <stdio.h>
#include <string.h>
#define max_string_size 100
#define max_pattern_size 100
int pmatch();
void fail();
int failure[max_pattern_size];
char string[max_string_size];
char pat[max_pattern_size];

// 프로그램 2.14 : Knuth, Morris, Pratt의 패턴 매칭 알고리즘
int pmatch(char *string, char *pat){
  // Knuth, Morris, Pratt의 패턴 매칭 알고리즘
  int i=0, j=0;
  int lastS = strlen(string);
  int lastP = strlen(pat);
  while(i<lastS && j<lastP){
    if(string[i] == pat[j]){
      i++; j++;
    } else if(j == 0) i++;
    else j = failure[j-1] + 1;
  }
  return ((j == lastP) ? (i-lastP) : -1);
}

// 프로그램 2.15 : 실패 함수의 계산
void fail(char *pat){
  // 패턴의 실패 함수 계산
  int i, n = strlen(pat);
  failure[0] = -1;
  for(int j=1; j<n; j++){
    i = failure[j-1];
    while((pat[j] != pat[i+1]) && (i>=0))
      i = failure[i];
    if(pat[j] == pat[i+1]) 
      failure[j] = i+1;
    else failure[j] = -1;
  }
}