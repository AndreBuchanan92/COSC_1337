#include<iostream>
#include<fstream>
#include <iomanip>  
using namespace std;


// CD class declaration
class CD
{
	private:
	// This is member variable
		string artist, title;
		int yearReleased;
	
	public:
		//default Constructor
		CD();
		//These are prototypes for the member functions
		void setArtist(string);
		void setTitle(string);
		void setYearReleased(int);
		
		string getArtist();
		string getTitle();
		int getYearReleased();	
};
/********************************************
 * 			CD :: CD
 * This is the constructor. It initializes
 * the CD class member variable.
 ********************************************/
CD::CD()
{
	artist = "";
	title = "";
 	yearReleased = 0;	
}
/********************************************
 * CD::setArtist 
 * This function assigning passing variable to the Artist member variable
 *************************************/


void CD::setArtist(string a)
{ 
	artist = a; 
}
/********************************************
 * CD::setTitle *
 * This function assigning passing variable to the Title member variable 
 *************************************/

void CD::setTitle(string t)
{
	title = t;
}
/********************************************
 * CD::setYearReleased *
 * This function assigning passing variable to the YearReleased member variable
 *************************************/
void CD::setYearReleased(int y)
{
	yearReleased = y;
}

/**********************************************
* CD :: getArtist 
* This function  returns the Artist .It does not need any
* parameters because it can directly access the member variable Artist. 
***********************************************/
string CD::getArtist()
{
	return artist;
}
/**********************************************
 * CD :: getTitle 
 * This function  returns the Title .It does not need any
 * parameters because it can directly access the member variable Title. 
 *******************************************/
string CD::getTitle()
{
	return title;
}
/**********************************************
 * CD :: getYearReleased 
 * This function  returns the YearReleased .It does not need any
 * parameters because it can directly access the member variable YearReleased.
 ********************************************/
int CD::getYearReleased()
{
	return yearReleased;
}


void mathBreak();
void evenOdd();
bool isEven(int number);
void primeNumber();
bool isPrime(int number);
void readData(CD []);
void displayCollection(CD []);
void sortCollection(CD []);
int findCD(CD []);

const int SIZE=17;

/********************************************************/
/*					Main								*/		
/********************************************************/
int main()
{		
	// declare local variable option 
	int option;
	CD cds[SIZE];

	do
	{	
		//display main menu options
		cout<< "*****************************"<<endl;
		cout<< "Main Menu"<<endl;
		cout<< "------------------------------"<<endl;
		cout << "1. Read Collection" << endl;
		cout << "2. Display Collection" << endl;
		cout << "3. Sort Collection" << endl;
		cout << "4. Find a CD" << endl;
		cout << "5. Edit a CD" << endl;		
		cout << "6. Math Break"<<endl;
		cout << "7. Quit" << endl;
		cout << "option : ";
		// read option from user input
		cin>> option;
		
		//if user enter invalid number then get new input
		while(option < 0 && option > 8 )
		{
			cout << "Invalid option entered. Please enter valid option : ";
			cin>> option;
		}

		if (option == 1)
		{
			// calling readData to read data from file
			readData(cds);
		}
		
		//if file did open then user are allow tp select option 2 to 5
		else if (option == 2)
		{
			// check if file has been read properly
			if (cds[0].getArtist().empty()==0)
			{
				//calling displayCollection function to dispaly CDs infromation
				displayCollection(cds);	
			}
			// if file did not open then display following error message
			else
			{
				cout << "\nYou did not read the collection or file did not opened properly. " << endl<< endl;
			}
						
		}
			
		else if (option == 3)
		{
			// check if file has been read properly	
			if (cds[0].getArtist().empty()==0)
			{
				//calling shortCollection function to sort the cd data
				sortCollection(cds);
			}
			// if file did not open then display following error message
			else
			{
				cout << "\nYou did not read the collection or file did not opened properly. " << endl<< endl;
			}			
		}
			
		else if (option == 4)
		{
			// check if file has been read properly		
			if (cds[0].getArtist().empty()==0)
			{
				// calling find findcd fucntion look up a cd information
				int foundat=findCD(cds);
				if(foundat!=-1){
					cout << "Title: " << cds[foundat].getTitle() << " and Artist: " << cds[foundat].getArtist()  << " is found in the CD collection." << endl<<endl;	
				}
				
			}
			// if file did not open then display following error message
			else
			{
				cout << "\nYou did not read the collection or file did not opened properly. " << endl<< endl;
			}				
		}
			
		else if (option == 5)
		{
			// check if file has been read properly
			if (cds[0].getArtist().empty()==0)
			{

			}
			// if file did not open then display following error message
			else
			{
				cout << "\nYou did not read the collection or file did not opened properly. " << endl<< endl;
			}			
		}		
		else if(option==6)
		{
			// call Math break function to Display math break options 
			mathBreak();	
		}
	//continue untill user enter quit option to quit main menu	
	}while(option!=7);
	return 0;		
}

//start math break function
void mathBreak()
{
	// declare local variable option 	
	int option;

	do
	{	
		// Display math break options
		cout<<"\n****************************"<<endl;
		cout<<"Math Break Menu"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"1. Even or odd"<<endl;
		cout<<"2. Prime Number"<<endl;
		cout<<"3. End my Math Break"<<endl;
		cout<<"Option:";
		// read option from user input
		cin>> option;
		
		//if user enter invalid number then get new input
		while(option!=1 && option!=2 && option!=3){
			cout << "option : ";
			cin>> option;
		}		

	   	if(option==2)
		{
			// calling primeNumber() funtion  to test a number is prime or not
			primeNumber();
		}		
		else if(option==1)
		{
			// calling evenOdd() funtion to test a number is even or odd
			evenOdd();
		}
		
	//continue untill user enter End my Math Break option to quit math break menu
	}while(option!=3);
}

//even or odd
void evenOdd()
{	
	// declare local variable number
	int number;
	
	do	
	{
		// dispay friendly messay to enter positive number or zero 	
		cout<< "\nEnter a positive integer or 0 to quit : ";
		//read number from user input
		cin>> number;
		
		//if user enter grater than zero then go inside of if conditon
		if (number> 0)
		{	
				
			// if isEven function return true then go to inside if otherwise execute else statement
			if(isEven(number))   
			{
				// display user input number is even 
				cout<< number<<" is an even number."<<endl;
			}
		
			else
			{
				// display user input number is odd
				cout<< number << " is an odd number."<<endl;
			}
		}
		//if user enten negative number then do nothing

	//continue untill user enter zero to quit loop				
	}while(number!= 0);	
}


//check if even
bool isEven(int number){
	// declare local boolean variable even
	bool even;

	//if number modulus 2 is zero then execute if statement otherwise execute else statement
	if(number%2==0)   
	{
		//set bool variable to true for even nuber
		even=true;
	}
	else 
	{
		//set bool variable to false for odd nuber
		even=false;
	}
	
	//return boolean variable even
	return even;
}


//check if prime   
void primeNumber()
{
	// declare local variable number
	int number;
	
	do
	{
	// dispay friendly messay to enter positive number or zero 
	cout<<"\nEnter a positive integer or 0 to quit : ";
	//read number from user input
	cin>>number;

	//if user enter grater than zero then go inside of if conditon
	if(number>0)
	{
		// if isPrime function return true then go to inside if otherwise execute else statement
		if(isPrime(number))
		{	
			// Display message for prime number
			cout<< number<<" is a prime number."<<endl;			
		}
		else 
		{		
			// Display message for not prime number
			cout<< number<<" is not a prime number."<<endl;	
		}
	}

	//if user enten negative number then do nothing

	//continue untill user enter zero to quit loop					
	}while(number!=0);

}

//check if prime                
bool isPrime(int number)
{
	// declare and Initialize local boolean variable prime to true
	bool  prime = true;
	
    // run for loop to check for not prime number
	for(int i=2; i<number && prime==true; i++)
	{
		//if number modulus i is zero then number is not prime
		if(number%i==0)
		{
			//set bool variable to false for not a prime nuber
			prime=false;	
		}
	}
	
	//return boolean local variable prime 
	return prime ;	
}

//read data 
void readData(CD cd[])
{
	
	string artist, title;	
	int yearReleased;	
	
	ifstream inFile;
	inFile.open("cd.txt");
	// if file open properly then get the data from file	
	if(inFile)
	{
		for( int i =0; i <SIZE; i++)
		{
			//read data from file
			getline(inFile,artist);
			getline(inFile,title);
			inFile>>yearReleased;
			inFile.ignore();
			
			//setting up cd infromation opject in a array
			cd[i].setArtist(artist);
			cd[i].setTitle(title);
			cd[i].setYearReleased(yearReleased);
		}
		cout<<"\nThe collection has been read properly\n";
		//close the file
		inFile.close();
	}
	
	else
	{	// display error message if incase file could not opened
		cout << "File could not be opened. " << endl;		
	}
}
//display collection
void displayCollection(CD cds[])
{
	//display header
	cout  <<"\n\n"<<left<<setw(30)<<"Artist" <<left<<setw(30)<<"Title"<<"\t"<<"Year Released" << endl;
	cout  <<left<<setw(30)<<"------" <<left<<setw(30)<<"-----"<<"\t"<<"-------------" << endl;
	// loop throw array data to display on screen
	for(int i = 0; i <SIZE; i++)
	{
		cout <<left<<setw(30)<<cds[i].getArtist() << left<<setw(30) << cds [i].getTitle()  << "\t" << cds[i].getYearReleased()<< endl;		
	}
	// leave two empty lines after collected displayed
	cout<<endl<<endl;
}

//sortCollection
void sortCollection(CD cds[])
{
	//declar and initialize bool variable
	bool swapped = true;
	// create temp CD opject
	CD temp;
	// loop till sort complite
	while(swapped)
	{
		swapped = false;
		//loop all the collection in the arrays 
		for(int i = 0; i < SIZE -1; i++)
		{
			//compare artist name in the collection
			if(cds[i].getArtist() > cds[i+1].getArtist())
			{
				//take curent i index value into temp
				temp.setTitle(cds[i].getTitle());
				temp.setArtist(cds[i].getArtist());
				temp.setYearReleased(cds[i].getYearReleased());
				
				// take next intex value into current index
				cds[i].setTitle(cds[i+1].getTitle());
				cds[i].setArtist(cds[i+1].getArtist());
				cds[i].setYearReleased(cds[i+1].getYearReleased());
				// take temp value into next index
				cds[i+1].setTitle(temp.getTitle());
				cds[i+1].setArtist(temp.getArtist());
				cds[i+1].setYearReleased(temp.getYearReleased());
				
				swapped = true;
			}
		}
	}
	// display friedly message for sort collection
	cout << "CD collection has been sorted in assending order by artist. " << endl;
}
//find CD
int findCD(CD cds[])
{
	//declare variable
	int foundAt=-1;	
	string artistName;
	string titleName;
	
	cin.ignore();
	//take user keyboad input for artist and title of cd collection
	cout << "Enter a CD artist name: " ;
	getline(cin,artistName);
	cout<< "Enter the CD Title : ";
	getline(cin,titleName);
	// loop throw cd collection
	for(int i = 0; i < SIZE & foundAt==-1; i++)
	{
		//if title and artist found in CD collection then print message and exit loop
		if(cds[i].getTitle().compare(titleName) == 0 & cds[i].getArtist().compare(artistName) == 0)
		{		
			foundAt=i;		
		}
	}
	//if title and artist not found in CD collection then print message
	if(foundAt==-1)
	{
		cout << "Title: " << titleName << " and Artist: " << artistName 
				<< " is not found in the CD collection." << endl<<endl;
	}
	
	return foundAt;	
}




