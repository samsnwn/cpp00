#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
using std::string;

class Contact
{
private:
  string firstname;
  string lastname;
  string nickname;
  string phone;
  string secret;

public:
  string getFirstname() const;
  string getLastname() const;
  string getNickname() const;
  string getValues() const;
  Contact(string firstname = "", string lastname = "", string nickname = "", string phone = "", string secret = "");
  ~Contact();
};

#endif