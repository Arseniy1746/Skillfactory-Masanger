#pragma once
#include <string>

class User {
private:
    std::string User_Name; //Имя пользователя
    std::string Password; //Пароль пользователя
    int ID; //Ид пользователя

public:
    User(std::string user_name, std::string password, int id);
    ~User();

    void SetName(std::string NewName);
    std::string GetName() const;
    std::string GetPassword() const;
    int GetID() const;
};