#include <iostream>
#include <string>

class QueueException {
    public:
        QueueException(std::string s) : str(s) {}
        ~QueueException() {}
        void what() {
            std::cout << str << std::endl;
        }

    private:
        std::string str;
};