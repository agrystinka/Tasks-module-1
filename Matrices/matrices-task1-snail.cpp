#include <iostream>

using namespace std;

int fillMatrix(int MA[4][5]);
int showMatrix(int MA[4][5]);
int showArray(int A[20]);

int snail(int MA[4][5], int A[20]);

int main(){

  int MA[4][5];
  fillMatrix(MA);

  int A[20];

  showMatrix(MA);

  snail(MA, A);
  showArray(A);

}

//----------------------------------------
int snail(int MA[4][5], int A[20]){

  //angles of mayrix MA
  int left = 0;
  int right = 4;
  int top = 0;
  int bottom = 3;

  //iterator for array A
  int a = 0;

  //copying
  while(left <= right && top <= bottom){

    for (int i = left; i <= right; i++)
      A[a++] = MA[top][i];
    top++;

    for (int i = top; i <= bottom; i++)
      A[a++] = MA[i][right];
    right--;

    for (int i = right; i >= left; i--)
      A[a++] = MA[bottom][i];
    bottom--;

    for (int i = bottom; i >= top; i--)
      A[a++] = MA[i][left];
    left++;
  }

  return 1;
}

//----------------------------------------
int fillMatrix(int MA[4][5]){
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 5; j++)
      MA[i][j] = i * 5 + j;

  return 1;
}


int showMatrix(int MA[4][5]){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 5; j++)
      cout << MA[i][j]<<' ';
    cout << endl;
  }

  return 1;
}


int showArray(int A[20]){
  for (int i = 0; i < 20; i++)
    cout << A[i] << ' ';
  cout << endl;

  return 1;
}
