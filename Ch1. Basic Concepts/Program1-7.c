// 프로그램 1.7: 순서 리스트 탐색
int binsearch(int list[], int searchnum, int left, int right){
  int middle;
  while(left <= right){
    middle = (left + right) / 2;
    switch(COMPARE(list[middle], searchnum)){
      case -1: 
        left = middle + 1; 
        break;
      case 0: return middle;
      case 1: right = middle - 1;
    }
  }
  return -1;
}