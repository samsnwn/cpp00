#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
  Contact contacts[8];
  int index;
  int totalContacts;
  std::string formatField(std::string text) const;

public:
  PhoneBook();
  ~PhoneBook();
  void addContact(Contact contact);
  void searchContact(int index);
  int getTotalContacts();
  void displayPhoneBook();
};

#endif