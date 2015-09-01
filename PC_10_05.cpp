//**********************************************************
// Author: Amy Weller
// Date : 09 / 01 / 15
// Description : Gaddis - Starting Out With C++ : Early
//                       Objects(8e)
//
//                Programming Challenge 10 - 05
//  		== == == == == == == == == == == == == =
//
//			In statistics the mode of a set of values
//			is the value that occurs most often.  Write
//			a program that determines how many pieces of
//			pie most people eat in a year.  Set up an integer
//			array that can hold responses from 30 people.
//			For each person, enter the number of pieces
//			they say they eat in a year.  Then write a 
//			function that finds the mode of these 30
//			vales.  This will be the number of pie slices 
//			eaten by the most people.  The function that returns
//			and finds the mode should accept two arguements, 
//			an array of integers, and a value indicating how
//			many elements are in the array.
/*************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



vector <int> findMode(int[], int);					//function prototype w/ return type vector


int main()
{
	
	//array to store the slices of 30 people
	int pieSlices[4];
	
	for (int i = 0; i < 4; i++)
	{
		//individual's input of pie slices eaten
		int userInput;
		std::cout << "User " << i + 1 << " please enter the number of pie slices eaten in one year" << endl;
		cin >> userInput;
		pieSlices [i] = userInput;
		
	}
	
	vector <int> returnModes = findMode(pieSlices, 4);
	for (int i = 0; i < returnModes.size(); i++)			//here I'm printing what came out of modes vector
	{
		cout << returnModes[i] << endl;
	}

	cin.get();
	cin.ignore();

	return 0;
}

vector <int> findMode(int nums[], int size)

{
	std::sort(nums, nums + size);			//sort the array received

	vector<int> modes;						//declare new vector
	int sameCount = 1;						//this will count how many times a number appears
	int modeCount = 1;						//how many modes are in the array
	int currHighest = 0;					//tracks which number is the mode in current loop
	int highest = 0;						//counter for number of numbers appearing the most
	for (int count = 0; count < size; count++)

	{

		if (nums[count] == nums[count + 1])
		{
			sameCount++;						//compare current number to the next one if match same count increment

		}


		else if (nums[count] != nums[count + 1])  //if curent doesn't match next num

		{
			if (sameCount > highest)			//how many were there?  If it is bigger than the last series, 
			{
				highest = sameCount;			//then it has highest count in the series and is the mode.
				modes.push_back(nums[count]);	//put mode in the vector
			}
			else if (sameCount == highest)		//if the count of this series = the highest of the last series
			{
				modeCount++;					//we have another mode
				modes.push_back(nums[count]);	//add the second mode

			}
			sameCount = 1;					//reset the counter and continue through the array
		}


	}

	return modes;								//returns modes vector to the caller w/ mode value(s)

}
