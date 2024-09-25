// 프로그램 1.8: 이원 탐색에 대한 순환 구현
int binsearch(int list[], int searchnum, int left, int right){
  int middle;
  if(left <= right){
    middle = (left + right) / 2;
    switch(COMPARE(list[middle], searchnum)){
      case -1: 
        return binsearch(list, searchnum, middle + 1, right);
      case 0: return middle;
      case 1: 
        return binsearch(list, searchnum, left, middle - 1);
    }
  }
  return -1;
}