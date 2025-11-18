#include "Contact.hpp"
#include "PhoneBook.hpp"

void contactPrompt(std::string &fname, std::string &lname, std::string &nick, std::string &phone, std::string &secret)
{
  while (fname.empty())
  {
    std::cout << "\033[1mEnter first name: \033[0m";
    std::getline(std::cin, fname);
    if (fname.empty())
      std::cout << "\033[31mFirst name cannot be empty!\033[0m" << std::endl;
  }
  while (lname.empty())
  {
    std::cout << "\033[1mEnter last name: \033[0m";
    std::getline(std::cin, lname);
    if (lname.empty())
      std::cout << "\033[31mLast name cannot be empty!\033[0m" << std::endl;
  }
  while (nick.empty())
  {
    std::cout << "\033[1mEnter nick name: \033[0m";
    std::getline(std::cin, nick);
    if (nick.empty())
      std::cout << "\033[31mNick name cannot be empty!\033[0m" << std::endl;
  }
  while (phone.empty())
  {
    std::cout << "\033[1mEnter phone number: \033[0m";
    std::getline(std::cin, phone);
    if (phone.empty())
      std::cout << "\033[31mPhone number cannot be empty!\033[0m" << std::endl;
  }
  while (secret.empty())
  {
    std::cout << "\033[1mEnter your darkest secret: \033[0m";
    std::getline(std::cin, secret);
    if (secret.empty())
      std::cout << "\033[31mDarkest secret cannot be empty!\033[0m" << std::endl;
  }
}

int main()
{
  std::string input;
  PhoneBook phonebook;

  while (input.compare("EXIT") != 0)
  {
    std::cout << "\033[1mPlease insert ADD, SEARCH or EXIT\033[0m" << std::endl;
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
        std::cout << "\033[32mContact #" << slotDisplay << " created\033[0m" << std::endl;
      else
        std::cout << "\033[33mContact #" << slotDisplay << " updated\033[0m" << std::endl;
      std::cout << std::endl;
    }
    else if (input.compare("SEARCH") == 0)
    {
      if (phonebook.getTotalContacts() == 0)
        std::cout << std::endl
                  << "\033[31mPhonebook is empty. Add some contacts first!\033[0m" << std::endl;
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
          if (!(std::cin >> search_index))
          {
            std::cout << std::endl
                      << "\033[31mInvalid input. Please enter a number of range [1-" << contactsToShow << "].\033[0m" << std::endl;
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
                      << "\033[31mContact does not exist with this index" << "\033[0m" << std::endl;
        }
      }
    }
    else if (input.compare("EXIT") != 0)
      std::cout << std::endl
                << "\033[31mInvalid input\033[0m" << std::endl;
    std::cout << std::endl;
  }
  return 0;
}