#include <string>
#include <iostream>
#include <fstream>

int generate_random_number();
bool flag = false;

std::string get_word()
{
  //Change wordbank list here:
  const int WORDLIST_SIZE = 24;
  std::string temp_word;
  std::string wordlist[WORDLIST_SIZE] = {" "};
  int index = 0;
  std::ifstream input_file("wordlist.txt");
  if (!input_file)
  {
    std::cout << "Error: -6//Wordlist not found...\n\n";
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
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|      0" << std::endl;
    std::cout << "\t\t\t|     /|\\" << std::endl;
    std::cout << "\t\t\t|      |" << std::endl;
    std::cout << "\t\t\t|     / \\" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  case 1:
  {
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|      0" << std::endl;
    std::cout << "\t\t\t|     /|\\" << std::endl;
    std::cout << "\t\t\t|      |" << std::endl;
    std::cout << "\t\t\t|       \\" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  case 2:
  {
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|      0" << std::endl;
    std::cout << "\t\t\t|     /|\\" << std::endl;
    std::cout << "\t\t\t|      |" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  case 3:
  {
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|      0" << std::endl;
    std::cout << "\t\t\t|     /|\\" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  case 4:
  {
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|      0" << std::endl;
    std::cout << "\t\t\t|     /|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  case 5:
  {
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|      0" << std::endl;
    std::cout << "\t\t\t|      |" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  case 6:
  {
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|      0" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  case 7:
  {
    std::cout << "\t\t\t|------|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|" << std::endl;
    std::cout << "\t\t\t|_";
    break;
  }
  }
}

void print_blanks(std::string chosen_word, std::string letters_guessed)
{
  for (int i = 0; i < chosen_word.size(); i++)
  {
    if (letters_guessed.find(chosen_word.at(i)) != -1)
    {
      std::cout << chosen_word.at(i) << " ";
    }
    else
    {
      std::cout << "_";
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