#include "OutputPerson.h"

void outputVectorToFile_HW_EX(const string& fileName, vector<Person> students)
{
	ofstream fileOut(fileName);

	if (!fileOut)
	{
		cerr << "File cannot be opened or created!";
		return;
	}

	fileOut << left
		<< setw(15) << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << "HW1"
		<< setw(15) << "HW2"
		<< setw(15) << "HW3"
		<< setw(15) << "HW4"
		<< setw(15) << "HW5"
		<< setw(15) << "HW6"
		<< setw(15) << "Exam"
		<< "\n";

	auto start = high_resolution_clock::now();

	for(auto& s: students)
	{
		fileOut << left << setw(15) << s.getfirstName() 
				<< setw(15) << s.getSurname();

		for (auto& h: s.getHomework())
		{
			fileOut << setw(15) << std::defaultfloat << h; 
		}

		fileOut << setw(15) << s.getExamScore();

		fileOut << "\n";
	}

	fileOut.close();
	std::chrono::duration<double> duration = high_resolution_clock::now() - start;

	cout << "Writing n number of students from a vector to a file takes " << duration.count() << " seconds\n";
}

void outputListToFile_HW_EX(const string& fileName, list<Person> students)
{
	ofstream fileOut(fileName);

	if (!fileOut)
	{
		cerr << "File cannot be opened or created!";
		return;
	}

	fileOut << left
		<< setw(15) << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << "HW1"
		<< setw(15) << "HW2"
		<< setw(15) << "HW3"
		<< setw(15) << "HW4"
		<< setw(15) << "HW5"
		<< setw(15) << "HW6"
		<< setw(15) << "Exam"
		<< "\n";

	auto start = high_resolution_clock::now();

	for (auto& s : students)
	{
		fileOut << left << setw(15) << s.getfirstName()
			<< setw(15) << s.getSurname();

		for (auto& h : s.getHomework())
		{
			fileOut << setw(15) << std::defaultfloat << h;
		}

		fileOut << setw(15) << s.getExamScore();

		fileOut << "\n";
	}

	fileOut.close();
	std::chrono::duration<double> duration = high_resolution_clock::now() - start;

	cout << "Writing n number of students from a vector to a file takes " << duration.count() << " seconds\n";
}

void outputListToFile_HW_EX(const string& fileName, deque<Person> students)
{
	ofstream fileOut(fileName);

	if (!fileOut)
	{
		cerr << "File cannot be opened or created!";
		return;
	}

	fileOut << left
		<< setw(15) << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << "HW1"
		<< setw(15) << "HW2"
		<< setw(15) << "HW3"
		<< setw(15) << "HW4"
		<< setw(15) << "HW5"
		<< setw(15) << "HW6"
		<< setw(15) << "Exam"
		<< "\n";

	auto start = high_resolution_clock::now();

	for (auto& s : students)
	{
		fileOut << left << setw(15) << s.getfirstName()
			<< setw(15) << s.getSurname();

		for (auto& h : s.getHomework())
		{
			fileOut << setw(15) << std::defaultfloat << h;
		}

		fileOut << setw(15) << s.getExamScore();

		fileOut << "\n";
	}

	fileOut.close();
	std::chrono::duration<double> duration = high_resolution_clock::now() - start;

	cout << "Writing n number of students from a vector to a file takes " << duration.count() << " seconds\n";
}

void outputSplitGrade_Vect(vector<Person>& students)
{
    vector<Person> passed;
    vector<Person> failed;

    gradeSplitter_Vect(students, passed, failed); // gradeSorter takes the loaded persons in a vector and two empty vector for to fill with pass and fail students

	auto start = high_resolution_clock::now();

    ofstream fileOut1("Passed_Students_Vector.txt");
    ofstream fileOut2("Failed_Students_Vector.txt");

    if (!fileOut1 || !fileOut2)
    {
        cerr << "Error while opening or creating passed or failed file";
        return;
    }

    fileOut1 << setw(15) << left << "Name"
             << setw(15) << "Surname"
             << setw(15) << right << "Final_Grade(Aver. )"
             << "\n";

    for (auto& s : passed)
    {
        fileOut1 << left << setw(15) << s.getfirstName()
                 << setw(15) << s.getSurname()
                 << setw(15) << s.getGrade()
                 << "\n";
    }

    fileOut2 << setw(15) << left << "Name"
             << setw(15) << "Surname"
             << setw(15) << right << "Final_Grade(Aver. )"
             << "\n";

    for (auto& s : failed)
    {
        fileOut2 << left << setw(15) << s.getfirstName()
                 << setw(15) << s.getSurname()
                 << setw(15) << s.getGrade()
                 << "\n";
    }

    fileOut1.close();
    fileOut2.close();

    std::chrono::duration<double> duration = high_resolution_clock::now() - start;
    cout << "Time taken to output sorted student in vector into two new file: " << duration.count() << " seconds\n\n";
}

void outputVectorToFile_Grade(const string& fileName, vector<Person> students)
{
	ofstream fileOut(fileName);

	if (!fileOut)
	{
		cerr << "File cannot be opened or created!";
		return;
	}

	fileOut << left
		<< setw(15) << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << "Grade"
		<< "\n";

	for (auto& s : students)
	{
		fileOut << left << setw(15) << s.getfirstName()
			<< setw(15) << s.getSurname();

		fileOut << setw(15) << fixed << setprecision(2) << s.getGrade();

		fileOut << "\n";
	} 

	fileOut.close();

}

void outputSplitGrade_list(list <Person>& students) 
{
	list<Person> passed;
	list<Person> failed;

	gradeSplitter_List(students, passed, failed); // gradeSorter takes the loaded persons in a list and two empty list for to fill with pass and fail students

	auto start = high_resolution_clock::now();

	ofstream fileOut1("Passed_Students_list.txt");
	ofstream fileOut2("Failed_Students_list.txt");

	if (!fileOut1 || !fileOut2)
	{
		cerr << "Error while opening or creating passed or failed file";
		return;
	}

	fileOut1 << setw(15) << left << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << right << "Final_Grade(Aver. )"
		<< "\n";

	for (auto& s : passed)
	{
		fileOut1 << left << setw(15) << s.getfirstName()
			<< setw(15) << s.getSurname()
			<< setw(15) << fixed << setprecision(2) <<  s.getGrade()
			<< "\n";
	}

	fileOut2 << setw(15) << left << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << right << "Final_Grade(Aver. )"
		<< "\n";

	for (auto& s : failed)
	{
		fileOut2 << left << setw(15) << s.getfirstName()
			<< setw(15) << s.getSurname()
			<< setw(15) << fixed << setprecision(2) << s.getGrade()
			<< "\n";
	}

	fileOut1.close();
	fileOut2.close();

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to output sorted student in list into two new file: " << duration.count() << " seconds\n\n";
}

void outputSplitGrade_deque(deque <Person>& students)
{
	deque<Person> passed;
	deque<Person> failed;

	gradeSplitter_Deque(students, passed, failed); // gradeSorter takes the loaded persons in a deque and two empty deque for to fill with pass and fail students

	auto start = high_resolution_clock::now();

	ofstream fileOut1("Passed_Students_deque.txt");
	ofstream fileOut2("Failed_Students_deque.txt");

	if (!fileOut1 || !fileOut2)
	{
		cerr << "Error while opening or creating passed or failed file";
		return;
	}

	fileOut1 << setw(15) << left << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << right << "Final_Grade(Aver. )"
		<< "\n";

	for (auto& s : passed)
	{
		fileOut1 << left << setw(15) << s.getfirstName()
			<< setw(15) << s.getSurname()
			<< setw(15) << fixed << setprecision(2) << s.getGrade()
			<< "\n";
	}

	fileOut2 << setw(15) << left << "Name"
		<< setw(15) << "Surname"
		<< setw(15) << right << "Final_Grade(Aver. )"
		<< "\n";

	for (auto& s : failed)
	{
		fileOut2 << left << setw(15) << s.getfirstName()
			<< setw(15) << s.getSurname()
			<< setw(15) << fixed << setprecision(2) << s.getGrade()
			<< "\n";
	}

	fileOut1.close();
	fileOut2.close();

	std::chrono::duration<double> duration = high_resolution_clock::now() - start;
	cout << "Time taken to output sorted student in deque into two new file: " << duration.count() << " seconds\n\n";

}