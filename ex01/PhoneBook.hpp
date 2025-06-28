#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
using std::string;

class PhoneBook {
  private:
    Contact contacts[8];
    int index;
    int totalContacts;
    string formatField(string text) const;

  public:
    PhoneBook();
    ~PhoneBook();
    void addContact(Contact contact);
    void searchContact(int index);
    int getTotalContacts();
    void displayPhoneBook();
};

#endif