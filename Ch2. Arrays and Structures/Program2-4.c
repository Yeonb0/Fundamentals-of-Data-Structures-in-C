#define FALSE 0
#define TRUE 1
// 프로그램 2.4: 구조의 동등성을 검사하는 함수
typedef struct{
  char name[20];
  int age;
  float salary;
} humanBeing;

int humansEqual(humanBeing person1, humanBeing person2){
  // 동일인 일시 TRUE, 그렇지 않으면 FALSE 반환
  if (strcmp(person1.name, person2.name))
    return FALSE;
  if (person1.age != person2.age)
    return FALSE;
  if (person1.salary != person2.salary)
    return FALSE;
  return TRUE;
}