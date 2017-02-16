////////////////
// Samuel Wynsma
// 10/22/14
// CS 171-3
// Exam 2
////////////////

#include <iostream>
#include <string> // Including my small touch.
using namespace std;

int main()
{
	double AvgSeedScoop, FeedAmount, SeedAmount, TTLScoop = 0; // Initializing my variables. 
	int days; // Days is an interger. We cannot have a 2.5rd day.
	string st;
	cout << "We need to determine how much seed to feed our turkeys and quail by knowing how much seed we have given in the past 3 days. \n";

	for (days = 0; days < 3; days++)
	{
		switch (days) // This is not necessary code, however it makes the code look better. Saying 2st day does not sound right.
		{
		case 0: st = "st"; break;
		case 1: st = "nd"; break;
		case 2: st = "rd"; break;
		}

		// This is the question that we ask to obtain the amount of seed.
		cout << "How much was the seed amount for the " << days+1 << st <<  " day \n";
		cin >> SeedAmount;
		while (SeedAmount < 0 || SeedAmount > 3) // We are doing a loop here to check and see if the seed amount is valid. If not, it will continue to try again until it finds a valid value.
		{
			cout << "Invalid seed amount: try again. \n";
			cin >> SeedAmount;
		}
		TTLScoop += SeedAmount; // This adds up the seed amount.


	}

	AvgSeedScoop = (TTLScoop / 3.0); // The average is the seed amount divided by the days
	if (AvgSeedScoop < 1 && AvgSeedScoop >= 0)
		FeedAmount = 2;
	else if (AvgSeedScoop >= 1 && AvgSeedScoop < 2.5)
		FeedAmount = 0.5;
	else if (AvgSeedScoop >= 2.5 && AvgSeedScoop <= 3.0)
		FeedAmount = 0;

	cout << "The average seed scoop for the past three days is " << AvgSeedScoop << endl;
	cout << "Looks like we need " << FeedAmount << " scoops of seed for today \n";
	return 0;
}