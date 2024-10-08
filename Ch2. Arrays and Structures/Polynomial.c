#define MAX_TERMS 101
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)
#include <stdio.h>

typedef struct {
  float coef;
  int expon;
} Polynomial;

Polynomial terms[MAX_TERMS];
int avail = 0;

Polynomial Zero(void){
  Polynomial p;
  p.expon = -1;
  return p;
}

int IsZero(Polynomial p){
  return p.expon == -1;
}

float Coef(Polynomial p, int exponent){
  if(p.expon == exponent)
    return p.coef;
  return 0;
}

int LeadExp(Polynomial p){
  return p.expon;
}

Polynomial Attach(Polynomial p, float coefficient, int exponent){
  if(avail >= MAX_TERMS){
    fprintf(stderr, "다항식에 항이 너무 많다.\n");
    exit(1);
  }
  terms[avail].coef = coefficient;
  terms[avail++].expon = exponent;
  return p;
}

Polynomial Remove(Polynomial p, int exponent){
  int i;
  for(i = 0; i < avail; i++){
    if(terms[i].expon == exponent){
      for(; i < avail - 1; i++)
        terms[i] = terms[i + 1];
      avail--;
      return p;
    }
  }
  fprintf(stderr, "항을 찾을 수 없다.\n");
  exit(1);
}

Polynomial pAdd(Polynomial a, Polynomial b){
  Polynomial d;
  int startA, finishA, startB, finishB, startD, finishD;
  float coefficient;
  startA = 0;
  startB = 0;
  startD = avail;
  while(!IsZero(a) && !IsZero(b)){
    switch(COMPARE(LeadExp(a), LeadExp(b))){
      case -1:
        d = Attach(d, Coef(b, LeadExp(b)), LeadExp(b));
        b = Remove(b, LeadExp(b));
        break;
      case 0:
        coefficient = Coef(a, LeadExp(a)) + Coef(b, LeadExp(b));
        if(coefficient)
          d = Attach(d, coefficient, LeadExp(a));
        a = Remove(a, LeadExp(a));
        b = Remove(b, LeadExp(b));
        break;
      case 1:
        d = Attach(d, Coef(a, LeadExp(a)), LeadExp(a));
        a = Remove(a, LeadExp(a));
    }
  }
  for(; !IsZero(a); a = Remove(a, LeadExp(a)))
    d = Attach(d, Coef(a, LeadExp(a)), LeadExp(a));
  for(; !IsZero(b); b = Remove(b, LeadExp(b)))
    d = Attach(d, Coef(b, LeadExp(b)), LeadExp(b));
  finishD = avail - 1;
  return d;
}

Polynomial pMult(Polynomial a, Polynomial b){
  Polynomial d;
  int startA, finishA, startB, finishB, startD, finishD;
  int i;
  float coefficient;
  startA = 0;
  startB = 0;
  startD = avail;
  while(!IsZero(a)){
    for(startB = 0; !IsZero(b); b = Remove(b, LeadExp(b))){
      coefficient = Coef(a, LeadExp(a)) * Coef(b, LeadExp(b));
      if(coefficient){
        for(i = 0; i < avail; i++){
          if(terms[i].expon == LeadExp(a) + LeadExp(b)){
            terms[i].coef += coefficient;
            break;
          }
        }
        if(i == avail)
          d = Attach(d, coefficient, LeadExp(a) + LeadExp(b));
      }
    }
    a = Remove(a, LeadExp(a));
  }
  finishD = avail - 1;
  return d;
}

void printPoly(Polynomial p){
  int i;
  for(i = 0; i < avail; i++)
    printf("%3.0fx^%d", terms[i].coef, terms[i].expon);
  printf("\n");
}

void readPoly(Polynomial *p){
  int i, n;
  float coef;
  int expon;
  printf("항의 개수는?");
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    printf("계수와 지수를 입력하시오: ");
    scanf("%f %d", &coef, &expon);
    *p = Attach(*p, coef, expon);
  }
}

Polynomial pEval(Polynomial p, float x){
  int i;
  Polynomial result = Zero();
  for(i = 0; i < avail; i++){
    result.coef += terms[i].coef * pow(x, terms[i].expon);
    result.expon = 0;
  }
  return result;
}
