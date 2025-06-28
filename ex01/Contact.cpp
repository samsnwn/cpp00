#include "Contact.hpp"

Contact::Contact(string firstname, string lastname, string nickname, string phone, string secret)
{
  this->firstname=firstname;
  this->lastname=lastname;
  this->nickname=nickname;
  this->phone=phone;
  this->secret=secret;
}

Contact::~Contact()
{
}

string Contact::getValues() const 
{
  return  "\033[1mFirst name: \033[0m" + firstname + "\n" + 
          "\033[1mLast name: \033[0m" + lastname + "\n" +
          "\033[1mNick name: \033[0m" + nickname + "\n" +
          "\033[1mPhone Number: \033[0m" + phone + "\n" +
          "\033[1mDarkest Secret: \033[0m" + secret + "\n";
}

string Contact::getFirstname() const
{
  return firstname;
}
string Contact::getLastname() const
{
  return lastname;
}
string Contact::getNickname() const
{
  return nickname;
}


