/*********************************************************************/
/* Lab 1 Solution                                                    */
/* This program diplays a main menu of options to manage a small CD  */
/* collection with the following options:                            */
/*       1. Read Collection                                          */
/*       2. Display Collection                                       */
/*       3. Sort Collection                                          */
/*       4. Find a CD                                                */
/*       5. Edit a CD                                                */
/*       6. Math Break                                               */
/*       7. Quit                                                     */
/*                                                                   */
/* It will be implemented in stages.                                 */
/* This stage has the following optiions implemented:                */
/*       1. Math Break                                               */
/*       2. Quit                                                     */
/*                                                                   */
/* Math Break has its own menu:                                      */
/*       1. Even or Odd                                              */
/*       2. Prime Number                                             */
/*       3. Quit                                                     */
/*********************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Cd
{
	private:
		string artist = "";
		string title = "";
		int yearReleased = 0;
	public:
		void setArtist(string a){artist = a;}
		void setTitle(string b){title = b;}
		void setYearReleased(int c){yearReleased = c;}
		
		string getArtist(){return artist;}
		string getTitle(){return title;}
		int getYearReleased(){return yearReleased;}
};



// Function prototypes
int getMainMenuOption();
void mathBreak();
int getMathBreakOption();
void evenOdd();
void primeNumber();
int getPositiveInt();
int isEven(int);
int isPrime(int);
void displayTestCD();
int CD();

int main()
{
	//Geeks obj1;
    // Variable Declarations
    int option;				// option returned by function
        
	// Get the first option
    option = getMainMenuOption();
    
    // Continue to display the main menu
    // until user chooses to quit
    while (option != 3)
    {
    	switch (option)
    	{
    		case 1:
				//display CD option 
                displayTestCD();
				break;
    		case 2:
    			// Math Break option
    			mathBreak();
    			break;
    	}
    		
    	// Get the next option
    	option = getMainMenuOption();
    
    } // end while option is not quit
    
} // end main

/*****************************************************/
/* Function:   getMainMenuOption                     */
/* Inputs:     none                                  */
/* Outputs:    a valid user option                   */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option, validates          */
/*             and returns it.                       */
/*             Menu options:                         */
/*             1. Math Break                         */
/*             2. Quit                               */
/*****************************************************/
int getMainMenuOption()
{
	// Variable Declarations
    int option;				// option entered by user
    
	do
	{
	    // Display main menu
	    cout << "\n*************\n";
	    cout << "Main Menu\n";
	    cout << "-----------\n";
	    cout << "1. Display Test CD\n";
	    cout << "2. Math Break\n";
	    cout << "3. Quit\n";
	    
	    // Read the first option
	    cout << "Option: ";
	    cin >> option;
	    
	    // Display error message for invalid options
	    if ((option < 1) || (option > 3))
			cout << "Invalid option\n\n";
			
	} while ((option < 1) || (option > 2));
	
	return option;
	                                                      
} // end getMainMenuOption()


void displayTestCD()

{

// create a test cd

       Cd cd1 ;

       cd1.setArtist("Test Artist");

       cd1.setTitle("Test Title");

       cd1.setYearReleased(1995);

// display a test cd

       cout<<"\n Details of Test CD : "<<endl;

       cout<<" Artist : "<<cd1.getArtist()<<endl;

       cout<<" Title : "<<cd1.getTitle()<<endl;

       cout<<" Year Released : "<<cd1.getYearReleased()<<endl;

}


    
/*****************************************************/
/* Function:   mathBreak                             */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option and plays the game. */
/*             Menu options:                         */
/*             1. Even or Odd                        */
/*             2. Prime Number                       */
/*             3. Quit                               */
/*****************************************************/
void mathBreak()
{	

       // add code for math break option

       cout<<"\n You selected Math break option"<<endl;
    // Variable Declarations
	int option;				// option entered by user
	
	// Get the first option
	option = getMathBreakOption();
    	
	// Check for option to quit
	while(option != 3) 
	{
		switch (option)
		{
			case 1:		// Even or Odd
				evenOdd();
				break;
			case 2:		// Prime Number
				primeNumber();
				break;
				
		} // end switch
		
		// Get the next option	
		option = getMathBreakOption();
			
	} // end while option is not quit
		
} // end mathBreak()

/*****************************************************/
/* Function:   getMathBreakOption                    */
/* Inputs:     none                                  */
/* Outputs:    a valid user option                   */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option, validates          */
/*             and returns it.                       */
/*             Menu options:                         */
/*             1. Math Break                         */
/*             2. Quit                               */
/*****************************************************/
int getMathBreakOption()
{
	// Variable Declarations
    int option;				// option entered by user
    
	do
	{
		// Display main menu
    	cout << "\n***************\n";
		cout << "Math Break Menu\n";
		cout << "---------------\n";
    	cout << "1. Even or Oddk\n";
    	cout << "2. Prime Number\n";
    	cout << "3. Quit\n";
    	
        // Read the option
        cout << "Option: ";
    	cin >> option;
    	
    	// Display error message for invalid options
    	if ((option < 1) || (option > 3))
			cout << "Invalid option\n\n";
			
	} while ((option < 1) || (option > 3));
	
	return option;
	
} // end getMathBreakOption()

/*****************************************************/
/* Function:   evenOdd                               */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This function prompts the user for a  */
/*             positive integer and displays a       */
/*             message identifying whether the int   */
/*             is even or odd.                       */ 
/*****************************************************/
void evenOdd()
{
	// Variable Declarations
	int num;	// User input
	
	// Display heading for the game
	cout << "\n     Even or Odd\n";
	cout << "********************\n";
	
	// Read first integer
    num = getPositiveInt();
    
    // Continue to ask for numbers 
    // until the user enters zero
    while (num > 0)
    {
    	// Identify whether the number
    	// is even or odd
    	if (isEven(num))
    		cout << num << " is even\n";
    	else
    		cout << num << " is odd\n";
    		
    	// Read next integer
    	num = getPositiveInt();
		
	} // end while number is > 0
	
} // end evenOdd()

/*****************************************************/
/* Function:   isEven                                */
/* Inputs:     integer to be tested                  */
/* Outputs:    1 if even, 0 if odd                   */
/* Purpose:    This function takes one integer input */
/*             and determines if it is even or odd . */
/*****************************************************/
int isEven(int number)
{
	// return 1(true) if number is even
	// or 0(false) if the number is odd
	return !(number % 2);
}

/*****************************************************/
/* Function:   primeNumber                           */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This function prompts the user for a  */
/*             positive integer and displays a       */
/*             message identifying whether the int   */
/*             is prime or not.                      */ 
/*****************************************************/
void primeNumber()
{
	// Variable Declarations
	int num;	// User input
	
	cout << "\n     Prime Number\n";
	cout << "********************\n";
	
	// Read first integer
    num = getPositiveInt();
    
    while (num > 0)
    {
    	// Prime numbers start at 2
    	if (num == 1)
    		cout << "Prime numbers start at 2\n";
    	else if (isPrime(num))
    		cout << num << " is prime\n";
    	else
    		cout << num << " is not prime\n";
    		
    	// Read next integer
    	num = getPositiveInt();
		
	} // end while num > 0
	
} // end primeNumber()

/*****************************************************/
/* Function:   isPrime                               */
/* Inputs:     integer to test                       */
/* Outputs:    1 if prime, 0 if not prime            */
/* Purpose:    This function takes one integer input */
/*             and determines if it is prime or not. */
/*****************************************************/
int isPrime(int number)
{
    // Variable declarations
    int limit,  // Upper limit for loop
        i;		// Loop control variable
    
    // Set the limit for the loop -
    // No need to interate through all the numbers
    // between 2 and the number.
    // This makes the loop more efficient.
    limit = sqrt(number) + 1;
    
    // See if any nmber between 2 and 
    // the square root of the number
    // evenly divides into the number
    for(i=2; (i < limit) && (number % i); i++);
    
    // If 'i' reaches the value of number,
    // it is prime; any value of 'i'
    // less than that means it is not prime.
    return !(i<limit);
} // end isPrime()

/*****************************************************/
/* Function:   getPositiveInt                        */
/* Inputs:     none                                  */
/* Outputs:    a positive integer                    */
/* Purpose:    This function returns a positive      */
/*             integer > 0                           */
/*****************************************************/
int getPositiveInt()
{
	// Variable declarations
	int num;	// user input
	
	// Read integer
    cout << "Enter a positive integer or 0 to quit: ";
    cin >> num; 
    
    // Validate the input
    // numbers must be 0 or larger
    while(num < 0)
    {
    	cout << "Invalid input; must be 0 or larger\n";
    	cout << "Enter a positive integer or 0 to quit: ";
    	cin >> num;
	} // end while input is invalid
	
	// Return valid input
	return num;
	
} // end getPositiveInt()
