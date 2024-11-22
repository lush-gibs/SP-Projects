#include "OutputPerson.h"
#include "InputPerson.h"


int main()
{
    srand(time(0));     //seed for rand function to generate from time

    cout << "1.Input students from file\t2.Output Random Students to file\t3.Input students manually\n" << endl;
    int studentInputChoice;

    while (true)
    {
        cout << "Please choose option 1 , 2 or 3: ";
        cin >> studentInputChoice;
        if (cin.fail())
            clearWrongInputs();

        else if (studentInputChoice == 1 || studentInputChoice == 2 || studentInputChoice == 3)
            break;

        else
            cout << "invalid Selection! ";
    }

    if (studentInputChoice == 1)       // Read INPUT from file 
    {
		string fileName = "students100000.txt";

        vector <Person> filePersonsVector;
		list<Person> filePersonsList;
		deque<Person> filePersonsDeque;
        
        cout << "\n";

        filePersonsVector = inputFile_Vector(fileName);
		filePersonsList = inputFile_list(fileName);
		filePersonsDeque = inputFile_Deque(fileName);

        cout << "\n";

        gradeSorter_Vect(filePersonsVector);                  //sorts students by descending order of final grade (average)
		gradeSorter_List(filePersonsList);                 
        gradeSorter_Deque(filePersonsDeque);

        cout << "\n";

		outputSplitGrade_Vect(filePersonsVector);       //splits students into passed and failed containers and outputs to file
        outputSplitGrade_list(filePersonsList);
		outputSplitGrade_deque(filePersonsDeque);

        cout << "\n";
    }

    if (studentInputChoice == 2)            //Output random students to file
    {
       cout << "\nPlease type in Name of file you want to create or replace... \nexample, 'Filename.txt': ";
       string fileName;
       cin >> fileName;

        vector<Person> randomStudents = randomizePersons();

        outputVectorToFile_HW_EX(fileName, randomStudents);
    }

    if (studentInputChoice == 3)    // to input information manually into person class and print final grade by average or median by users choice
    {
        vector <Person> students = manualInputPerson();

        printGrades_AverOrMed(students);
    }
    return 0;
}
