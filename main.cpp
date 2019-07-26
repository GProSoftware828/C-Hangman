#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

using namespace std;
string get_word();
void print_board(int);
void print_blanks(string, string);

int main()
{
    int user_lives = 7;
    string word = get_word();
    string letters_guessed = "";
    string guess;
    while (user_lives > 0)
    {
        flag = true;
        print_board(user_lives);
        cout << endl
             << endl;
        print_blanks(word, letters_guessed);
        if (flag == true)
        {
            break;
        }
        cout << "\n\nLetters Guessed: " << letters_guessed << endl;
        cout << "\n\nEnter a letter: ";
        cin >> guess;
        letters_guessed += guess;
        if (word.find(guess) != -1)
        {
            system("clear");
            continue;
        }
        else
        {
            //"CLS" on windows
            system("clear");
            user_lives--;
        }
    }

    if (user_lives == 0)
    {
        cout << "\n\n\nYOU LOSE" << endl
             << endl;
        cout << "The word was: " << word;
    }
    else if (user_lives > 0)
    {
        cout << "\n\n\nYOU WIN!" << endl
             << endl;
        cout << "The word was: " << word;
    }
    return 0;
}