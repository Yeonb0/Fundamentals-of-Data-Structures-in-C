#define MAX_SIZE 100
// 프로그램 2.1: 배열 프로그램의 예
float sum(float a[], int n);
float input[MAX_SIZE], answer;

void main(){
  int i;
  for (i = 0; i < MAX_SIZE; i++)
    input[i] = i;
  answer = sum(input, MAX_SIZE);
  printf("The sum is: %f\n", answer);
}

float sum(float a[], int n){
  int i;
  float tempsum = 0;
  for(i = 0; i < n; i++)
    tempsum += a[i];
  return tempsum;
}