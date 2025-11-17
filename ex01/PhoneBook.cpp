#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _totalContacts(0)
{

}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(Contact contact)
{
  _contacts[_index] = contact;
  _index = (_index + 1) % 8;
  _totalContacts++;
}

void PhoneBook::searchContact(int index) const
{
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(FIRST) << std::endl;
    std::cout << BOLD << "Last name: " << RESET << _contacts[index].getData(LAST) << std::endl;
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(NICK) << std::endl;
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(PHONE) << std::endl;
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(SECRET) << std::endl;
}

int PhoneBook::getTotalContacts() const
{
  return _totalContacts;
}

std::string PhoneBook::_formatField(std::string text) const
{
  if (text.length() > 10) {
    return text.substr(0, 9) + ".";
  }
  return text;
}

void PhoneBook::displayPhoneBook() const
{
  std::cout << std::setw(6) << std::right << YELLOW << BOLD << "INDEX" << RESET << " | ";
  std::cout << std::setw(6) << std::right << BOLD << "FIRST NAME" << " | ";
  std::cout << std::setw(7) << std::right << "LAST NAME" << " | ";
  std::cout << std::setw(6) << std::right << "NICK NAME" << RESET << std::endl;

  int contactsToShow = (_totalContacts <= 8) ? _totalContacts : 8;

  for (int i = 0; i < contactsToShow; i++)
  {
    std::cout << std::setw(10) << std::right << YELLOW << i + 1 << RESET << " | ";
    std::cout << std::setw(10) << std::right << _formatField(_contacts[i].getData(FIRST)) << " | ";
    std::cout << std::setw(10) << std::right << _formatField(_contacts[i].getData(LAST)) << " | ";
    std::cout << std::setw(10) << std::right << _formatField(_contacts[i].getData(NICK)) << std::endl;
  }
}