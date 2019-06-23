#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
string get_word();
void print_board(int);
void print_blanks(string, string);
int generate_random_number();

bool flag = false;

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

string get_word()
{
    //Change wordbank list here:
    const int WORDLIST_SIZE = 24;
    string temp_word;
    string wordlist[WORDLIST_SIZE] = {" "};
    int index = 0;
    ifstream input_file("wordlist.txt");
    if (!input_file)
    {
        cout << "Error: -6//Wordlist not found...\n\n";
    }
    input_file.ignore(255, '\n');
    //pre-read
    input_file >> temp_word;
    while (!input_file.eof())
    {
        wordlist[index] = temp_word;
        index++;
        //post read
        input_file >> temp_word;
    }

    return wordlist[generate_random_number()];
}

void print_board(int lives)
{
    switch (lives)
    {
    case 0:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|      0" << endl;
        cout << "\t\t\t|     /|\\" << endl;
        cout << "\t\t\t|      |" << endl;
        cout << "\t\t\t|     / \\" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    case 1:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|      0" << endl;
        cout << "\t\t\t|     /|\\" << endl;
        cout << "\t\t\t|      |" << endl;
        cout << "\t\t\t|       \\" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    case 2:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|      0" << endl;
        cout << "\t\t\t|     /|\\" << endl;
        cout << "\t\t\t|      |" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    case 3:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|      0" << endl;
        cout << "\t\t\t|     /|\\" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    case 4:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|      0" << endl;
        cout << "\t\t\t|     /|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    case 5:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|      0" << endl;
        cout << "\t\t\t|      |" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    case 6:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|      0" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    case 7:
    {
        cout << "\t\t\t|------|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|" << endl;
        cout << "\t\t\t|_";
        break;
    }
    }
}

void print_blanks(string chosen_word, string letters_guessed)
{
    for (int i = 0; i < chosen_word.size(); i++)
    {
        if (letters_guessed.find(chosen_word.at(i)) != -1)
        {
            cout << chosen_word.at(i) << " ";
        }
        else
        {
            cout << "_";
            flag = false;
        }
    }
}

int generate_random_number()
{
    srand(time(NULL));
    int random_number = rand() % 10 + 1;
    return random_number;
}