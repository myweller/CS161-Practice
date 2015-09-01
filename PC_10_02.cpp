/**********************************************************
** Author: Amy Weller
** Date: 08/23/15
** Description: Gaddis - Starting Out With C++: Early
**                       Objects (8e)
**
**              Programming Challenge 10-02
**              ===========================
**
**              Write a program that dynamically allocates
**              an array large enough to hold a user-
**              defined number of test scores. Once all the
**              scores are entered, the array should be
**              passed to a function that sorts them in
**              ascending order. Another function should be
**              called that calculates the average score.
**              The program should display the sorted list
**              of scores and average with appropriate
**              headings. Use pointer notation rather than
**              array notation whenever possible.
**
**              Input Validation: Do not accept negative
**               numbers for test scores.
**				
**				Revise the above to allow the user to enter
**				Name-Score pairs.  For each student taking
**				a test, the user types a string representing
**				the name of the student followed by an integer
**				representing the student's score.  Modify both 
**				sorting and average-calculting functions so they
**				take arrays of structures, with each structure
**				containing the name and score of a single student.
**				In traversing the arrays, use pointers rather 
**				than array indices.
**				
**********************************************************/


#include <iostream>						//for cin/cout
#include <algorithm>					//for sort algorithm
#include <iomanip>						//for formatting user output
#include <string>						//for string
using namespace std;

//initialize a structure of student scores taking string for the name and double for score
struct StudentScores
{
	string name;
	double score;

};


//Function Prototypes
int getValidScore(int, string, string );			
void bubbleSort(StudentScores [], int);			
double avgArray(StudentScores[], int);			
void userOutput(StudentScores[], int, double);	

int main()
{	
	//User input:  Define how many scores will be stored
	cout << "How many scores do you wish to store?"<< " there must be one score." << endl;
	int numScores = getValidScore(1, "Enter the number of test scores: ",
		"There must be at least 1 test.  Please "
		"enter a valid number of test scores: ");

	//dynamically allocate heap memory for an array of StudentScores
	StudentScores *nameAndScore = new struct StudentScores[numScores];
	
	//Loop User input:  call getValidScore to insure positive value
	for (int count = 0; count < numScores; count++)
	{
		
		cout << "Please enter student #"<<count+1<< " frist name,then press enter." << endl;
		cin >> (nameAndScore+count)->name;
				
		(nameAndScore+count)->score = getValidScore(1, "Enter the score then press enter", 
										"The score must be a positive number.  Please enter a valid score");
		
	}
	//sort array of StudentScores by score member value
	bubbleSort(nameAndScore, numScores);
	
	//calculate the average score in the array
	double scoreAvg = avgArray(nameAndScore, numScores);
	
	//display output of each students name and score, plus the average score
	userOutput(nameAndScore, numScores, scoreAvg);
	
		
	//keeps window open in Visual Studio
	cin.get();						
	cin.ignore();
	cout << "Press any key to end the program" << endl;


	// free allocated heap memory from array to avoid memory leaks
	delete[] nameAndScore;	
	nameAndScore = 0;

	return 0;
}



/*********************************************************************
** Description: Prompts the user for an int value greater than or
**              equal to minValue.  Until the user inputs a valid int,
**              it displays a custom error message.
*********************************************************************/
int getValidScore(int minValue, string prompt, string errMsg) 
{
	int input;

	cout << prompt << endl;

	// prompt user for input at least as big as minValue
	while (true) 
	{
		cin >> input;

		if (input < minValue) 
		{
			// user gave invalid input
			cout << errMsg << endl;
			
		}
		else {
			// user gave valid input
			return input;
		}
	}
}


///*Description:  Sorts the Student Scores based on score elements in ascending order */
void bubbleSort(StudentScores sortedArray[], int s)
{
	//holds temp value of StudentScores type
	StudentScores temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < s-1; count++)
		{
			if ((sortedArray+count)->score > (sortedArray+count + 1)->score)
			{
				temp = *(sortedArray + count);
				//temp = sortedArray[count]; this uses the array subscript
				//this uses the pointer arithmetic instead, the two are equivalent
				*(sortedArray+count) = *(sortedArray+count + 1);
				//sortedArray[count] = sortedArray[count + 1];
				
				//sortedArray[count + 1] = temp;
				*(sortedArray + count + 1) = temp;
				swap = true;

			}

		}

	} while (swap);
	
}//end bubbleSort

///*Description:  Returns the average scores in the array */
double avgArray(StudentScores avgedArray[], int s)
{
	//capture total by looping through the array and keep running total	
	double total = 0;
	for (int count = 0; count < s; count++)
	{
		total += (avgedArray+count)->score;
	}
	//calculate average by dividing total by array numScores
	double avg = total / s;
	return avg;
}


///*Description:  Outputs the values in the array and the avearge scores */
void userOutput(StudentScores finalArray[], int s, double avg)
{	//loop through the list of scores
	
	cout << fixed << showpoint << setprecision(2);
	
	for (int count = 0; count < s; count++)
	{
		cout << "Name: " <<count+1<<", "<<(finalArray+count)->name << "		Score: "<<(finalArray+count)->score<< endl;
		
	}

	cout << "Average Score " << avg << endl;
}
