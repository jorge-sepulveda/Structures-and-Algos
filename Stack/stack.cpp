#include "stack.h"
#include "Student.h"

using namespace std;

int main () {
    

    try {
        
        Stack <Student> studentStack;

        Student s1( "John Doe" , "CSCE 221", 21);
        Student s2( "Jane Smith" , "CSCE 312", 22);
        
        studentStack.push(s1);
        studentStack.push(s2);
    
        Student s3 = studentStack.pop();
        cout << "Student Details: " << s3.getName() << ", " << s3.getCourse() << ", " << s3.getAge() << endl;

        Student s4 = studentStack.pop();
        cout << "Student Details: " << s4.getName() << ", " << s4.getCourse() << ", " << s4.getAge() << endl;

        Student s5 = studentStack.pop();
        cout << "Student Details: " << s5.getName() << ", " << s5.getCourse() << ", " << s5.getAge() << endl;
    } catch (StackException& se) {
        se.what();
    }
}