#include "Person.h"

int main() 
{
    srand(time(0));     //seed for rand fucntion to generate from time

    cout << "Press '1' to input student details from file or '2' to input student details manually: ";
    int studentInputChoice;
    cin >> studentInputChoice;

    // section to input information from file , change file name to check you file

        if (studentInputChoice == 1)
        {
            vector <vector <string>> fileInfo;
            stringstream myBuffer;
            vector<Person> personInFile;

            std::ifstream file("students20.txt");        //type in file to input from

            if (file.is_open())
            {
                myBuffer << file.rdbuf();
                file.close();
            }
            else
            {
                std::cerr << "File not found\n";
            }

            vector <string> wordsInLine;           
            string lineOfFile;
            
            while(std::getline(myBuffer, lineOfFile))
            {
                wordsInLine.clear();
                std::istringstream is(lineOfFile);                  // prepares each line in file to be read
                string word;

                while(is >> word)                                     // words in line are read separately using the word variable
                {
                    wordsInLine.push_back(word);                             // fill the vector of string with each word from line
                }
                fileInfo.push_back(wordsInLine);                    //fill the vector with vector of string
            }

            bool firstLine = true;

            for (auto& lines : fileInfo)            // loops through entire vector which contains the file information, 1 index in vector is for each line in file
            {
                if (firstLine)
                {
                  
                    firstLine = false;
                    continue;                       //skips first line in the file 
                }

                Person p;
                vector<double> hw;

                p.setFirstName(lines[0]);                           //sets object firstname with first word in the vector of string

                if (lines.size() > 1)
                    p.setSurname(lines[1]);

                    for (int i = 2; i < lines.size(); i++)
                    {
                        double value = std::stod(lines[i]);      //converts string to double

                        if (i < lines.size() - 1)                      //checks if index is not on the last column which is reserved for exam scores
                            hw.push_back(value);
                        else
                            p.setExamScore(value);
                    }

                    p.setHomework(hw);
                    personInFile.push_back(p);
                }
            
            cout<< left << setw(20) << "Name"                   //format for header of file
                << setw(20) << "Surname"
                << right << setw(20) << "Final (Avg. )" << " | "
                << left << setw(20) << "Final (Med. )" << endl;

            string line(79, '-');           //to get accurate width of line but it's not accurate for some reason, even though 83 is the width of previous line
            cout << line << endl;

                for (auto student : personInFile)             //loops through persons and  calculates Average and median and then prints each line in the file with results in console.
                {
                    cout << left << student;

                    student.calcAverage();
                    cout << fixed << setprecision(2) <<  right << setw(20) << student.getGrade() << " | ";

                    student.calcMedian();
                    cout << fixed << setprecision(2) << setw(15) << student.getGrade() << endl;
                }
        }
    
      // section to input information manually into person class

        else if (studentInputChoice == 2)
        {
            cout << "Please input number of students: ";
            int n;
            cin >> n;

            cout << "\nCalculate Grade with:\n1. Average\n2. Median\ninput 1 for average and 2 for median: ";
            int m;
            cin >> m;

            vector<Person> arr(n);

            for (Person& student : arr)
            {
                cin >> student;                 // calls overloaded cin to input data into Persons class member variables until number of students required has reached
            }

            cout.setf(ios::left);           //formats header for manual input of students
            cout.width(20);
            cout << "Name";
            cout.width(20);
            cout << "Surname";
            cout.width(20);
            cout << ((m == 1) ? "Final_point(Aver.)" : "Final_point(Median)") << endl;
            cout << "------------------------------------------------------------" << endl;

            for (Person& student : arr) {
                cout << student;        //calls overloaded cout to print first and last name of student
                
                student.calcFinalGrade(m);                  //calculates and updates the grade member of persons class based on user's choice

                cout << fixed << setw(20) <<  setprecision(2) << student.getGrade() << endl;
            }
        }
        else
        {
            cout << "Invalid Selection! Select option 1 or 2." << endl;
            cout << "Restart program." << endl;
        }

        return 0;
}
