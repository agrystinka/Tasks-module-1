#include <iostream>

using namespace std;

int showMatrix(int MA[5][5]);

int main(){

  int MA[5][5] = {
    {1, 9, 6, 4, 3},
    {2, 50, 1, 3, 10},
    {8, 7, 3, 1, 2},
    {2, 1, 8, 1, 7},
    {3, 7, 2, 5, 4}
  };

showMatrix(MA);

int xmax = 0;
int ymax = 0;

//find positions of MAX elment
for(int i = 0; i < 5; i++)
  for(int j = 0; j < 5; j++)
    if (MA[i][j] > MA[xmax][ymax]){
      xmax = i;
      ymax = j;
    }

cout << MA[xmax][ymax] << endl; //MAX

//fill with '0' diagonals, which contain MAX element

int k = ymax - xmax; //'main' diagonal identificator
int g = ymax + xmax; //'side' diagonal identificator

//fill 'main' diagonal with '0'
if(k >= 0)
  for(int i = 0; i <= 5 - k; i++)
    MA[i][ i+ k] = 0;
else
  for(int i = -k; i <= 5; i++)
    MA[i][i + k] = 0;

//fill 'side' diagonal with '0'
if (g < 5)
  for(int i = g; i>=0; i--)
    MA[g - i][i] = 0;
else
  for(int i = g % 5 +1 ; i < 5; i++)
    MA[i][g - i] = 0;

showMatrix(MA);
}

//----------------------------------------
int showMatrix(int MA[5][5]){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++)
      cout << MA[i][j]<<' ';
    cout << endl;
  }
  return 1;
}
