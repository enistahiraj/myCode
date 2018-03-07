/***************************************************************************************
 Name:Enis Tahiraj
 Date:02/28/2018
 Title:Find all subsets of a set
 Description:The program gets user's input (int) for the size of the set (n),
 then it stores it in a vector. The input doesnt accept anything but (int)'s
 and it doesnt accept repeated numbers. After the set is given the program
 will print (recursively) all possible subsets of the given set.
 ***************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//function prototype
void powerSet(int index, vector <int> storeUserInput, bool used[]);

int main()
{
	//declaring variables
	int userSetInput, size=0;
	vector <int> storeUserInput(size);
	bool used[storeUserInput.size()];

	//explaining to the user what the program does
	cout <<"\nEnter as many numbers as you want to make a set.\n"<<endl;
	cout <<"Displayed you will see all the subsetes of the set you made\n"<<endl;

	//get the size of the set
	cout<<"\nHow many numbers would you like to put in the set?\n";
	cin >> size;

	for (int i=0; i<size; i++)
	{
		
		cout <<"Enter number: ";
		cin >> userSetInput;
		//check for invalid input
		if (!(cin))
		{
			cout <<"Invalid input, please enter numbers only!"<<endl;
			cin.clear();
			cin.ignore();
			i--;
		}
		//if the input is valid, store it in the vector
		else 
		{
			//check if the input already exists in the vector
			if (find(storeUserInput.begin(), storeUserInput.end(), userSetInput) != storeUserInput.end())
			{
				cout <<"This number is already in the set. Try again!"<<endl;
				i--;
				continue;
			}
			else
				storeUserInput.push_back(userSetInput);
				
		}
	} 

	powerSet(0, storeUserInput, used);
	
	return 0;
}

//function to get the subsets
void powerSet(int index, vector <int> storeUserInput, bool used[])
{
	if (index == storeUserInput.size())
	{
		// last index at which used[i] == true
		int lastUsed = 0;
		for (int booli = 0; booli < storeUserInput.size(); booli++)
		{
			if (used [booli])
			{
				lastUsed = booli;
			}
		}
		cout <<"{";
		//
		for (int i=0; i<storeUserInput.size(); i++)
		{
			if (used[i])
			{
				if (i == lastUsed)
				{
					cout << storeUserInput[i];
				}
				else
				{
					cout << storeUserInput[i] <<",";
				}
			}
		}
		cout <<"}\n";
	}
	else
	{
		used[index] = true;
		powerSet(index + 1, storeUserInput, used);

		used[index] = false;
		powerSet(index + 1, storeUserInput, used);
	}

}

