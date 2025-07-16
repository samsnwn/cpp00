#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
  std::string firstname;
  std::string lastname;
  std::string nickname;
  std::string phone;
  std::string secret;

public:
  std::string getFirstname() const;
  std::string getLastname() const;
  std::string getNickname() const;
  std::string getValues() const;
  Contact(std::string firstname = "", std::string lastname = "", std::string nickname = "", std::string phone = "", std::string secret = "");
  ~Contact();
};

#endif