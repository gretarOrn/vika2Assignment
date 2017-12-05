#ifndef INVALIDINPUTEXCEPTION_H
#define INVALIDINPUTEXCEPTION_H


class InvalidInputException
{
    public:
        InvalidInputException(string str);
        string getString();

    private:
        string str;
};

#endif // INVALIDINPUTEXCEPTION_H
