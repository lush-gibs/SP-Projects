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
        cout << "Input name of the file to read\nExample(filename.txt) : ";
        string fileName;
        cin >> fileName;

        cout << "\nChoose one container to use: \n1. Vector\n2. List\n3. Deque\n\n";
        int containerChoice;
        while (true)
        {
            cout << "Please choose option 1 , 2 or 3: ";

            cin >> containerChoice;

            if (cin.fail())
                clearWrongInputs();

            else if (containerChoice == 1 || containerChoice == 2 || containerChoice == 3)
                break;

            else
                cout << "invalid Selection! ";
        }
       
        switch (containerChoice)
        {
            case 1:
            {
                auto filePersonsVector = inputFile_Vector(fileName);
				gradeSorter_Vect(filePersonsVector);

				cout << "\n";
			    strategyChooserVector(filePersonsVector);

                break;
            }
            case 2:
            {
                auto filePersonsList = inputFile_List(fileName);
                gradeSorter_List(filePersonsList);

                cout << "\n";
                strategyChooserList(filePersonsList);

                break;
            }
            case 3:
            {
                auto filePersonsDeque = inputFile_Deque(fileName);
                gradeSorter_Deque(filePersonsDeque);

                cout << "\n";
			    strategyChooserDeque(filePersonsDeque);

                break;
            }
            default:
            {
                cout << "Unexpected error: invalid container choice!" << endl;
                break;
            }
        }
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

    system("pause");
    return 0;
}
