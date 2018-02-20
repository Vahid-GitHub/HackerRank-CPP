#include <iostream>
#include <string>
#include <sstream>

class Person {
    public:
        std::string name;
        short age;
        virtual void getdata() = 0;
        virtual void putdata() = 0;
    };

class Professor: public Person {
    short publications;
    static short curid;
    short cur_id;
    public:
        void getdata() {
            std::cin >> name >> age >> publications;
            //std::cin.ignore(INT_MAX);
            Professor::curid++;
            cur_id = curid;
        };
        void putdata() {
            std::cout << name << " " << age << " " << publications << " " << cur_id << std::endl;
        };
};

class Student: public Person {
    short marks[6];
    static short curid;
    short cur_id;
    public:
        void getdata() {
            std::cin.ignore();
            std::string line;
            std::getline(std::cin, line);
            std::istringstream isline(line);
            isline >> name;
            isline >> age;
            for (int i = 0; i < 6; i++) {
                isline >> marks[i];
            }
            Student::curid++;
            cur_id = curid;
        };
        void putdata() {
            long sumofmarks = 0;
            for (int i = 0; i < 6; i++) {
                sumofmarks += marks[i];
            }
            std::cout << name << " " << age << " " << sumofmarks << " " << cur_id << std::endl;
        };
};

short Professor::curid = 0;
short Student::curid = 0;

int main() {
    int n, val;
    std::cin >> n; //The number of objects that is going to be created.
    Person *per[n];
    for(int i = 0;i < n;i++){
        //std::cout << i << std::endl;
        std::cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else per[i] = new Student; // Else the current object is of type Student
        per[i]->getdata(); // Get the data from the user.
    }
    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.
    return 0;

}
