#include "Contact.hpp"

Contact::Contact()
{
  
}

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret) :
_firstname(first), _lastname(last), _nickname(nick), _phone(phone), _secret(secret)
{
}

Contact::~Contact()
{
}

std::string Contact::getData(Data data) const
{
  switch (data)
  {
    case FIRST:
      return _firstname;
    case LAST:
      return _lastname;
    case NICK:
      return _nickname;
    case PHONE:
      return _phone;
    case SECRET:
      return _secret;
  }
}
