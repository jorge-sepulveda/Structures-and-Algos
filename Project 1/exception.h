#include <iostream>
#include <string>

class ArrayException {
    public:
        ArrayException(std::string s) : str(s) {}
        ~ArrayException() {}
        void what() {
            std::cout << str << std::endl;
        }

    private:
        std::string str;
};