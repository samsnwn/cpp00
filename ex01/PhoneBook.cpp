#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _totalContacts(0)
{

}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::addContact(Contact contact)
{
  int slotUsed = _index;
  _contacts[_index] = contact;
  _index = (_index + 1) % 8;
  _totalContacts++;
  return slotUsed + 1;
}

void PhoneBook::searchContact(int index) const
{
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(Contact::FIRST) << std::endl;
    std::cout << BOLD << "Last name: " << RESET << _contacts[index].getData(Contact::LAST) << std::endl;
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(Contact::NICK) << std::endl;
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(Contact::PHONE) << std::endl;
    std::cout << BOLD << "First name: " << RESET << _contacts[index].getData(Contact::SECRET) << std::endl;
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
    std::cout << std::setw(10) << std::right << _formatField(_contacts[i].getData(Contact::FIRST)) << " | ";
    std::cout << std::setw(10) << std::right << _formatField(_contacts[i].getData(Contact::LAST)) << " | ";
    std::cout << std::setw(10) << std::right << _formatField(_contacts[i].getData(Contact::NICK)) << std::endl;
  }
}