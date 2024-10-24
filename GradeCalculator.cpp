#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <cstdlib> 
#include <ctime>

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
    double calcFinalGrade(int n);
};
Person::Person() {
    firstName = "";
    surName = "";
    exam = 0;
    grade = 0;
    HW = {};
}
Person::Person(string firstName, string surName, double exam, double grade, vector<double> HW) : firstName(firstName), surName(surName), exam(exam), grade(grade), HW(HW) {}
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
double Median(vector<double>& list) {
    double Median;

    int length = list.size();

    if(length == 0) return 0;

    sort(list.begin(),list.end());

    if (length % 2 == 0) {
        int mid = length / 2 ;
        int mid1 = mid - 1;

        Median = (list[mid] + list[mid1])/2;
    }
    else Median = list[length / 2];
    
    return Median;
}

double Person::calcFinalGrade(int n) {
    double finalGrade = 0;

    if (n == 1){
        double average = accumulate(HW.begin(), HW.end(), 0.0)/HW.size();
        finalGrade = 0.4 * average + 0.6 * exam;
    } 
    else if (n == 2)
        finalGrade = 0.4 * Median(HW) + 0.6 * exam;

    return finalGrade;
}
istream& operator>>(istream& input, Person& p) {
    cout << "\nPlease enter student's name and surname: " ;
    input >> p.firstName >> p.surName;
    
    int n = 0;
    int i = 0;                                                                           // variable i to track number of homework request prompts
    do
    {
        cout << ((i == 0)? "\n1.Add Homework\n2.No Homework\nPress '1' to Add OR '2' to Skip: " : 
        "\nPress '1' to continue adding homework OR '2' to finish: " );                //prompt to ask User if there is homework or notcle
        input >> n;

        if(i == 0 & n == 2)         // put zero in vector when no homework is  selected
            p.HW.push_back(0.00);
        
        if(n == 1)
        {
            cout << "\n1. Input Homework Score\n2. Randomize Score\nInput option '1' or '2': ";
            int q;
            input >> q;
        
            double hw;

            if (q == 1)
            {
                cout << "Input Homework " << i + 1 << ": ";
                input >> hw;
            }
            else if (q == 2)
            {   
                hw = rand() % 100 + 1.00;           // generates random number for homework between 1 and 100
                cout << hw << " generated" << endl;
            }

            i++;
            p.HW.push_back(hw);                                           
                
        }
    }
    while(n != 2);
    
    cout << "1. Input Exam Score\n 2. Generate exam Score\n Please input option 1 or 2: ";
    int s;
    input >> s;

    if (s == 1)
    {
        cout << "Please enter student's exam score: ";
        input >> p.exam;
    }
    else if (s == 2)
    {
        p.exam = rand() % 100 + 1;
        cout << p.exam << " generated" << endl << endl;
    }
    
    return input;
}
ostream& operator<<(ostream& out, Person& p) {
    cout.setf(ios::left);
    out.width(20);
    out << p.firstName;
    out.width(20);
    out << p.surName;

    return out;
}
int main() {
    srand(time(0));

    cout << "Please input number of students: ";
    int n;
    cin >> n;

    cout << "\nCalculate Grade with:\n1. Average\n2. Median\ninput 1 for average and 2 for median: " ;
    int m;
    cin >> m;

    vector<Person> arr(n);

    for (Person& student : arr)  {
        cin >> student;
    }

    cout.setf(ios::left);
    cout.width(20);
    cout << "Name";
    cout.width(20);
    cout << "Surname";
    cout.width(20);
    cout << ((m == 1) ? "Final_point(Aver.)" : "Final_point(Median)")  << endl;
    cout << "------------------------------------------------------------" << endl;

    for (Person& student : arr) {
        cout << student;
        cout.width(20);
        cout << fixed << setprecision(2) << student.calcFinalGrade(m) << endl;
    }

    return 0;
}
