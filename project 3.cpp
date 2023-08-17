#include <iostream>
#include <fstream>
#include <map>
#include <string>
/*
Austin Niwa
8/13/23/
this file is meant to take a list of groceries out of a text file and count them then output the count beside each item type when prompted it also writes to a file
I didnt end up using a class as i remembered you saying in a video we did not have to
*/

using namespace std;
void displayMenu();
int getSelection(string);
void processSelection(int);
void optionOne();
void optionTwo();
void optionThree();
void printFile();
const int SENTINEL = 4;
int selection = 0;
ofstream outputFile("frequency.dat");//makes a file at the start of the program as specified
int main() {
	
	do {
		displayMenu();//do while loop that keeps goind until the user selects the SENTINEL number (4)
		selection = getSelection("Enter your menu selection from 1 " + to_string(SENTINEL) + " ");
		cout << "\n You picked " << selection << endl;
		processSelection(selection);
		printFile();
	} while (selection != SENTINEL);
}//main 

void displayMenu()
{//this function is to print the menu
	cout << "Press 1 to select 1 item from the list to see how many times it shows up on the list. " << endl;
	cout << "Press 2 for a list with numbers that represent the frequency of all items purchased. " << endl;
	cout << "Press 3 for a histogram of the items on the list using * instead of numbers. " << endl;
	cout << "Press " << SENTINEL << " to exit " << endl;


}//displaymenu
   
int getSelection(string prompt)//this function checks the input selection to make sure it is from -1-4 otherwise it prompts the user again
{
	
	bool needSelection = true;
	do {
		cout << prompt;
		cin >> selection;
		needSelection = ((selection < 1) || (selection > SENTINEL));
		if (needSelection) {
			cout << "Invalid choice - valid are 1 to " << SENTINEL << endl;
		}//if
	} while (needSelection);
	return selection;
}//getSelection
void processSelection(int selection)//switch for user selection. 1 lets the user select one item to check, 2 prints all of them, 3 replaces the numbers with asterisks, and ofcourse 4 exits the program
{
	switch (selection) {
	case 1:
		optionOne();
		break;
	case 2:
		optionTwo();
		break;
	case 3:
		optionThree();
		break;
	case 4:
		break;
	default:
		cout << "Please input a number from 1 to 4. " << endl;
		break;
	}//switch
}

void optionOne()
{
	string itemInput = "NULL";//input set to null
	fstream inputFile;


	map<string, int> stuff;//maps the file so the loop can get a string then an int out of each line

	inputFile.open("CS210_Project_Three_Input_File.txt");// opens file (i think this was the file name outlined in the rubric

	if (inputFile.fail()) {//failsafe
		cout << "Error in file " << endl;
	}//if
	while (inputFile >> itemInput) {//while loop to find the string for the user input

		if (stuff.count(itemInput)) {
			stuff[itemInput]++;//adds to item input when it counts the same string

		}//if
		else {
			stuff.emplace(itemInput, 1);
			
			
		}//else
	}//while

	cout << "Which item would you like to check on the list? " << endl;//have to get input after opening of the file or it will print the last thing registered on the list
	cin >> itemInput;//gets user input for the 
	if (stuff.count(itemInput)) {
		cout << "  " << itemInput << "  " << stuff[itemInput] << endl;
		
	}
	else {
		cout << "You did not pick an item on the list, try another."<< endl;
	}
}

void optionTwo()// i thought one of the videos lined up with what was expected for option two so hopefullyh i was correct
{
	fstream inputFile;
	
	string item;

	map<string, int> stuff;
	inputFile.open("CS210_Project_Three_Input_File.txt");

	if (inputFile.fail()) {//checks for the text file to begin
		cout << "Error in file " << endl;
	}//if
	while (inputFile >> item) {

		if (stuff.count(item)) {
			stuff[item]++;
			
		}//if
		else {
			stuff.emplace(item, 1);
			
		
		}//else
	}//while
	
	
	inputFile.close();
	for (auto groceries : stuff) {//prints the name of the groceries from the text file and the amount of times they come up
		cout << "  " << groceries.first << "  " << groceries.second << endl;
   	}//for
	
	
}//option2

void optionThree()//mostly the same as part 2 with an added loop!
{
	ifstream inputFile;
	
	string item;
	map<string, int> stuff;
	inputFile.open("CS210_Project_Three_Input_File.txt");
	int i = 0;
	if (inputFile.fail()) {
		cout << "Error in file " << endl;
	}//if
	while (inputFile >> item) {

		if (stuff.count(item)) {
			stuff[item]++;

		}//if
		else {
			stuff.emplace(item, 1);


		}//else
	}//while

	for (auto groceries : stuff) {//loop to go through the groceries in the text file
		cout << "  " << groceries.first << "    ";//prints the name of the groceries from the text file
		for (int i = 0;i < groceries.second; i++) {//loop to go until i is greater than the number of times an item comes up. Replaces number with asterisks.
			cout << "*";
			}//for groceries second
		cout << endl;//endl is after the loop for the number or it would endl after each asterisk
		}//for stuff
	}
void printFile()//this function prints the list with the numbers to a document i tested it as a txt file first to see if it worked and it seemed to
//i pretty much just copied the code for option 2 and changed the output location. I thought to put it in option 2 but then that would make outputting the list inconsistant as it would require the user to use option 2 and we want it to do it every time
{
	fstream inputFile;
	fstream outputFile;
	string item;
	map<string, int> stuff;
	
	inputFile.open("CS210_Project_Three_Input_File.txt");//open both files
	outputFile.open("frequency.dat");
	if (inputFile.fail()) {//checks for the input text file to begin
		cout << "Error in input file " << endl;
	}//if
	if (outputFile.fail()) {//checks for the output text file to begin
		cout << "Error in output file " << endl;
	}//if
	while (inputFile >> item) {

		if (stuff.count(item)) {
			stuff[item]++;

		}//if
		else {
			stuff.emplace(item, 1);


		}//else
	}//while


	inputFile.close();//closes both files
	outputFile.close();
	for (auto groceries : stuff) {//prints the name of the groceries from the text file and the amount of times they come up
		outputFile << "  " << groceries.first << "  " << groceries.second << endl;
	}//for

}
//for



