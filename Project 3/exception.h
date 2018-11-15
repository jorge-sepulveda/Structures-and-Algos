#include <iostream>
#include <string>

class PQException {
    public:
        PQException(std::string s) : str(s) {}
        ~PQException() {}
        void what() {
            std::cout << str << std::endl;
        }

    private:
        std::string str;
};