#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact(/* args */);
    ~Contact();

    void setFirstName(std::string& name);
    std::string getFirstName() const;

    void setLastName(std::string& name);
    std::string getLastName() const;

    void setNickname(std::string& nick);
    std::string getNickname() const;

    void setPhoneNumber(std::string& phone);
    std::string getPhoneNumber() const;

    void setDarkestSecret(std::string& darkSecret);
    std::string getDarkestSecret() const;

    void displayContact() const;
    bool isEmpty() const;
};

#endif