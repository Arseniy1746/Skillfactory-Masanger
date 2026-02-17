#include <iostream>
#include <memory>
#include <locale.h>
#include "User.h"
#include "Message.h"
#include "SimpleArray.h"

using namespace std;

// Глобальные переменные
const int MAX_USERS = 10;
const int MAX_MESSAGES = 30;

std::unique_ptr<User> Users[MAX_USERS]; //Обьявили масив пользователей
int NumUsers = 0;

SimpleArray<Message, MAX_MESSAGES> PublicChat; //С помощью шаблона создали публичгый чат
SimpleArray<Message, MAX_MESSAGES> PrivateMessages[MAX_USERS]; //Обьявили масив приватных чатов

int CurrentUserID = -1;

// Меню
void Register_Menu() {
    cout << endl << "        ========================== " << endl;
    cout << "        |        Ч А Т           |" << endl;
    cout << "        |                        |" << endl;
    cout << "        | 1. Регистрация         |" << endl;
    cout << "        | 2. Вход                |" << endl;
    cout << "        | 3. Выход из программы  |" << endl;
    cout << "        ==========================" << endl;
    cout << "Выберите действие: ";
}

void User_Menu() {
    cout << endl << "        ==========================" << endl;
    cout << "        |   Добро пожаловать!    |" << endl;
    cout << "        | 1. Написать всем       |" << endl;
    cout << "        | 2. Личное сообщение    |" << endl;
    cout << "        | 3. Показать общий чат  |" << endl;
    cout << "        | 4. Показать мои ЛС     |" << endl;
    cout << "        | 5. Выйти из аккаунта   |" << endl;
    cout << "        | 6. Список пользователей|" << endl;
    cout << "        ==========================" << endl;
    cout << "Выберите действие: ";
}





int main()
{
    setlocale(LC_ALL, "Russian");

    bool Exit = false;

    cout << "Простой консольный чат" << endl;
    cout << "Вводите числа для выбора пунктов меню и ID" << endl;
    cout << "Сообщения, имена и пароли — одно слово без пробелов" << endl << endl;

    while (!Exit)
    {
        try
        {
            if (CurrentUserID == -1) {
                Register_Menu();

                int choice = 0;
                cin >> choice;

                switch (choice) {
                case 1: // Регистрация
                    if (NumUsers >= MAX_USERS) {
                        cout << "Лимит пользователей достигнут (макс. 10)" << endl;
                        break;
                    }

                    {
                        string name, pass;
                        cout << "Имя (без пробелов): ";
                        cin >> name;
                        cout << "Пароль (без пробелов): ";
                        cin >> pass;

                        Users[NumUsers] = std::make_unique<User>(name, pass, NumUsers);
                        cout << "Создан пользователь: " << name << endl;
                        cout << "Ваш ID: " << NumUsers << " — запомните!" << endl;
                        NumUsers++;
                    }
                    break;

                case 2: // Вход
                {
                    int id = 0;
                    string pass;
                    cout << "ID: ";
                    cin >> id;
                    cout << "Пароль: ";
                    cin >> pass;

                    if (id < 0 || id >= NumUsers || !Users[id]) {
                        cout << "Нет такого ID" << endl;
                        break;
                    }

                    if (Users[id]->GetPassword() != pass) {
                        cout << "Неверный пароль" << endl;
                        break;
                    }

                    CurrentUserID = id;
                    cout << "Добро пожаловать, " << Users[id]->GetName() << "!" << endl;
                }
                break;

                case 3:
                    Exit = true;
                    cout << "До свидания!" << endl;
                    break;

                default:
                    cout << "Нет такого пункта меню" << endl;
                }
            }
        }
        catch (...)
        {

        }
    }
}
