#ifndef _STUDENT_H_
#define _STUDENT_H_

using namespace std;

class Student {
    private:
        string name;
        string course;
        int age;

    public:
        Student(string n, string c, int a) : name(n), course (c) {
            //cout << "In STUDENT constructor" << endl;
            age = a;
        }

        ~Student() {
            //cout << "In STUDENT destructor" << endl;
        }

        string getName() {
            return name;
        }

        string getCourse() {
            return course;
        }

        int getAge() {
            return age;
        }
};

#endif