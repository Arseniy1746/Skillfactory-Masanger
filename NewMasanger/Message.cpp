#include "Message.h"
Message::Message(std::string from, std::string txt, int recipient) : from_name(from), text(txt), to_id(recipient){}

std::string Message::GetFrom() const
{
    return from_name;
}

std::string Message::GetText() const
{
    return text;
}

int Message::GetToID() const
{
    return to_id;
}

bool Message::IsPrivate() const
{
    return to_id != -1;
}

void Message::Print() const
{
    if (IsPrivate()) 
    {
        std::cout << "[หั] " << from_name << " -> " << to_id << ": " << text << std::endl;
    }
    else 
    {
        std::cout << from_name << ": " << text << std::endl;
    }
}