////////////////
// Samuel Wynsma
// Semester Project
// CS 171-1
// 9/22/14
////////////////

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
// Some sprint 6 specifics.
const int ARSIZE = 100;
int Tries[ARSIZE];
int Correct[ARSIZE];
int problemNumber = 0;


// Major changes for sprint 5
void welcome()
{
	string userName;
	char answer;
	cout << "Welcome to the basic mathematics tutor. This is a tutor for adding, subtracting, multiplying, and dividing." << endl;
	cout << "What is your name?";
	getline(cin, userName);
	cout << "Nice to meet you, " << userName << endl;
}

char MainMenu()
{
	char subjectChoice;
	cout << "What subject do you want to do? \n";
	cout << "a) Addition \n";
	cout << "b) Subtraction \n";
	cout << "c) Multiplication \n";
	cout << "d) Division \n";

	cout << "Which tutor would you like to work with? ";
	cin >> subjectChoice;
	return subjectChoice;
}


void RandomizeForNormalProb(int& x, int& y)
{
	srand(time(NULL));
	x = rand() % 10;
	y = rand() % 10;
	if (y > x)
	{
		int temp = x;
		x = y; 
		y = temp;
	}
}

void RandomizeForAddSubDivQuiz(int&r, int& s, string z)
{
	srand(time(NULL));
	r = rand() % 100;
	s = rand() % 50;
	while ((r % s != 0) && z == "Div")
		r++;
}

void RandomizeForMultQuiz(int& r, int& s)
{
	srand(time(NULL));
	r = rand() % 20;
	s = rand() % 10;
}



bool TryAgain()
{
	char x;
	cout << "Do you want to try again? (Y or N)";
	cin >> x;
	if (x == 'N' || x == 'n')
	{
		return false;
	}
	return true;
}

bool TryNewProblem()
{
	char x;
	cout << "Do you want to try a new problem? (Y or N)";
	cin >> x;
	if (x == 'N' || x == 'n')
	{
		return false;
	}
	return true;
}

bool StartPrompt()
{
	char z;
	cout << "Do you want to take a five problem quiz? (Q) or do you want to do a single problem? (anything else) \n";
	cin >> z;
	if (z == 'Q' || z == 'q')
	{
		return true;
	}
	return false;

}

char AnswerPrompt()
{
	char h;
	cout << "Please type in the letter of your answer \n";
	cout << "Your answer is ";
	cin >> h;
	return h;
}
// Unnecesary function, but put in in order to completely randomize the correct answer in the multiple choice practice problems.
char RandomizeAnswerPosition(int a, int b, string c)
{
	int ans1, ans2, ans3;
	char CorrectAnswer;
	srand(time(NULL));
	int WhichAnswer = rand() % 4;
	switch (WhichAnswer)
	{
	case 0:
	{
		if (c == "Add")
		{
			ans1 = a + b;
			ans2 = (a + b + 2);
			ans3 = (a - b - 1);
		}
		else if (c == "Sub")
		{
			ans1 = a - b;
			ans2 = (a - b + 2);
			ans3 = (a * b);
		}
		else if (c == "Mult")
		{
			ans1 = a * b;
			ans2 = (a / b - 1);
			ans3 = (a * b + 2);
		}
		else
		{
			ans1 = a / b;
			ans2 = (a * b + 1);
			ans3 = (a - b);
		}
		CorrectAnswer = 'a';
		break;
	}
	case 1:
	{
		if (c == "Add")
		{
			ans2 = a + b;
			ans1 = (a + b + 2);
			ans3 = (a - b - 1);
		}
		else if (c == "Sub")
		{
			ans2 = a - b;
			ans1 = (a - b + 2);
			ans3 = (a * b);
		}
		else if (c == "Mult")
		{
			ans2 = a * b;
			ans1 = (a / b - 1);
			ans3 = (a * b + 2);
		}
		else
		{
			ans2 = a / b;
			ans1 = (a * b + 1);
			ans3 = (a - b);
		}
		CorrectAnswer = 'b';
		break;
	}
	case 2:
	{
		if (c == "Add")
		{
			ans3 = a + b;
			ans1 = (a + b + 2);
			ans2 = (a - b - 1);
		}
		else if (c == "Sub")
		{
			ans3 = a - b;
			ans1 = (a - b + 2);
			ans2 = (a * b);
		}
		else if (c == "Mult")
		{
			ans3 = a * b;
			ans1 = (a / b - 1);
			ans2 = (a * b + 2);
		}
		else
		{
			ans3 = a / b;
			ans1 = (a * b + 1);
			ans2 = (a - b);
		}
		CorrectAnswer = 'c';
		break;
	}
	case 3:
	{
		if (c == "Add")
		{
			ans3 = (a + b - 4);
			ans1 = (a + b + 2);
			ans2 = (a - b - 1);
		}
		else if (c == "Sub")
		{
			ans3 = (a - b - 5);
			ans1 = (a - b + 2);
			ans2 = (a * b);
		}
		else if (c == "Mult")
		{
			ans3 = (a * b / 4);
			ans1 = (a / b - 1);
			ans2 = (a * b + 2);
		}
		else
		{
			ans3 = (a / b - 10);
			ans1 = (a * b + 1);
			ans2 = (a - b);
		}
		CorrectAnswer = 'd';
		break;
	}
	}
	if (c == "Add") cout << "What is the answer to " << a << " + " << b << endl;
	if (c == "Sub") cout << "What is the answer to " << a << " - " << b << endl;
	if (c == "Mult") cout << "What is the answer to " << a << " * " << b << endl;
	if (c == "Div") cout << "What is the answer to " << a << " / " << b << endl;

	cout << "a) " << ans1 << endl;
	cout << "b) " << ans2 << endl;
	cout << "c) " << ans3 << endl;
	cout << "d) None of the Above \n";
	return CorrectAnswer;

}
// Sprint 6 material
void ProgramStats()
{
	cout << "You did " << problemNumber << " problems \n";
	double summer = 0, corrector = 0;
	for (int i = 0; i < problemNumber; i++)
	{
		cout << "You tried the " << (i + 1) << " problem " << Tries[i] << " times and got it correct " << Correct[i] << " times. \n";
		summer += Tries[i];
		corrector += Correct[i];
	}
	double percent = ((corrector / summer) * 100);
	cout << "The percent of answers that you got right is " << percent << "% \n";
}

void Addition(int numOfQs, int QuizAnswer, int correctAnswer)
{
	string t = "Add";
	char j;
	int x, y, n;
	// new stuff for sprint 4
	
	if (StartPrompt())
	{
		do
		{
		for (int i = 1; i <= numOfQs; i++)
		{
			RandomizeForAddSubDivQuiz(x, y, t);
			cout << "What does " << x << " + " << y << " equal " << endl;
			cin >> QuizAnswer;
			if (QuizAnswer == x + y)
			{
				correctAnswer++;
			}
		}

		cout << "Out of " << numOfQs << " questions, you got " << correctAnswer << " correct." << endl;
		correctAnswer = 0;
		} while (TryAgain());
	}
	else
	{
		do
		{
			RandomizeForNormalProb(x, y);
			do
			{
			
				do
				{
					// old stuff from sprint 3 or earlier
					n = RandomizeAnswerPosition(x, y, t);
					j = AnswerPrompt();
					if (j == n)
					{
						cout << "Correct! \n";
						Tries[problemNumber]++;
						Correct[problemNumber]++;
					}
					else
					{
						cout << "Wrong \n";
						Tries[problemNumber]++;
					}
				} while (j != n);

			} while (TryAgain());
			problemNumber++;
		} while (TryNewProblem());

		ProgramStats();
		
	}

}


void Subtraction(int numOfQs, int QuizAnswer, int correctAnswer)
{
	string t = "Sub";
	int x, y, n;
	char j;
	// new stuff for sprint 4
	if (StartPrompt())
	{
		do
		{
		for (int i = 1; i <= numOfQs; i++)
		{
			RandomizeForAddSubDivQuiz(x, y, t);
			cout << "What does " << x << " - " << y << " equal " << endl;
			cin >> QuizAnswer;
			if (QuizAnswer == x - y)
			{
				correctAnswer++;
			}
		}

		cout << "Out of " << numOfQs << " questions, you got " << correctAnswer << " correct." << endl;
		correctAnswer = 0;
		} while (TryAgain());
	}
	else
	{
		do
		{
			RandomizeForNormalProb(x, y);
			do
			{
				do
				{
					// old stuff
					n = RandomizeAnswerPosition(x, y, t);
					j = AnswerPrompt();
					if (j == n)
					{
						cout << "Correct! \n";
						Tries[problemNumber]++;
						Correct[problemNumber]++;
					}
					else
					{
						cout << "Wrong \n";
						Tries[problemNumber]++;
					}
				} while (j != n);

			} while (TryAgain());
			problemNumber++;
		} while (TryNewProblem());

		ProgramStats();
	}
}

void Multiplication(int numOfQs, int QuizAnswer, int correctAnswer)
{
	int x, y, n;
	string t = "Mult";
	char j;
	// new stuff for sprint 4
	if (StartPrompt())
	{
		do
		{
			for (int i = 1; i <= numOfQs; i++)
			{
				RandomizeForMultQuiz(x, y);
				cout << "What does " << x << " * " << y << " equal" << endl;
				cin >> QuizAnswer;
				if (QuizAnswer == x * y)
				{
					correctAnswer++;
				}
			}
			cout << "Out of " << numOfQs << " questions, you got " << correctAnswer << " correct." << endl;
			correctAnswer = 0;
		} while (TryAgain());

	}
	else
	{
		do
		{
			RandomizeForNormalProb(x, y);
			do
			{	
				do
				{
					// back to the old stuff from sprint 3
					n = RandomizeAnswerPosition(x, y, t);
					j = AnswerPrompt();
					if (j == n)
					{
						cout << "Correct! \n";
						Tries[problemNumber]++;
						Correct[problemNumber]++;
					}
					else
					{
						cout << "Wrong \n";
						Tries[problemNumber]++;
					}
				} while (j != n);

			} while (TryAgain());
			problemNumber++;
		} while (TryNewProblem());

		ProgramStats();

	}
}

void Division(int numOfQs, int QuizAnswer, int correctAnswer)
{
	int x, y, n;
	string Div = "Div";
	char j;
	// new stuff for sprint 4
	if (StartPrompt())
	{
		do
		{
			for (int i = 1; i <= numOfQs; i++)
			{
				RandomizeForAddSubDivQuiz(x, y, Div);
				cout << "What does " << x << " / " << y << " equal" << endl;
				cin >> QuizAnswer;
				if (QuizAnswer == x / y)
				{
					correctAnswer++;
				}
			}
			cout << "Out of " << numOfQs << " questions, you got " << correctAnswer << " correct." << endl;
			correctAnswer = 0;
		} while (TryAgain());

	}

	else
	{
		do
		{
			RandomizeForNormalProb(x, y);
			do
			{
				while (x % y != 0)
					x++;
				do
				{
					n = RandomizeAnswerPosition(x, y, Div);
					j = AnswerPrompt();
					if (j == n)
					{
						cout << "Correct! \n";
						Tries[problemNumber]++;
						Correct[problemNumber]++;
					}
					else
					{
						cout << "Wrong \n";
						Tries[problemNumber]++;
					}
				} while (j != n);

			} while (TryAgain());
			problemNumber++;
		} while (TryNewProblem());

		ProgramStats();
	}
}

int main()
{
	char ans = ' ';
	const int numberOfQuestions = 5;
	int QuizAns = 0, correctAnswers = 0;
	welcome();
	


	switch (MainMenu())
	{
	case 'a':
	{
		Addition(numberOfQuestions, QuizAns, correctAnswers);
		break;
	}
	case 'b':
	{
		Subtraction(numberOfQuestions, QuizAns, correctAnswers);
		break;
	}
	case 'c':
	{
		Multiplication(numberOfQuestions, QuizAns, correctAnswers);
		break;
	}
	case 'd':
	{
		Division(numberOfQuestions, QuizAns, correctAnswers);
		break;
	}
	default:
	{
		cout << "Invalid response \n";
		break;
	}
	}

}