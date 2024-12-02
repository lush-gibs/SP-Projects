#include "Utilities.h"

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

void clearWrongInputs()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "invalid input!\n";
}

vector<Person> randomizePersons()
{
	vector<Person> randomStudents;
	vector<double> hw;
	int n;

	cout << "Please input number of students you want to randomize: ";

	while (true)
	{
		cin >> n;
		if (cin.fail())
		{
			clearWrongInputs();

			cout << "Input a number: ";
		}
		else
			break;
	}

    auto start = high_resolution_clock::now();

	for (int i = 1; i <= n; i++)
	{
		Person p;
		hw.clear();

		p.setFirstName("Name" + std::to_string(i));
		p.setSurname("Surname" + std::to_string(i));

		for (int j = 0; j < 6; j++)
		{
			double homework = rand() % 11;
			hw.push_back(homework);
		}

		p.setHomework(hw);

		double exam = rand() % 11;
		p.setExamScore(exam);

		p.calcFinalGrade(1);

		randomStudents.push_back(p);
	}

    std::chrono::duration<double> duration = high_resolution_clock::now() - start;
    cout << "\nRandomizing and pushing n number of students into a vector takes " << duration.count() << " seconds\n";

	return randomStudents;
}

void gradeSplitter_2Vects(vector <Person>& students, vector <Person>& Passed, vector <Person>& Failed)
{
    auto start = high_resolution_clock::now();

	auto it = std::partition(students.begin(), students.end(), [](Person& s) {return s.getGrade() >= 5; });

	Passed = vector<Person>(students.begin(), it);
	Failed = vector<Person>(it, students.end());

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to split the vector into two containers: " << duration.count() << " seconds\n";
}

void gradeSplitter_2Lists(list <Person>& students, list <Person>& Passed, list <Person>& Failed)
{
	auto start = high_resolution_clock::now();

	std::partition_copy(students.begin(), students.end(), back_inserter(Passed), back_inserter(Failed), [](Person& s) {return s.getGrade() >= 5; });

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to split the list into two containers: " << duration.count() << " seconds\n";
}

void gradeSplitter_2Deques(deque <Person>& students, deque <Person>& Passed, deque <Person>& Failed)
{
	auto start = high_resolution_clock::now();

	std::partition_copy(students.begin(), students.end(), back_inserter(Passed), back_inserter(Failed), [](Person& s) {return s.getGrade() >= 5; });

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to split the deque into two containers: " << duration.count() << " seconds\n";
}

void splitGrades_1Vect(vector<Person>& students,vector<Person>& other)
{
	auto start = high_resolution_clock::now();

	auto it = std::partition(students.begin(), students.end(), [](Person& s) {return s.getGrade() >= 5; });

	other = vector<Person> (it, students.end());

	students.erase(it, students.end());

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to split the vector into one container and resize: " << duration.count() << " seconds\n";
}

void splitGrades_1List(list<Person>& students, list<Person>& other)
{
	auto start = high_resolution_clock::now();

    students.remove_if([&other](Person& s) {if (s.getGrade() < 5) { other.push_back(s); return true; } return false;});

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to split the list into one container: " << duration.count() << " seconds\n";
}
 
void splitGrades_1Deque(deque<Person>& students, deque<Person>& other)
 {
	auto start = high_resolution_clock::now();

	auto it = std::remove_if(students.begin(), students.end(), [&other](Person& s) {if (s.getGrade() < 5) { other.push_back(s); return true;} return false;});

	students.erase(it, students.end());

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;

	cout << "Time taken to split the deque into one container and resize: " << duration.count() << " seconds\n";
 }

void gradeSorter_Vect(vector <Person>& students)
{
	auto start = high_resolution_clock::now();

	sort(students.begin(), students.end(), [](Person& a, Person& b) { return a.getGrade() > b.getGrade(); });

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to sort the vector of students: " << duration.count() << " seconds\n";
}

void gradeSorter_List(list <Person>& students)
{
	auto start = high_resolution_clock::now();

	students.sort([](Person& a, Person& b) { return a.getGrade() > b.getGrade(); });

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to sort the list of students: " << duration.count() << " seconds\n";
}

void gradeSorter_Deque(deque <Person>& students)
{
	auto start = high_resolution_clock::now();

	sort(students.begin(), students.end(), [](Person& a, Person& b) { return a.getGrade() > b.getGrade(); });

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to sort the deque of students: " << duration.count() << " seconds\n";
}

void printGrades_AverAndMed(vector<Person>& students)
{
    cout << left << setw(20) << "Name"                   //format for header of file
        << setw(20) << "Surname"
        << right << setw(20) << "Final (Avg. )" << " | "
        << left << setw(20) << "Final (Med. )" << endl;

    string line(79, '-');           //to get accurate width of line but it's not accurate for some reason, even though 83 is the width of previous line
    cout << line << endl;

    for (auto& student : students)             //loops through persons and  calculates Average and median and then prints each line in the file with results in console.
    {
        cout << left << student;

        student.calcAverage();
        cout << fixed << setprecision(2) << right << setw(20) << student.getGrade() << " | ";

        student.calcMedian();
        cout << fixed << setprecision(2) << setw(15) << student.getGrade() << endl;
    }
}

void printGrades_AverOrMed(vector<Person>& students)
{
    cout << "\nCalculate Grade with:\n1. Average\n2. Median\n";
    int m;

    while (true)
    {
        cout << "Please press 1 or 2: ";
        cin >> m;

        if (cin.fail())                                 //exception handler to control input that are not intergers of type int.
            clearWrongInputs();
        else if (m == 1 || m == 2)
            break;
        else
            cout << "Invalid selection!\n";
    }

    cout.setf(ios::left);           //formats header for manual input of students
    cout.width(20);
    cout << "Name";
    cout.width(20);
    cout << "Surname";
    cout.width(20);
    cout << ((m == 1) ? "Final_point(Aver.)" : "Final_point(Median)") << endl;
    string line(60, '-');
    cout << line << endl;

    for (Person& student : students)
    {
        cout << student;        //calls overloaded cout to print first and last name of student

        student.calcFinalGrade(m);                  //calculates and updates the grade member of persons class based on user's choice

        cout << fixed << setw(20) << setprecision(2) << student.getGrade() << endl;
    }
}
