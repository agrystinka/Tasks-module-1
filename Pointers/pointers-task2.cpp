#include <iostream>

using namespace std;

//Sort bytes of integer number
//Low bytes on low address in memory

int main(){

  unsigned int C[3] = {0x7A025C1F, 0x3405C100, 0x9CFF046D};

  //In memory array C is placed like:
  //1F 5C 02 7A   00 C1 05 34   6D 04 FF 9C

  //After sort it should be placed in memory like:
  //02 1F 5C 7A   00 05 34 C1   04 6D 9C FF

  //It means, that array C after sort should be like:
  //7A 5C 1F 02   C1 34 05 00   FF 9C 6D 04

  unsigned int *h = &C[0];
  unsigned char *u;
  unsigned char tmp;
  int f;

  for(int i = 0; i < 3; i++)
    cout << hex << C[i] << ' ';

  //Sort
  for (int i = 0; i < 3; i++){
    u = (unsigned char *) (h + i);

    do{
      f = 0;
      for (int j = 0; j < 3; j++)
        if (*(u + j) > *(u + j + 1)){
          tmp = *(u + j);
          *(u + j) = *(u + j +1);
          *(u + j + 1) = tmp;
          f = 1;
        }
    }while(f == 1);
  }

cout << endl;
  for(int i = 0; i < 3; i++)
    cout << hex << C[i] << ' ';
}
