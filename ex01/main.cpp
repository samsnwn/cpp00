#include "Contact.hpp"
#include "PhoneBook.hpp"

void contactPrompt(std::string &fname, std::string &lname, std::string &nick, std::string &phone, std::string &secret)
{
  while (fname.empty())
  {
    std::cout << BOLD << "Enter first name: " << RESET;
    std::getline(std::cin, fname);
    if (fname.empty())
      std::cout << RED << "First name cannot be empty!" << RESET << std::endl;
  }
  while (lname.empty())
  {
    std::cout << BOLD << "Enter last name: " << RESET;
    std::getline(std::cin, lname);
    if (lname.empty())
      std::cout << RED << "Last name cannot be empty!" << RESET << std::endl;
  }
  while (nick.empty())
  {
    std::cout << BOLD << "Enter nick name: " << RESET;
    std::getline(std::cin, nick);
    if (nick.empty())
      std::cout << RED << "Nick name cannot be empty!" << RESET << std::endl;
  }
  while (phone.empty())
  {
    std::cout << BOLD << "Enter phone number: " << RESET;
    std::getline(std::cin, phone);
    if (phone.empty())
      std::cout << RED << "Phone number cannot be empty!" << RESET << std::endl;
  }
  while (secret.empty())
  {
    std::cout << BOLD << "Enter your darkest secret: " << RESET;
    std::getline(std::cin, secret);
    if (secret.empty())
      std::cout << RED << "Darkest secret cannot be empty!" << RESET << std::endl;
  }
}

int main()
{
  std::string input;
  PhoneBook phonebook;

  while (input.compare("EXIT") != 0)
  {
    std::cout << BOLD << "Please insert ADD, SEARCH or EXIT" << RESET << std::endl;
    std::cin >> input;
    if (input.compare("ADD") == 0)
    {
      std::cout << std::endl;
      std::cin.ignore(); // Clear leftover newline from reading "ADD"
      std::string fname, lname, nick, phone, secret;
      contactPrompt(fname, lname, nick, phone, secret);
      Contact newContact(fname, lname, nick, phone, secret);
      int prevTotal = phonebook.getTotalContacts();
      int slotDisplay = phonebook.addContact(newContact);
      if (prevTotal < 8)
        std::cout << GREEN << "Contact #" << slotDisplay << " created" << RESET << std::endl;
      else
        std::cout << YELLOW << "Contact #" << slotDisplay << " updated" << RESET << std::endl;
      std::cout << std::endl;
    }
    else if (input.compare("SEARCH") == 0)
    {
      if (phonebook.getTotalContacts() == 0)
        std::cout << std::endl
                  << RED << "Phonebook is empty. Add some contacts first!" << RESET << std::endl;
      else
      {
        std::cout << std::endl;
        phonebook.displayPhoneBook();
        int search_index;
        int contactsToShow = (phonebook.getTotalContacts() <= 8) ? phonebook.getTotalContacts() : 8;
        while (true)
        {
          std::cout << std::endl;
          std::cout << "Search by index: ";
          std::cin >> search_index;
          if (search_index < 1 || search_index > 8)
          {
              std::cout << std::endl << RED << "Invalid input. Please enter a number of range [1-8]." << RESET << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
              continue;
          }
          if (search_index > 0 && search_index <= contactsToShow)
          {
            std::cout << std::endl;
            phonebook.searchContact(search_index - 1);
            break;
          }
          else
            std::cout << std::endl
                      << RED << "Contact does not exist with this index" << "" << RESET << std::endl;
        }
      }
    }
    else if (input.compare("EXIT") != 0)
      std::cout << std::endl
                << RED << "Invalid input" << RESET << std::endl;
    std::cout << std::endl;
  }
  return 0;
}