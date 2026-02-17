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

std::unique_ptr<User> Users[MAX_USERS]; //Создали масив пользователей
int NumUsers = 0;

SimpleArray<Message, MAX_MESSAGES> PublicChat; //С помощью шаблона создали публичгый чат
SimpleArray<Message, MAX_MESSAGES> PrivateMessages[MAX_USERS]; //Создали масив приватных чатов

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

}
