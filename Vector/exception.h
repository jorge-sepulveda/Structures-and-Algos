#include <iostream>
#include <string>

class VectorException {
    public:
        VectorException(std::string s) : str(s) {}
        ~VectorException() {}
        void what() {
            std::cout << str << std::endl;
        }

    private:
        std::string str;
};