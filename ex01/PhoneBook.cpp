#include "PhoneBook.hpp"
#include <iomanip>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

PhoneBook::PhoneBook()
{
  index = 0;
  totalContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(Contact contact)
{
  contacts[index] = contact;
  index = (index + 1) % 8;
  totalContacts++;
}

void PhoneBook::searchContact(int index)
{
  std::cout << contacts[index].getValues() << std::endl;
}

int PhoneBook::getTotalContacts()
{
  return totalContacts;
}

std::string PhoneBook::formatField(std::string text) const
{
  if (text.length() > 10) {
    return text.substr(0, 9) + ".";
  }
  return text;
}

void PhoneBook::displayPhoneBook()
{
  std::cout << std::setw(10) << std::right << YELLOW << "\033[1mINDEX\033[0m" << RESET << " | ";
  std::cout << std::setw(10) << std::right << "\033[1mFIRST NAME" << " | ";
  std::cout << std::setw(10) << std::right << "LAST NAME" << " | ";
  std::cout << std::setw(10) << std::right << "NICK NAME\033[0m" << std::endl;

  int contactsToShow = (totalContacts <= 8) ? totalContacts : 8;

  for (int i = 0; i < contactsToShow; i++)
  {
    std::cout << std::setw(10) << std::right << YELLOW << i + 1 << RESET << " | ";
    std::cout << std::setw(10) << std::right << formatField(contacts[i].getFirstname()) << " | ";
    std::cout << std::setw(10) << std::right << formatField(contacts[i].getLastname()) << " | ";
    std::cout << std::setw(10) << std::right << formatField(contacts[i].getNickname()) << std::endl;
  }
}