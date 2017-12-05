#include "InvalidInputException.h"

InvalidInputException::InvalidInputException(string str)
{
    this->str = str;
}

string InvalidInputException::getString() {
    return this->str;
}
