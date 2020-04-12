#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*
 * Function: is_alphanumeric
 * Parameter: Character c
 * Return: Boolean
 * Returns true if character is alphanumeric, otherwise returns false.
 */
bool is_alphanumeric(char c) {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) { //Check if character is alphanumeric 
                return true;
        }
        return false;
}

/*
 * Function: count
 * Parameter: Character input[100]
 * Return: void
 * Counts the amount of alpha-numeric and non alpha-numeric characters in input
 */
void count(char input[100]) {
        int i = 0, alpha = 0, nonalpha = 0;
        while(input[i] != '\0') {
                if(is_alphanumeric(input[i]))
                        alpha++; //Increment alphanumeric character count
                else if(ispunct(input[i]))
                        nonalpha++; //Increment non-alphanumeric character count
                i++;
        }
        cout << "You entered: " << input << endl;
        cout << "There are " << alpha << " alphanumeric characters." << endl;
        cout << "There are " << nonalpha << " non-alphanumeric characters." << endl;
        return;
}

/*
 * Function: main
 * Recieve phrase input from user.
 * Then counts and prints out the amount of alphanumeric and non-alphanumeric characters in the phrase.
 */
int main() {
        int i = 0, alpha = 0, nonalpha = 0;
        char input[100];
        cout << "What is your phrase?: ";
        cin.get(input, 100);
        count(input); //Counts and prints the amount of alphanumeric and non-alphanumeric characters
        return 0;
}