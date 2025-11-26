#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  std::string _phone;
  std::string _secret;
  
public:
  enum Data
  {
    FIRST,
    LAST,
    NICK,
    PHONE,
    SECRET
  };

  Contact();
  Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
  ~Contact();
  std::string getData(Data data) const;
};


#endif