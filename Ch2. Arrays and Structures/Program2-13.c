// 프로그램 2.13 : 패턴의 마지막 문자를 먼저 검사하는 패턴 매칭

int nFind(char *string, char *pat){
  // 먼저 패턴의 마지막 문자를 매치시킨 뒤, 처음부터 매치시킨다.
  int i, j, start = 0;
  int lastS = strlen(string)-1;
  int lastP = strlen(pat)-1;
  int endMatch = lastP;

  for(i=0; endMatch <= lastS && endMatch >= 0; endMatch++, start++){
    if(string[endMatch] == pat[lastP]){
      for(j=0, i=start; j<lastP && string[i] == pat[j]; i++, j++)
        ;
      if(j == lastP) return start; // 성공
    }
  }
  return -1; // 실패
}