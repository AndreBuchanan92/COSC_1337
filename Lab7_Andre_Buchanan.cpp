/*********************************************************************/
/* This program diplays a main menu of options to manage a small CD  */
/* collection with the following options:                            */
/*       1. Read Collection                                          */
/*       2. Display Collection                                       */
/*       3. Sort Collection                                          */
/*       4. Find a CD                                                */
/*       5. Edit a CD  
/*		6. Add Tracks for a CD                                              */
/*       7. Delete Tracks for a CD     
//		8. Math Break 		                                          */
/*       9. Quit                                                     */
/*                                                                   */
/* It will be implemented in stages.                                 */
/* This stage has the following optiions implemented:                */
/*       1. Read Collection                                          */
/*       2. Display Collection                                       */
/*       3. Sort Collection                                          */
/*       4. Find a CD                                                */
/*       5. Edit a CD                                                */
/*       6. Math Break                                               */
/*       7. Quit                                                     */
/*                                                                   */
/* Math Break has its own menu:                                      */
/*       1. Even or Odd                                              */
/*       2. Prime Number                                             */
/*       3. Quit                                                     */
/*********************************************************************/

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

//Class Declaration 
class CD
{
	private:
		//member variables 
		string artist;
		string title;
		int year;
		int numOfTracks;  //
		string *tracks;  //
		
	public:
		//These are prototypes for the member functions
		void setArtist(string);
		void setTitle(string);
		void setYear(int);
		void setNumTracks(int);  //
		void setTrackName(int, string); //
		void deleteTracks();  //
		CD();  //
		
		//Accessors
		string getArtist();
		string getTitle();
		int getYear(); 
		int getNumTracks();  //
		string getTrackName(int);  //
		
};

CD::CD()
{
	numOfTracks = 0; //
}
void CD::setArtist(string a)
{
	artist = a;
}

void CD::setTitle(string t)
{
	title = t;
}

void CD::setYear(int y)
{
	year = y;
}

void CD::setNumTracks(int n)
{
	numOfTracks = n; 
	tracks = new string[numOfTracks];
}

void CD::setTrackName(int position, string k)
{
	
	tracks[position] = k;
}

void CD::deleteTracks() 
{
	delete [] tracks;
	tracks = NULL;
	numOfTracks = 0;
}

string CD::getArtist()
{
	return artist;
}

string CD::getTitle()
{
	return title;
}

int CD::getYear()
{
	return year;
}

int CD::getNumTracks()
{
	return numOfTracks; 
}

string CD::getTrackName(int position)
{
	return tracks[position]; 
}

/**********************/
//function prototypes
void evenOdd();
void primeNumber();
void mathBreak();
int isEven(int);
int	isPrime(int);
int mainMenuOption();
int	mathBreakOption();
int	getValidNum();
void testCD();
int readCollection(CD [], int);
void displayCollection(CD [], int);
void sortCollection();
CD * editCD(CD [], int);
void sortCollection(CD [], int);
void findCD(CD [], int);
void addTracks(CD [], int);
void editOneCD(CD *);
void deleteTracks(CD [], int);
void findRecursiveCD(CD [], int);
bool recursionCD(CD [], int, string, string);
void recursionReverse(string, int);
void stringReverse();

int main()
{
	// Variable Declarations
	const int SIZE = 17;
	int option;
	CD fullCD[SIZE];
	int readCD = 0;
	
	option = mainMenuOption();
	
	while(option != 10)
	{
		switch (option)
		{
			case 1:
				readCD = readCollection(fullCD, SIZE);
				break;
			case 2:
				if(readCD)
					displayCollection(fullCD, SIZE);
				else
					cout << "Collection must be read first";
				break;
			case 3:
				if(readCD)
					sortCollection(fullCD, SIZE);
				else
					cout << "Collection must be read first";
				break;
			case 4:
				if(readCD)
					findCD(fullCD, SIZE);
				else
					cout << "Collection must be read first";
				break;
			case 5:
				if(readCD)
					findRecursiveCD(fullCD, SIZE);
				else
					cout << "Collection must be read first";
				break;
			case 6:
				if(readCD)
					editCD(fullCD, SIZE);
				else
					cout << "Collection must be read first";
				break;
			case 7:
				if(readCD)
					addTracks(fullCD, SIZE);
				else
					cout << "Collection must be read first";
				break;
			case 8:
				if (readCD)
					deleteTracks(fullCD, SIZE);
				else 
					cout << "Collection must be read first";
				break;
			case 9:
				mathBreak();
				break;
		}
		
		option = mainMenuOption();
	}
	
	cout << "Ending program";

return 0;
}


/*****************************************************/
/* Function:   mainMenuOption                        */
/* Inputs:     none                                  */
/* Outputs:    a valid user option                   */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option, validates          */
/*             and returns it.                       */
/*****************************************************/
int mainMenuOption()
{
	int option;
	
	do
	{
		cout << endl;
		cout << "\n---Main Menu---\n";
		cout << "1. Read Collection \n";
		cout << "2. Display Collection \n";
		cout << "3. Sort Collection \n";
		cout << "4. Find a CD \n";
		cout << "5. Find a CD (Recursive Version) \n";
		cout << "6. Edit a CD \n";
		cout << "7. Add Tracks for a CD \n";
		cout << "8. Delete All Tracks for a CD \n";
		cout << "9. Math Break \n";
		cout << "10. Quit \n";
		cout << "Pick an option from above: ";
		cin >> option;
		
		if ((option < 1) || (option > 10))
		cout << "Invalid option\n";
		
	}while((option < 1) || (option > 10));
	
	return option;
}

/*****************************************************/
/* Function:   MathBreakOption                       */
/* Inputs:     none                                  */
/* Outputs:    a valid user option                   */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option, validates          */
/*             and returns it.                       */
/*****************************************************/
int mathBreakOption()
{
	int option;
	
	do
	{
		cout << endl;
		cout << "Beginning the Math Break\n";
		cout << "1. Even or Odd\n";
		cout << "2. Prime Number\n";
		cout << "3. String Reverse\n";
		cout << "4. Quit Math Break\n";
		cout << "Please pick an option: ";
		cin >> option;
		cin.ignore(100, '\n');
		
		if ((option < 1) || (option > 4))
			cout << "Invalid option\n\n";
		
	}while((option < 1) || (option > 4));
		
	return option;
}


/*****************************************************/
/* Function:   mathBreak                             */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option and plays the game. */
/*****************************************************/
void mathBreak()
{
	int option;
	
	option = mathBreakOption();
	
	while(option != 4)
	{
		switch(option)
		{
			case 1:
				evenOdd();
			case 2:
				primeNumber();
				break;
			case 3:
				stringReverse();
				break;
		}
		option = mathBreakOption();
			
	}
}


/************************************************************/
/* Function:   evenOdd                                      */
/* Inputs:     integer to test                              */
/* Outputs:    1 if prime, 0 if not prime                   */
/* Purpose:     Promps and validates user inpup             */
/*               And teels weather its even or odd          */
/************************************************************/
void evenOdd()
{
	int oddEvenInteger;
	
	cout << endl;
	cout << "---Odd or Even---\n";
	
	oddEvenInteger = getValidNum();

	while (oddEvenInteger > 0)
	{
		if (isEven(oddEvenInteger))
			cout << oddEvenInteger << " is Even\n" << endl;
	
		else
			cout << oddEvenInteger << " is Odd\n" << endl;
		
		oddEvenInteger = getValidNum();
	}
}


/**************************************************************/
/* Function:   isEven                                         */
/* Inputs:     user integer                                   */
/* Outputs:    1 if Odd, 0 if  Even                           */
/* Purpose:    This function determines if it is odd or Even. */     
/**************************************************************/
int isEven(int number)
{
	// return 1(true) if number is even
	// or 0(false) if the number is odd
	return !(number % 2);
}


/************************************************************/
/* Function:   PrimeNumber                                  */
/* Inputs:     integer to test                              */
/* Outputs:    Displays if number is prime or not           */
/* Purpose:     Promps and validates user inpup             */
/*               And teels weather its prime or not         */
/************************************************************/
void primeNumber()
{
	int primeInteger;
	
	cout << endl;
	cout << "---Prime---\n";
	primeInteger = getValidNum();

	while (primeInteger > 0)
	{
		if (primeInteger == 1)
			cout << "Prime numbers begin after 2\n";
			
		else if (isPrime(primeInteger))	
			cout << primeInteger << " is prime\n" << endl;
	
		else									
			cout << primeInteger << " is not prime\n" << endl;
			
		primeInteger = getValidNum();
	}
}


/************************************************************/
/* Function:   isPrime                                      */
/* Inputs:     integer to test                              */
/* Outputs:    1 if prime, 0 if not prime                   */
/* Purpose:    This function takes one integer input        */
/*                  and determines if it is prime or not.   */
/************************************************************/
int isPrime (int number)
{
	
	int primeDivisor,
		primeLimit;
		
	primeLimit = sqrt(number) + 1;
	
	for (primeDivisor = 2; (primeDivisor < number) && (number % primeDivisor); primeDivisor++)
		return !(primeDivisor < primeLimit);
}


/*****************************************************/
/* Function:   getValidNum                           */
/* Inputs:     none                                  */
/* Outputs:    a positive integer                    */
/* Purpose:    This function returns a positive      */
/*             integer > 0                           */
/*****************************************************/
int getValidNum()
{
	int num;
	
    cout << "Enter a positive integer or 0 to quit: ";
    cin >> num; 
    
    while(num < 0)
    {
    	cout << "Invalid input; must be 0 or larger\n";
    	cout << "Enter a positive integer or 0 to quit: ";
    	cin >> num;
	} 
	
	return num;
}

///Function:		readCollection();
//Purpoose: 	Reads in collection
int readCollection (CD collectionCD[], int size)
{
	ifstream inCD;
	string artistCD, titleCD;
	int yearCD;
	int success = 0;
	
	inCD.open("cd.txt");
	
	if (inCD)
	{
		for (int i=0; i < size; i++)
		{
			getline(inCD, artistCD);

			getline(inCD, titleCD);
			
			inCD >> yearCD;
			inCD.ignore(100,'\n');

			collectionCD[i].setArtist(artistCD);
			collectionCD[i].setTitle(titleCD);
			collectionCD[i].setYear(yearCD);
		}
		inCD.close();
		success = 1;
	}
	else
		cout << "Could not open file\n";
		
	return success;	
	
}


//Function:		displayCollection();
//Purpose: 	Displays Information in the CD
void displayCollection(CD collectionCD[], int size)
{
	cout << "\n\n------------------------ Album Information ------------------------------\n";
	cout << left << setw(30) << "Artist" << setw(30) << "Title" << setw(10) << "Year Released\n";
	cout << "-------------------------------------------------------------------------\n\n";
	for (int i=0; i < size; i++)
	{
		cout << left << setw(30) << collectionCD[i].getArtist();
		cout << left << setw(30) << collectionCD[i].getTitle();
		cout << left << setw(10) << collectionCD[i].getYear() << endl;
		
		if (collectionCD[i].getNumTracks() > 0)
			{
				cout << "---------------------------------------------------------------\n";
				
				for (int j=0; j<collectionCD[i].getNumTracks(); j++)
				{
					cout << "	" << j+1 << ". " << collectionCD[i].getTrackName(j) << endl;
				}
			}
		else 
			{
				cout << "----------------------------------------------------------------\n";
				cout << "**NO TRACKS FOUND**\n" << endl;
			}
	}
}

//Function:		sortCollection();
//Purpoose: 	Sorts the array in ascending order by artist
void sortCollection(CD collectionCD[], int size)
{	
	string smallestArtist;
	int smallestPosition;
	CD temp;
	
	for (int start = 0; start < size-2; start++)
	{
		smallestArtist = collectionCD[start].getArtist();
		smallestPosition = start;
		for (int inner = start + 1; inner < size; inner++)
		{
			if (collectionCD[inner].getArtist() < smallestArtist)
			{
				smallestArtist = collectionCD[inner].getArtist();
				smallestPosition = inner;
			}
		}
		temp = collectionCD[start];
		collectionCD[start] = collectionCD[smallestPosition];
		collectionCD[smallestPosition] = temp;		
	}
}

//Function: 	findCD();
//Purpoose: 	Reads a CD artist and title from the keyboard and displays an appropriate message:
//              CD is in the collection or CD is not in the collection
void findCD(CD collectionCD[], int size)
{
	
	cout << "\n----Find A CD----\n";
	
	string searchArtist,
			searchTitle;
	bool foundArtist = false;
	bool foundTitle = false;
	
	cout << "Enter Artist: ";
	cin.ignore();
	getline(cin, searchArtist);
	
	for (int i=0; i < size && !foundArtist; i++)
		if (searchArtist == collectionCD[i].getArtist())
		{
			foundArtist = true;
			
			cout << "Enter Title: ";
			getline(cin, searchTitle);
			for (int i=0; i < size && !foundTitle; i++)
				if (searchTitle == collectionCD[i].getTitle())
				{
					foundTitle = true;
					cout << "\nCD is in position " << i + 1 << " in the collection\n";
				}
		}
		
	if (!foundArtist || !foundTitle)
		cout << "CD is not in collection\n";
			
}

//Function: 	editCD();
//Purpoose: 	Edits parts the user picks to edit of a CD
CD * editCD(CD collectionCD[], int size)
{
	string newArtist, newTitle;
	int newYear;
	int getEditOption();
	int editOption;
	string searchArtist, searchTitle;
	bool foundArtist = false;
	bool foundTitle = false;
	
	cout << "\n---Edit A CD---\n";
	cout << "Enter Artist: ";
	cin.ignore();
	getline(cin, searchArtist);
	
	for (int i=0; i < size && !foundArtist; i++)
		if (searchArtist == collectionCD[i].getArtist())
		{
			foundArtist = true;
			
			cout << "Enter Title: ";
			getline(cin, searchTitle);
			for (int i=0; i < size && !foundTitle; i++)
				if (searchTitle == collectionCD[i].getTitle())
				{
					foundTitle = true;
					editOneCD(&collectionCD[i]);
				}
		}
		
	if (!foundArtist || !foundTitle)
		cout << "CD is not in collection\n";
}

// Function editOneCD()
//Finds a CD to Edit
/*-----------------------*/

void editOneCD(CD * editCD)
{
	int editOption;
	string newArtist, newTitle;
	int newYear;
	int getEditOption();
	string searchArtist, searchTitle;
	
	editOption = getEditOption();
	cin.ignore(100, '\n');
	
	while (editOption != 4)
	{
		if (editOption == 1)
		{
			cout << "Enter new Artist name: ";
			getline (cin, newArtist);
			editCD->setArtist(newArtist);
		}
		
		else if (editOption == 2)
		{
			cout << "Enter new Title name: ";
			getline (cin, newTitle);
			editCD->setTitle(newTitle);		
		}
		
		else if (editOption == 3)
		{
			cout << "Enter new Year: ";
			cin >> newYear;
			editCD->setYear(newYear);								
		}
		
		cout << "\n---New CD information---\n";
		cout << "Artist: " << editCD->getArtist() << endl;
		cout << "Title: " << editCD->getTitle() << endl;
		cout << "Year Released: " << editCD->getYear() << endl;
		
		editOption = getEditOption();
		cin.ignore(100, '\n');
	}
	
}


//Function getEditCDOption()
//gets edit cd option
int getEditOption()
{
	int option;
	
	do
	{
		cout << endl;
		cout << "--Edit CD Options--\n";
		cout << "1. Edit Artist\n";
		cout << "2. Edit Title\n";
		cout << "3. Edit Year Released\n";
		cout << "4. Quit\n";
		cout << "Pick an option: ";
		cin >> option;
		
		if ((option < 1) || (option > 4))
			cout << "Invalid option\n\n";
		
	}while((option < 1) || (option > 4));
		
	return option;

}

void addTracks(CD collectionCD[], int size)
{
	string trackNameCD;
	CD numberOfTracks;
	int numTracks;
	string trackName;
	string searchArtist,
	searchTitle;
	bool foundArtist = false;
	bool foundTitle = false;	
	
	cout << "\n---Add Tracks---\n";
	
	cout << "Enter Artist: ";
	cin.ignore();
	getline(cin, searchArtist);
	
	for (int i=0; i < size && !foundArtist; i++)
		if (searchArtist == collectionCD[i].getArtist())
		{
			foundArtist = true;
			
			cout << "Enter Title: ";
			getline(cin, searchTitle);
			for (int i=0; i < size && !foundTitle; i++)
				if (searchTitle == collectionCD[i].getTitle())
				{
					foundTitle = true;
					cout << "\nCD found in position " << i + 1 << endl;
					
					cout << "How many tracks will you add? ";
					cin >> numTracks;
					cin.ignore(100, '\n');
					
					collectionCD[i].setNumTracks(numTracks);
					
					for (int j=0; j<numTracks; j++)
					{
						cout << "Enter name of track: ";
						getline(cin, trackNameCD);
						collectionCD[i].setTrackName(j, trackNameCD);
					}
				}
		}
	if (!foundArtist || !foundTitle)
		cout << "CD is not in collection\n";
	
	
}

//Function: deleteTracks
//Deletes tracks of a CD if the CD has tracks
void deleteTracks(CD collectionCD[], int size)
{
	
	cout << "\n----Delete Tracks----\n";
	
	string searchArtist, searchTitle;
	bool foundArtist = false;
	bool foundTitle = false;
	
	cout << "Enter Artist: ";
	cin.ignore(100, '\n');
	getline(cin, searchArtist);
	
	for (int i=0; i < size && !foundArtist; i++)
		if (searchArtist == collectionCD[i].getArtist())
		{
			foundArtist = true;
			
			cout << "Enter Title: ";
			getline(cin, searchTitle);
			for (int i=0; i < size && !foundTitle; i++)
				if (searchTitle == collectionCD[i].getTitle())
				{
					foundTitle = true;
				
					if (collectionCD[i].getNumTracks() > 0)
					{
						cout << "Tracks found and will be deleted\n";
						collectionCD[i].deleteTracks();
						
					}
					else if (collectionCD[i].getNumTracks() == 0)
					{
						cout << "**No tracks found to delete**\n";
					}
					
				}
		}
		
	if (!foundArtist || !foundTitle)
		cout << "CD is not in collection to delete tracks\n";
		

}

//Funtion: findRecursiveCD
//Finds a CD in the collection recursively 
void findRecursiveCD(CD collectionCD[], int size)
{	
	cout << "\n----Find A CD (Recursive)----\n";
	
	string searchArtist, searchTitle;
	bool result = false;
	
	cout << "Enter Artist: ";
	cin.ignore(100, '\n');
	getline(cin, searchArtist);
	cout << "Enter Title: ";
	getline(cin, searchTitle);
	
	result = recursionCD(collectionCD, size, searchArtist, searchTitle);
	
	if (result == true)
		cout << searchTitle << " by " << searchArtist << " was found in collection\n";
		
	else if (result == false)
		cout << "CD was not found in collection\n";
	
	else 
		cout << "Error\n";
} 

//Function: recursionCD()
// does the recursion to find CD
bool recursionCD(CD collection[], int size, string userArtist, string userTitle)
{
	if (size == 0)
		return false;
		
	if ((userArtist == collection[size-1].getArtist()) && (userTitle == collection[size-1].getTitle()))
		return true;
		
	else 
		return recursionCD(collection, size-1, userArtist, userTitle);
}


void stringReverse()
{
	string reverse;
	
	cout << "\n---Reverse String---\n";
	cout << "Enter a string: ";
	getline(cin, reverse);
	
	cout << "The string entered backwards is: ";
	recursionReverse(reverse, 0);
	cout << endl;
	
}

void recursionReverse(string word, int position)
{
	if (word.length() != position)
		{
			recursionReverse(word, position+1);
			cout << word[position];
		}
}

