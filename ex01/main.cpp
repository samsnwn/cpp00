#include "Contact.hpp"
#include "PhoneBook.hpp"

void contactPrompt(string &fname, string &lname, string &nick, string &phone, string &secret)
{

  do
  {
    std::cout << "\033[1mEnter first name: \033[0m";
    std::getline(std::cin, fname);
    if (fname.empty())
      std::cout << "\033[31mFirst name cannot be empty!\033[0m" << std::endl;
  } while (fname.empty());

  do
  {
    std::cout << "\033[1mEnter last name: \033[0m";
    std::getline(std::cin, lname);
    if (lname.empty())
      std::cout << "\033[31mLast name cannot be empty!\033[0m" << std::endl;
  } while (lname.empty());

  do
  {
    std::cout << "\033[1mEnter nick name: \033[0m";
    std::getline(std::cin, nick);
    if (nick.empty())
      std::cout << "\033[31mNick name cannot be empty!\033[0m" << std::endl;
  } while (nick.empty());

  do
  {
    std::cout << "\033[1mEnter phone number: \033[0m";
    std::getline(std::cin, phone);
    if (phone.empty())
      std::cout << "\033[31mPhone number cannot be empty!\033[0m" << std::endl;
  } while (phone.empty());

  do
  {
    std::cout << "\033[1mEnter your darkest secret: \033[0m";
    std::getline(std::cin, secret);
    if (secret.empty())
      std::cout << "\033[31mDarkest secret cannot be empty!\033[0m" << std::endl;
  } while (secret.empty());
}

int main()
{
  string input;
  PhoneBook phonebook;

  while (input.compare("EXIT") != 0)
  {
    std::cout << "\033[1mPlease insert ADD, SEARCH or EXIT\033[0m" << std::endl;
    std::cin >> input;
    if (input.compare("ADD") == 0)
    {
      std::cout << std::endl;
      std::cin.ignore(); // Clear leftover newline from reading "ADD"
      string fname, lname, nick, phone, secret;
      if (phonebook.getTotalContacts() == 0)
      {
        for (int i = 0; i < 8; ++i)
        {
          contactPrompt(fname, lname, nick, phone, secret);
          Contact newContact(fname, lname, nick, phone, secret);
          phonebook.addContact(newContact);
          std::cout << "\033[32mContact #" << i + 1 << " created\033[0m" << std::endl;
          std::cout << std::endl;
        }
      }
      else if (phonebook.getTotalContacts() > 0)
      {
        contactPrompt(fname, lname, nick, phone, secret);
        Contact newContact(fname, lname, nick, phone, secret);
        phonebook.addContact(newContact);
        std::cout << std::endl;
      }
    }
    else if (input.compare("SEARCH") == 0)
    {
      if (phonebook.getTotalContacts() == 0)
      {
        std::cout << std::endl << "\033[31mPhonebook is empty. Add some contacts first!\033[0m" << std::endl;
      }
      else
      {
        int search_index;
        std::cout << std::endl;
        phonebook.displayPhoneBook();
        while (true)
        {
          std::cout << std::endl;
          std::cout << "Search by index: ";
          if (!(std::cin >> search_index))
          {
            std::cout << std::endl << "\033[31mInvalid input. Please enter a number.\033[0m" << std::endl;
            std::cin.clear();            // Clear error flags
            std::cin.ignore(1000, '\n'); // Skip bad input
            continue;                    // Go back to start of while loop
          }
          if (search_index > 0 && search_index <= 8)
          {
            std::cout << std::endl;
            phonebook.searchContact(search_index - 1); // Convert user index (1-8) to array index (0-7)
            break;
          }
          else
            std::cout << std::endl << "\033[31mInvalid index. valid range [1-8].\033[0m" << std::endl;
          std::cout << std::endl;
        }
      }
    }
    else if (input.compare("EXIT") != 0)
      std::cout << std::endl << "\033[31mInvalid input\033[0m" << std::endl;
    std::cout << std::endl;
  }
  return 0;
}