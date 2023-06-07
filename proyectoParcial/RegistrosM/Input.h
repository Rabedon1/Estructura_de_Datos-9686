#ifndef INPUT_H
#define INPUT_H
#include <string>

class Input {
    
    public:
        int integerNumber(const char *instructionMessage, int charAmount);
        double realNumber(const char *instructionMessage, int charAmount);
        char *letters(const char *instructionMessage, int charAmount);
        char *claves(const char *instructionMessage, int charAmount);
        char *ET(const char *instructionMessage, int charAmount);
        static bool isValid(const std::string &idCard);
};

#endif
