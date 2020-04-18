#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*
 * Function: print_spaces
 * Parameters: int n
 * Return: void
 * Prints n number of spaces
 */
void print_spaces(int n) {
        int i;
        for(i = 0; i < n; i++)
                cout << " ";
}

/*
 * Function print_backwards
 * Parameters: Character input[10]
 * Retun: void
 * Prints array of length 10 backwords
 */
void print_backwords(char input[10]) {
        int i;
        for(i = 10; i >= 0; i--) {
                cout << input[i];
        }
}

/*
 * Function: print
 * Parameters: Character input[10]
 * Return: void
 * Prints array in pattern as demonstrated on Camino
 */
void print(char input[10]) {
        int i;
        int k = 1, n = 10;
        for(i = 0; i < 5; i++) {
                print_spaces(k); //Prints foward spaces
                cout << input; //Prints input foward
                print_spaces(n); //Prints middle spaces
                print_backwords(input); //Prints input backwards
                cout << endl; //End line
                k += 2; //Increment foward spaces
                n += 2; //Increment middle spaces
        }
}

/*
 * Function: check
 * Parameters: Character input[10]
 * Return: boolean
 * Checks if array is consisting of only numerical digits
 */
bool check(char input[10]){
  int i;
  for(i = 0; i < 10; i++){
    if(input[i] >= '0' && input[i] <= '9'){
    } else {
      return true; //If not a digit return
    }
  }
  return false;
}

/*
 * Function: main
 * Prompts user for string of 10 digits.
 * Prints strings of digits as demonstrated on Camino.
 */
int main() {
        char input[11];
        cout << "Please type a string of 10 digits (0 to 9) with no spaces: ";
        cin.get(input, 11);
        if(check(input)){ //If input includes non digits exit.
          cout << "Error: Invalid Input" << endl;
          return 0;
        }
        print(input); //Prints input as demonstrated on Camino
        return 0;
}
