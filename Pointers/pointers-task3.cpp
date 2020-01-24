#include <iostream>

using namespace std;

main(){
  //Solution is suited for 4-byte int and 4-byte float numbers

  float a = 0.625;

  //Binary representation of a (for 4-byte float) is:
  //(1 bit sign, 8 bits exponent, 23 bits mantissa)
  //0011 1111 0010 0000 0000 0000 0000 0000
  //Heximal representation:
  // 3F 20 00 00

  cout << "a = " << a << endl;

// Change the sign of float number a using pointers and bitwise operators only.
  int *p = (int *) &a;
  *p ^=0x80000000; //a = -0.625
  cout << "- a = " << a << endl;

  *p ^=0x80000000; //a = 0.625

  //Double the number a using pointers and bitwise operators only.
  *p += 0x00800000; //a = 1.25
  cout << "a * 2 = " << a << endl;
  
}
