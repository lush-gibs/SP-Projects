 SP-Projects
Systemic Programmic task in VVK 2024/2025

-- intro about futured application----

Basic student points calculation formula:

Final	points = 0.4 * (Average of HW|Median of HW) + 0.6 * Exam 

  **Releases**
**Release v0.1**

This is the basic structure for the grade calculator. In this release, a Person class is implemented, containing various methods and attributes, including the Rule of Three.

Features:
o	The Person class can hold information for a single student, including:
	Name and surname
	Homework and exam results
	Final grade
o	The class can be populated via user input.
o	Users can calculate the final grade based on the average or median of homework scores, with output displayed on the console.

Homework Input:
o	Users can input homework scores without knowing the exact number of assignments. They can stop input at any time.
o	Random homework and exam scores can also be generated.

File Input:
o	The program can read student data from a file formatted as follows:

Name        Surname    HW1   HW2   HW3   HW4   HW5   Exam
Name1       Surname1     8     9    10     6    10      9      
Name2       Surname2     7    10     8     5     4      6        

o	The program calculates and displays the final grades (both average and median) for all students in the file.

Performance Note: This release uses a vector container, which is ideal for this task. However, frequent pushbacks can be costly if reallocation occurs.
 
**Release v0.2**

Refactoring: The code is split into .cpp and .h files, making it easier to read and maintain.

Error Handling: Exception handlers are introduced to catch errors and ensure a smooth user experience.

New Features:
o	Random student data generation:
	Users can specify the number of students to generate.
	Output is written to a file.
o	File operations include:
	Reading student data into a vector.
	Sorting data in descending order (using the std::sort function).
	Splitting data into two containers: one for passed grades and one for failed grades.
	Outputting the results to two new files.

Performance Tracking: Speed for file reading, sorting, splitting, and file output is measured and displayed on the console. Handling large datasets (e.g., 10,000,000 students) is noted to be time-intensive.
 
**Release v0.25**

Container Comparison:
o	Introduced list and deque containers alongside vectors.
o	Performance Observations:
	Sorting: Lists are faster due to their doubly-linked structure, which enables pointer-based sorting without copying elements.
	Splitting: Deques excel in splitting due to efficient insertion and deletion operations.

Refinement: Functions like reading, sorting, splitting, and outputting to files are tested with all three containers and speed rate is analysed and displayed on console.
 
**Final Release 1.0**

Splitting Strategies:
1.	Two-container strategy: Creates separate containers for passed and failed students.
2.	One-container strategy: Moves failed students to a new container, leaving passed students in the original.

The one-container strategy proves more efficient in terms of speed and memory, requiring fewer operations.

Vector Optimization:
o	Splitting students with vectors is faster due to algorithms like std::find_if and range-based construction of containers.

Repo Cleanup:
o	Unnecessary files are removed, leaving only source and include files.
o	Added CMakeLists.txt and runMe.bat to streamline building and running the program.

Overall the vector container with the new implemented algorithms was the preferred container to perform the task required.
 

**Application User Guide
**
Setup and Installation

Requirements:
o	The program requires a CMake compiler with a minimum version of 3.25.
o	The CMakeLists.txt file describes all the requirements and processes needed to compile the program.

Running the Application:
o	Use the provided runMe.bat file for automatic compilation, installation, and running of the application. This file executes all necessary commands step by step in the terminal.
o	You can also manually input the commands if preferred.

Test Files:
o	A sample file containing student data is copied automatically to both the Debug folder and the main project folder. This ensures users have a test file ready to work with.



Options at Runtime:

1.	Read students’ data from a file:
	Input the file name (e.g., FileName.txt), ensuring it exists in the working directory.
	Select a container type (vector, list, or deque) and splitting strategy (one-container or two-container).

2.   Generate random student data:
	Users are asked to input the desired file name (e.g., FileName.txt). The program creates this file in the working directory.
	 Input the number of students to generate randomly.
	A new file containing the data will be created.

3.    Manually Input Student Data

1.	Specify Number of Students:
Input the total number of students you want to manually enter.

2.	Input Student Details:
For each student:
	Input their full name in the format: “FirstName Surname”.

3.	Choose to manually input or randomly generate the exam score:
	If manually inputting, enter a score between 0 and 100.


4.	Homework Scores:
Select how to handle homework scores:                                                                                                                            
1.	Add Homework:
	Enter each homework score one at a time, pressing Enter after each.
	To stop adding homework, type "X" and press Enter.
2.	Do Not Add Homework:
	Skip entering homework scores.
3.	Randomize Homework Scores:
	Enter the number of homework scores to randomize, and the program will generate them automatically.

5.	Calculate Final Grades:
Choose how to calculate the grades:
1.	Average: Calculates the final grade using the average of the homework scores.
2.	Median: Calculates the final grade using the median of the homework scores.

Output: The program displays the results on the console.
 













******************************************************OBSERVATION**************************************





Comparison of Containers for Tasks

1. Reading Data

•	Vector:
- Reading and inserting data into a vector can be slower for large files due to frequent reallocation when capacity is exceeded.
-	However, vector performs well when the data size is predictable and memory is contiguous.
•	List:
-	Reading into a list is efficient for large files because it does not require contiguous memory.
-	Insertions are fast due to the doubly linked structure, but memory usage is higher.
•	Deque:
-	Similar to a vector, but deque handles reallocation more efficiently because it allocates in smaller, non-contiguous chunks.


2. Sorting Data

•	Vector:
-	Sorting is faster in vector because it uses contiguous memory and allows random access, making the std::sort algorithm highly efficient.
•	List:
-	The list container uses std::list::sort, which is optimized for linked structures. This is faster for a list compared to converting it into random access like std::sort.
-	However, overall sorting in list is slower than vector for large datasets due to less cache locality.
•	Deque:
-	Deque has performance similar to vector in sorting but slightly slower because its memory layout is not entirely contiguous.


3. Splitting Data

•	Vector:
-Splitting using a vector can be memory-intensive as it requires copying data into new containers. However, it benefits from fast iteration and range-based construction.
•	List:
-	A list excels at splitting tasks due to its linked structure, which allows elements to be moved between containers by updating pointers rather than copying data.
•	Deque:
-	Deque performs better than vector for splitting because of its efficient insertions and deletions at both ends. However, it's not as fast as list for middle insertions or deletions.

4. Writing Data to Files

•	Vector:
- Writing data from a vector is slightly faster because of its contiguous memory layout and sequential access pattern.
•	List:
-	Writing from a list is slower due to its non-contiguous memory and the need to traverse each node.
•	Deque:
-	Writing performance is close to vector but can be slower if data spans multiple memory blocks.
 
General Observations

•	Efficiency:
-	Vector is generally the fastest for tasks requiring frequent random access (e.g., sorting and file output).
-	List is the most efficient for tasks involving frequent insertions, deletions, or reordering of elements (e.g., splitting data).
-	Deque balances between vector and list, performing well in tasks with a mix of random access and frequent insertions or deletions at the ends.

•	Memory Usage:
- Vector uses the least memory due to its contiguous allocation.
-	List uses the most memory because each node stores additional pointers for the doubly linked structure.
-	Deque has moderate memory usage because of its segmented blocks.
 

