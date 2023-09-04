#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student {
    string name;
    string surname;
    int age;
};

void InputStudents(Student*& students, int& num) {
    cout << "Enter the number of students: ";
    cin >> num;

    students = new Student[num]; // Выделяем динамический мас

    for (int i = 0; i < num; i++) {
        cout << "Enter student #" << i + 1 << " details (Name Surname Age): ";
        cin >> students[i].name >> students[i].surname >> students[i].age;
    }
}

void PrintStudents(const Student* students, int num) {
    cout << "Students' information:" << endl;

    cout << "======================================================" << endl;
    cout << "|| " << setw(5) << left << "Number " << "|| " << setw(10) << left << "Name" << "|| " << setw(13) << left << "Surname" << "|| " << setw(5) << right << "Age" << "     ||" << endl;
    cout << "======================================================" << endl;
    cout << endl;
    cout << endl;
    cout << "======================================================" << endl;
    for (int i = 0; i < num; i++) {
        cout << "||   " << setw(5) << left << i + 1 << "|| " << setw(10) << left << students[i].name << "|| " << setw(13) << left << students[i].surname << "|| " << setw(5) << right << students[i].age << "     ||" << endl;
        cout << "======================================================" << endl;
    }
}
void PrintFile(const Student* students, int num)
{
    ofstream fout;
    fout.open("DataBase.txt");

    fout << "Students' information:" << endl;

    fout << "======================================================" << endl;
    fout << "|| " << setw(5) << left << "Number " << "|| " << setw(10) << left << "Name" << "|| " << setw(13) << left << "Surname" << "|| " << setw(5) << right << "Age" << "     ||" << endl;
    fout << "======================================================" << endl;
    fout << endl;
    fout << endl;
    fout << "======================================================" << endl;
    for (int i = 0; i < num; i++) {
        fout << "||   " << setw(5) << left << i + 1 << "|| " << setw(10) << left << students[i].name << "|| " << setw(13) << left << students[i].surname << "|| " << setw(5) << right << students[i].age << "     ||" << endl;
        fout << "======================================================" << endl;
    }

}
int main() {
    Student* students = nullptr;
    int num = 0;

    InputStudents(students, num);
    PrintStudents(students, num);
    PrintFile(students, num);

    delete[] students; // Освобождаем память, выделенную под массив студентов

    return 0;
}
