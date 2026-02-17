#include "User.h"

User::User(std::string user_name, std::string password, int id) : User_Name(user_name), Password(password), ID(id) {}

User::~User()
{
}

void User::SetName(std::string NewName)
{
    User_Name = NewName;
}

std::string User::GetName() const
{
    return User_Name;
}

std::string User::GetPassword() const
{
    return Password;
}

int User::GetID() const
{
    return ID;
}