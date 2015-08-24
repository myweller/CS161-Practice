/**********************************************************
** Author: Amy Weller
** Date: 08/23/15
** Description: Gaddis - Starting Out With C++: Early
**                       Objects (8e)
**
**              Programming Challenge 10-01
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
**                                numbers for test scores.
**********************************************************/


#include <iostream>						//for cin/cout
#include <algorithm>					//for sort algorithm
#include <iomanip>						//for formatting user output
using namespace std;

//Function Prototypes
void getValidScore(double );			
void sortArray(double [], int);			
double avgArray(double[], int);			
void userOutput(double[], int, double);	

int main()
{	
	//User input:  Define how many scores will be stored

	int size;
	cout << "How many scores do you wish to store?"<< " there must be one score." << endl;
	cin >> size;

	//initizlie an array of doubles size == defined by size from user
	double *myArray = new double[size];
	
	//Loop User input:  call getValidScore to insure positive value
	for (int count = 0; count < size; count++)
	{
		double score;
		cout << "Please enter score number " << count+1 << endl;
		cin >> score;
		getValidScore(score);
		myArray[count] = score;
		
	}

	sortArray(myArray, size);
	double scoreAvg = avgArray(myArray, size);
	userOutput(myArray, size, scoreAvg);

	// free allocated heap memory from array to avoid memory leaks
	delete[] myArray;
	
	//keeps window open in Visual Studio
	cin.get();						
	cin.ignore();
	
	return 0;
}

/*Description:  Validates user input is not a negative value */
void getValidScore(double x)
{
	while (x < 0)
	{
		cout << "Score cannot be negative.  Please enter a valid score" << endl;
		cin >> x;
	}
}

/*Description:  Sorts the scores in the array in ascending order */
void sortArray(double sortedArray[], int s)
{
	std::sort(sortedArray, sortedArray + s);
	
}

/*Description:  Returns the average scores in the array */
double avgArray(double avgedArray[], int s)
{
	//capture total by looping through the array and keep running total	
	double total = 0;
	for (int count = 0; count < s; count++)
	{
		total += avgedArray[count];
	}
	//calculate average by dividing total by array size
	double avg = total / s;
	return avg;
}


/*Description:  Outputs the values in the array and the avearge scores */
void userOutput(double finalArray[], int s, double avg)
{	//loop through the list of scores
	
	cout << fixed << showpoint << setprecision(2);
	int position = 1;
	for (int count = 0; count < s; count++)
	{
		cout << "Score " <<position<<" "<<finalArray[count] << endl;
		position++;
	}

	cout << "Average Score " << avg << endl;
}
