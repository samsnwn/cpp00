#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

class PhoneBook
{
private:
  Contact _contacts[8];
  int _index;
  int _totalContacts;
  
public:
  PhoneBook();
  ~PhoneBook();
  int addContact(Contact contact);
  void searchContact(int index) const;
  int getTotalContacts() const;
  void displayPhoneBook() const;
  std::string _formatField(std::string text) const;
};

#endif