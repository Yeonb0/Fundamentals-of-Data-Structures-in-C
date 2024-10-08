// 프로그램 2.6 : 두 다항식을 더하는 함수
/*
void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD){
  // A(x)와 B(x)를 더하여 D(x)를 생성한다
  float coefficient;
  *startD = avail;
  while(startA <= finishA && startB <= finishB){
    switch(COMPARE(terms[startA].expon, terms[startB].expon)){
      case -1: // a의 지수 < b의 지수
        attach(terms[startB].coef, terms[startB].expon);
        startB++;
        break;
      case 0: // a의 지수 = b의 지수
        coefficient = terms[startA].coef + terms[startB].coef;
        if(coefficient)
          attach(coefficient, terms[startA].expon);
        startA++;
        startB++;
        break;
      case 1: // a의 지수 > b의 지수
        attach(terms[startA].coef, terms[startA].expon);
        startA++;
    }
  }
  // A(x)에 남은 항들을 D(x)에 추가한다
  for(; startA <= finishA; startA++)
    attach(terms[startA].coef, terms[startA].expon);
  // B(x)에 남은 항들을 D(x)에 추가한다
  for(; startB <= finishB; startB++)
    attach(terms[startB].coef, terms[startB].expon);
  *finishD = avail - 1;
}
*/