/*
 * Programming Challenge 11
 */
#include <cassert>
#include <iomanip>
#include <iostream>
using namespace std;

/*
 * Class Prize. A class representing a simple prize, such as for a gameshow.
 */
class Prize
{
	public:
	
		// CODE HERE -- DECLARE FUNCTIONS
		
		/*
		 * Constructor.
		 * @param newName string containing a name for this Prize; default argument is "no name!";
		 *        if newValue is > 100, converts name to all capital letters and concatenates a '!'
		 *        at the end of name
		 * @param newValue unsigned int containing a value for this Prize; default argument is 0
		 */
		 
		 Prize (string newName="no name!", unsigned int newValue=0);
	
		/*
		 * Get this Prize's name
		 * @return a string containing this Prize's name
		 */
		 
		 string getName () const;
		
		/*
		 * Get this Prize's value
		 * @return an unsigned int containing this Prize's value
		 */
		 
		 unsigned int getValue () const;
		
	private:
	
		string name;
		unsigned int value;
};

/*
 * Class SecretDoor. A class representing a "secret door" such as might be used on a game show.
 * Contains a Prize.
 */
class SecretDoor
{
	public:
	
		// CODE HERE -- DECLARE FUNCTIONS
		
		/*
		 * Constructor.
		 * @param newNumber unsigned int containing a value for this SecretDoor's number; default argument is 1
		 * @param newPrize Prize containing a Prize that is "hidden" behind this secret door; default argument 
		 *        is Prize()
		 */
		 
		 SecretDoor (unsigned int newNumber=1, Prize newPrize=Prize());
		
		/*
		 * Get this SecretDoor's number.
		 * @return an unsigned int containing this SecretDoor's number
		 */
		 
		 unsigned int getNumber () const;
		
		/*
		 * Get this SecretDoor's Prize.
		 * @return the Prize, by reference, "hidden behind" this SecretDoor
		 */
		 
		 Prize getPrize () const;
		
	private:
	
		unsigned int number;
		Prize prize;
};

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main ()
{
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS FOR PRIZE; USE INITIALIZER SECTION FOR CONSTRUCTOR

Prize::Prize (string newName, unsigned int newValue)
: name(newName), value(newValue)
{
    if(newValue > 100)
    {
        for(unsigned int i=0; i < newName.length(); i++)
        {
            newName[i] = toupper(newName[i]);
        }
        
        newName += '!';
        
    }
    
}

string Prize::getName () const
{
    return name;
}

unsigned int Prize::getValue () const
{
    return value;
}

// CODE HERE -- FUNCTION DEFINITIONS FOR SECRETDOOR; USE INITIALIZER SECTION FOR CONSTRUCTOR

SecretDoor::SecretDoor (unsigned int newNumber, Prize newPrize)
{
    number = newNumber;
    prize = newPrize;
}

unsigned int SecretDoor::getNumber () const
{
    return number;
}

Prize SecretDoor::getPrize () const
{
    return prize;
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";
	Prize * prizePointer;
	SecretDoor * doorPointer;
	try {
		prizePointer = new Prize();
		btassert<bool>(prizePointer->getName() == "no name!" && prizePointer->getValue() == 0);
		cout << "Passed TEST 1: CREATING A PRIZE () \n";
	} catch (bool b) {
		cout << "# FAILED TEST 1: CREATING A PRIZE () #\n";
	}
	delete prizePointer;
	try {
		prizePointer = new Prize("A Brand New Car");
		btassert<bool>(prizePointer->getName() == "A Brand New Car" && prizePointer->getValue() == 0);
		cout << "Passed TEST 2: CREATING A PRIZE (NAME) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 2: CREATING A PRIZE (NAME) #\n";
	}
	delete prizePointer;
	try {
		prizePointer = new Prize("A Couch",1000);
		btassert<bool>(prizePointer->getName() == "A COUCH!" && prizePointer->getValue() == 1000);
		cout << "Passed TEST 3: CREATING A PRIZE (NAME,VALUE) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 3: CREATING A PRIZE (NAME,VALUE) #\n";
	}

	try {
		doorPointer = new SecretDoor();
		btassert<bool>(doorPointer->getPrize().getName() == "no name!" && doorPointer->getNumber() == 1);
		cout << "Passed TEST 4: CREATING A SECRET DOOR () \n";
	} catch (bool b) {
		cout << "# FAILED TEST 4: CREATING A SECRET DOOR () #\n";
	}
	delete doorPointer;
	try {
		doorPointer = new SecretDoor(5);
		btassert<bool>(doorPointer->getPrize().getName() == "no name!" && doorPointer->getNumber() == 5);
		cout << "Passed TEST 5: CREATING A SECRET DOOR (NUMBER) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 5: CREATING A SECRET DOOR (NUMBER) #\n";
	}
	delete doorPointer;
	try {
		doorPointer = new SecretDoor(5,*prizePointer);
		btassert<bool>(doorPointer->getPrize().getName() == "A COUCH!" && doorPointer->getNumber() == 5);
		cout << "Passed TEST 6: CREATING A SECRET DOOR (NUMBER,PRIZE) \n";
	} catch (bool b) {
		cout << "# FAILED TEST 6: CREATING A SECRET DOOR (NUMBER,PRIZE) #\n";
	}
	delete doorPointer;
	delete prizePointer;
		
	cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}