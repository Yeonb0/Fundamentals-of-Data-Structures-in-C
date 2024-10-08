// d = a + b, 여기서 a, b, d는 다항식이다.
// 프로그램 2.5 : 함수 padd의 초기 버전
/*
d = Zero;
while(! IsZero(a) && ! IsZero(b)) do {
  switch (COMPARE(LeadExp(a), LeadExp(b))) {
    case -1 :
      d = Attach(d, Coeff(b, LeadExp(b)), LeadExp(b));
      b = Remove(b, LeadExp(b));
      break;
    case 0 : 
      sum = Coeff(a, LeadExp(a)) + Coeff(b, LeadExp(b));
      if (sum) {
        Attach(d, sum, LeadExp(a));
        a = Remove(a, LeadExp(a));
        b = Remove(b, LeadExp(b));
      }
      break;
    case 1 :
      d = Attach(d, Coeff(a, LeadExp(a)), LeadExp(a));
      a = Remove(a, LeadExp(a));
  }
}
*/