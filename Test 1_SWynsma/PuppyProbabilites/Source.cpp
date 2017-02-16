////////////////
// Samuel Wynsma
// 9/24/14
// CS 171-3
// Exam 1
////////////////

////////////////////////////////////////////////////////////////////////////
//	Input with appropriate prompts	(10) 
//	Correctly compute probabilities (10) 
//	Variable data types(10) 
//	Output probabilities, test (10)
//	Appropriate comments (10)

//	Total =  50   /50    Very nice!!!
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

int main()
{
	/* The number of puppies are intergers because we cannot have part of a puppy. 
	The probabilites are decimals becauuse chance can have a non-whole number */
	int boyPuppies;
	int girlPuppies;
	double ProbBoys;
	double ProbGirls;

	cout << "Enter the number of girls in a 3 puppy litter: ";
	cin >> girlPuppies;
	ProbGirls = (-0.125*girlPuppies*girlPuppies + 0.375*girlPuppies + 0.125); // This is the probability formula for the girl puppies. I used decimal equivalents to 1/8 and 3/8.
	cout << "The probability of a litter with " << girlPuppies << 
		" is " <<  ProbGirls << endl;
	
	cout << "Enter the number of boys in a 3 puppy litter: ";
	cin >> boyPuppies;
	ProbBoys = (-0.125*boyPuppies*boyPuppies + 0.375*boyPuppies + 0.125); // This is the probability for the boy puppies. It is the same code as the probability for the girl puppies.
	cout << "The probability of a litter with " << boyPuppies <<
		" is " << ProbBoys << endl;

	return 0;
}