#include <iostream>

using namespace std;

int main(){

  char arr[] = "ARNOLDIZLDALJNAKPILDMCK";
  char *V[4];
  int **U[2];

  V[0] = &arr[0];
  V[1] = &arr[7];
  V[2] = &arr[14];
  V[3] = &arr[21];

  U[0] =  (int**)&V[0];
  U[1] =  (int**)&V[3];

  //-------------------------------------------------------------------
  //Intro
  cout << "Intro" << endl;
  cout << endl;

  // The task is to print fist symbol - 'A'
  cout << "First syblol of string arr:" << endl;

  //calling by char array arr
  cout << arr[0] << endl;

  //calling by char pointer's array V
  cout << *V[0] << endl;

  //calling by int pointer's array U
  cout << *((char*)*U[0]) << endl;

  cout << endl;

  cout << "Address of V[0] - first element of char pointer's array V:" << endl;
  cout << &V[0] << endl;
  cout << U[0] << endl;
  cout << endl;

  cout << "String arr:" << endl;
  cout << arr <<endl;
  cout << &arr[0] << endl;
  cout << &*V[0] << endl;
  cout << &*(char*)*U[0] << endl;
  cout << endl;

  //-------------------------------------------------------------------
  //Task

  //You have 3 substrings: ARNOLDI, ZLDALJN, AKPILDM.
  //The borders of these substrings are saved in char pointer's array V.
  //Print the identic double word of those 3 strings.
  //If there are not any identic double word, print identic word.
  //If there are not any identic word, print identic byte.
  //Else, print "0".

  //To call elements of char array arr use only int poiter's array U.

  int F = 0;
  int i = 4;
  int j;

  int f2;
  int f3;

  while (i > 0 && F == 0){

    j = 0;
    while((j < (char *)*(U[0] + 1) - (char *)*U[0] - i) && F == 0){

      f2 = 0;
      int k = 0;
      while ((k < (char *)*(U[0] + 2) - (char *)*(U[0] + 1) - i) && f2 == 0){

        f2 = 1;
        for (int h = 0; h < i; h++)
          if(*((char *)*U[0] + j + h)!=*((char *)*(U[0] + 1) + k + h))
            f2 = 0;
        k++;
      }


      f3 = 0;
      k = 0;
      while ((k < (char *) *(U[0] + 3) - (char*) (U[0] + 2) - i) && f3 == 0){

        f3 = 1;
        for (int h = 0; h < i; h++)
          if (*((char *) *U[0] + j + h) != *((char*)*(U[0] + 2) + k + h))
            f3 = 0;
        k++;
      }

      if (f3 == 1 && f2 == 1)
        F = 1;


      j++;
    }
    if (F == 0)
      i /= 2;
  }


  cout << "-----------------------------------------" << endl;
  cout << "Task answer" << endl;

  if (i == 0)
    cout <<"There is no equal symbols in this 3 substrings." << endl;

  else{

    if (i == 4)
    cout <<"For this 3 substrings equal doubble word is:" << endl;

    else if(i == 2)
      cout <<"For this 3 substrings equal word is:" << endl;

    else if(i == 1)
        cout <<"For this 3 substrings equal byte is:" << endl;

    for (int h = 0; h < i; h++)
      cout << *((char *) *U[0] + j - 1 + h);

    cout << endl;
  }


  //The same
  //Using char pointer's array V

//   while (i > 0 && F == 0){
//
//     j = 0;
//     while((j < V[1] - V[0] - i) && F == 0){
//
//       f2 = 0;
//       int k = 0;
//       while ((k < V[2] - V[1] - i) && f2 == 0){
//         f2 = 1;
//
//         for (int h = 0; h < i; h++)
//           if(*(V[0] + j + h)!=*(V[1] + k + h))
//             f2 = 0;
//
//         k++;
//       }
//
//       f3 = 0;
//       k = 0;
//       while ((k < V[3] - V[2] - i) && f3 == 0){
//         f3 = 1;
//
//         for (int h = 0; h < i; h++)
//           if(*(V[0] + j + h)!=*(V[2] + k + h))
//             f3 = 0;
//
//         k++;
//       }
//
//       if (f3 == 1 && f2 == 1)
//         F = 1;
//
//       j++;
//     }
//     if (F == 0)
//       i /= 2;
//   }
//
//   cout << "-----------------------------------------" << endl;
//   cout << "Task answer" << endl;
//
//   if (i == 0)
//     cout <<"There is no equal symbols in this 3 substrings." << endl;
//
//   else{
//
//     if (i == 4)
//     cout <<"For this 3 substrings equal doubble word is:" << endl;
//
//     else if(i == 2)
//       cout <<"For this 3 substrings equal word is:" << endl;
//
//     else if(i == 1)
//         cout <<"For this 3 substrings equal byte is:" << endl;
//
//     for (int h = 0; h < i; h++)
//       cout << *( V[0] + j - 1 + h);
//
//     cout << endl;
//   }
 }
