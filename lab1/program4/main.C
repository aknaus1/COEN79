#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

/*
 * Function: response
 * Parameters: none
 * Return: Boolean
 * Recieves a Y/N response from user returing true if 'Y' and false if 'N'
 * Is not case sensitive.
 */
bool response() {
    char c;
    while(1) {
        cin >> c;
        if(c == 'Y' || c == 'y')
            return true;
        else if(c == 'N' || c == 'n')
            return false;
        else
            cout << "Please enter Y or N." << endl;
    }
}

/*
 * Function: main
 * Parameters: none
 * Recieves a Y/N response from user returing true if 'Y' and false if 'N'
 * Is not case sensitive.
 */
int main() {
    int guess, i, n = 0, k = 20;
    int list[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout << "Think of a number between 1 and 20. Press enter when you are ready.";
    cin.ignore(); //waits for user to hit enter
    while(1){
        srand(time(NULL));
        guess = rand() % k; //generates index of guess number
        n++; //incrememnts guess count
        cout << "Is your number: " << list[guess] << " (Y/N)" << endl;
        if(response()) //gets response from user, if guessed correctly exits loop.
            break;
        for(i = guess; i < k - 1; i++) //removes guessed number from list
            list[i] = list[i+1];
        k--;
    }
    cout << "I found the number in " << n << " steps." << endl;
}
