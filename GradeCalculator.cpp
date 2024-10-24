#include <iostream>
#include <string>
#include <vector>
#include <iomanip>



using namespace std;

class Person {
private:
    string firstName, surName;
    double exam, grade;
    vector<double> HW;

public:
    Person();
    Person(string firstName, string surName, double exam, double grade, vector<double> HW);
    Person(const Person& other);
    ~Person();
    Person& operator= (const Person& other);
    friend istream& operator>>(istream& input, Person& p);
    friend ostream& operator<<(ostream& out, Person& p);
    double calcFinalGrade();
};

Person::Person() {
    firstName = "";
    surName = "";
    exam = 0;
    grade = 0;
    HW = {};
}

Person::Person(string firstName, string surName, double exam, double grade, vector<double> HW)
    : firstName(firstName), surName(surName), exam(exam), grade(grade), HW(HW) {}

Person::Person(const Person& other) {
    firstName = other.firstName;
    surName = other.surName;
    exam = other.exam;
    grade = other.grade;
    HW = other.HW;
}

Person::~Person() {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstName = other.firstName;
        surName = other.surName;
        exam = other.exam;
        grade = other.grade;
        HW = other.HW;
    }
    return *this;
}

double Person::calcFinalGrade() {
    double Average = 0;
    double finalGrade;
    for (int i = 0; i < HW.size(); i++) {
        Average += HW[i];
    }
    Average /= HW.size();
    finalGrade = 0.4 * Average + 0.6 * exam;
    return finalGrade;
}

istream& operator>>(istream& input, Person& p) {
    cout << "Please enter student's name and surname: ";
    input >> p.firstName >> p.surName;
    cout << "Please input how many homeworks were submitted by " << p.firstName << ": ";
    int n;
    input >> n;
    for (int i = 0; i < n; i++) {
        cout << "Input Homework " << i + 1 << " score: ";
        double score;
        input >> score;
        p.HW.push_back(score);
    }
    cout << "Please enter student's exam score: ";
    input >> p.exam;
    return input;
}

ostream& operator<<(ostream& out, Person& p) {
    cout.setf(ios::left);
    out.width(20);
    out << p.firstName;
    out.width(20);
    out << p.surName;
    out.width(20);
    out << fixed << setprecision(2) << p.calcFinalGrade();

    return out;
}

int main() {
    cout << "Please input number of students to calculate Final Grade based on average: ";
    int n;
    cin >> n;

    vector<Person> arr;

    for (int i = 0; i < n; i++) {
        Person student;
        cin >> student;
        arr.push_back(student);
    }

    cout.setf(ios::left);
    cout.width(20);
    cout << "Name";
    cout.width(20);
    cout << "Surname";
    cout.width(20);
    cout << "Final_point(Aver.)" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

