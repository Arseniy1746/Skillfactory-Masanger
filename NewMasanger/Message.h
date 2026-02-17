#pragma once
#include <string>
#include <iostream>

class Message {
private:
    std::string from_name;
    std::string text;
    int to_id;          // -1 = всем, иначе ID получателя

public:
    Message(std::string from, std::string txt, int recipient = -1);

    std::string GetFrom() const;
    std::string GetText() const;
    int GetToID() const;

    bool IsPrivate() const;

    void Print() const;
};