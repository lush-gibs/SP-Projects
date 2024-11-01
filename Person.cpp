#include "Person.h"

Person::Person() {
    firstName = "";
    surName = "";
    exam = 0;
    grade = 0;
    HW = {0};
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


void Person::setFirstName(const string& firstName) { this->firstName = firstName; }
string Person::getfirstName() { return firstName; }

void Person::setSurname(const string& surName) { this->surName = surName; }
string Person::getSurname() { return surName; };

void Person::setExamScore(double exam) { this->exam = exam;}
double Person::getExamScore() { return exam; }

void Person::setHomework(const vector<double> HW){ this->HW = HW; }
vector <double> Person::getHomework() { return HW; }

double Person::getGrade() { return grade; }

double Median(vector<double>& list) {
    double Median;

    int length = list.size();

    if (length == 0) return 0;

    sort(list.begin(), list.end());

    if (length % 2 == 0) {
        int mid = length / 2;
        int mid1 = mid - 1;

        Median = (list[mid] + list[mid1]) / 2;
    }
    else Median = list[length / 2];

    return Median;
}

double average(vector<double>& list)
{
    double average = (accumulate(list.begin(), list.end(), 0.0) / list.size());

    return average;
}

void Person::calcFinalGrade(int n) {

    if (n == 1) {
        grade = 0.4 * average(HW) + 0.6 * exam;
    }
    else if (n == 2)
        grade = 0.4 * Median(HW) + 0.6 * exam;
}

void Person::calcMedian()
{   
    grade = 0.4 * Median(HW) + 0.6 * exam; 
}
void Person::calcAverage()
{
    grade = 0.4 * average(HW) + 0.6 * exam;
}

istream& operator>>(istream& input, Person& p) {

    string firstName, surName;
    double exam, hw;
    vector <double> h;

    cout << "\nPlease enter student's name and surname: ";
    cin >> firstName >> surName;
    p.setFirstName(firstName);
    p.setSurname(surName);

    cout << "1. Input Exam Score\t 2. Generate random exam Score\nPlease input option 1 or 2: ";     // collects exam score from user
    int n;
    cin >> n;

    while(true)                                 // Loop to ask if user wants to input or generate exam score
    {   
        if (n == 1)
        {
            cout << "Please enter student's exam score: ";
            cin >> exam;

            while (exam < 0 || exam > 100)              // loop to collect only valid exam score from 0 to 100
            {
                cout << "Invalid Score, Please input exam score from 0 - 100: ";                    
                cin >> exam;
            }

            p.setExamScore(exam);
            break;
        }
        else if (n == 2)
        {
            exam = rand() % 100 + 1;
            cout << exam << " generated" << endl << endl;
            p.setExamScore(exam);
            break;
        }
        else
        {
            cout << "Invalid input! Please input option 1 or 2: ";
            cin >> n;
        }
    }

    cout << "1. Add homework\t 2.No Homework\t 3.Randomize Homework\nPlease input option 1,2 or 3: ";    
    int i; 
    cin >> i;

    while(true)                                                                     // Loop to enter homework scores
    {
        if (i == 2)
            break;

        else if (i == 1)
        {
            int j = 0;
            do
            {
                cout << "\nPlease enter '-1' to finish or Input Homework " << ++j << ": ";
                cin >> hw;

                h.push_back(hw);
            } while (hw != -1);

            p.setHomework(h);
            break;
        }
        else if (i == 3)
        {
            cout << "Input number of homeworks to generate randomly: ";
            int j;
            cin >> j;

            for (int i = 0; i < j; i++)
            {
                hw = rand() % 100 + 1.00;           // generates random number for homework between 1 and 100
                cout << hw << " generated" << endl;

                h.push_back(hw);
            }

            p.setHomework(h);
            break;
        }
        else
        {
            cout << "Invalid input! Please input option 1,2 or 3: ";
            cin >> i;
        }    
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