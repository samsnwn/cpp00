#include <iostream>

int main(int argc, char *argv[])
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
  {
    for (int i = 1; i < argc; i++)
    {
      std::string arg = argv[i];
      for (int j = 0; arg[j] != '\0'; j++)
      {
        if (std::isalpha(arg[j]))
          std::cout << std::toupper(arg[j]);
        else
          std::cout << arg[j];
      }
    }
  }
  std::cout << std::endl;
  return 0;
}
