// ************************************************** Project 2 ***************************************
// ************************************************* Math Quiz ************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


enum enLevel  { Easy = 1 , Med = 2 , Hard = 3 , MixLvl = 4 };
enum enOpType { Add = 1 , Sub = 2 , Mul = 3 , Div = 4 , MixOp = 5 };


int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;

}


short funcReadHowManyQuestions() {

	short howManyQuestions = 0;
	cout << "Enter How Many Questions Do You Want To Play?? : ";
	cin >> howManyQuestions;
	return howManyQuestions;
}

enLevel funcQuestionsLevel() {
	short questionsLvl = 0;
	cout << "\nEnter Questions Level? [1]:Easy , [2]:Med , [3]:Hard , [4]:Mix : ";
	cin >> questionsLvl;
	return enLevel(questionsLvl);
}


enOpType funcOpType() {

	short opType = 0;

	cout << "\nEnter Operation Type? [1]:Add , [2]:Sub , [3]:Mul , [4]:Div , [5]:Mix : ";
	cin >> opType;
	return enOpType(opType);
}


short funcSelectLevel(enLevel choiceLevel) {

	switch (choiceLevel) {

	case enLevel::Easy:
		return RandomNumber(1, 10);
	case enLevel::Med:
		return RandomNumber(10, 50);
	case enLevel::Hard:
		return RandomNumber(50, 100);
	case enLevel::MixLvl:
		return RandomNumber(1, 100);

	}

}


char funcSelectOerationType(enOpType opType) {

	switch (opType) {

	case enOpType::Add:
		return '+';
	case enOpType::Sub:
		return '-';
	case enOpType::Mul:
		return '*';
	case enOpType::Div:
		return '/';
	case enOpType::MixOp:
		char ops[] = { '+', '-', '*', '/' };
		return (ops[RandomNumber(0, 3)]);
	}
}


void funcStringQuestionsLevel(enLevel level) {

	switch (level) {

	case enLevel::Easy   : cout << "Easy";        break;
	case enLevel::Med    : cout << "Med";         break;
	case enLevel::Hard   : cout << "Hard";        break;
	case enLevel::MixLvl : cout << "Mix Level";   break;
	}
}


void funcCharOpType(enOpType opType) {

	switch (opType) {

	case enOpType::Add   : cout << "+";                  break;
	case enOpType::Sub   : cout << "-";                  break;
	case enOpType::Mul   : cout << "*";                  break;
	case enOpType::Div   : cout << "/";                  break;
	case enOpType::MixOp : cout << "Mix Operation Type"; break;
	}
}



void funcStartGame(short howManyRounds) {

	enLevel questionLevel = funcQuestionsLevel();
	enOpType opType = funcOpType();

	int answer;
	int correct = 0;
	short rightAnswersCounter = 0;
	short wrongAnswersCounter = 0;

	for (short i = 0; i < howManyRounds; i++) {

		cout << "\n\nQuestion [" << i + 1 << "/" << howManyRounds << "]\n\n";

		int number1 = funcSelectLevel(questionLevel);
		int number2 = funcSelectLevel(questionLevel);
		char op = funcSelectOerationType(opType);

		cout << number1 << endl;
		cout << number2 << "   " << op << endl;
		cout << "-----------\n";
		cin >> answer;

		switch (op) {

		case '+': correct = number1 + number2; break;
		case '-': correct = number1 - number2; break;
		case '*': correct = number1 * number2; break;
		case '/': correct = number1 / number2; break;

		}

		if (answer == correct) {
			system("color 2F");
			cout << "\nCorrect Answer :-)";
			rightAnswersCounter++;
		}

		else {
			system("color 4F");
			cout << "\a";
			cout << "\nWrong Answer :-(";
			cout << "\nThe Right Answer is : " << correct;
			wrongAnswersCounter++;
		}

	}

	cout << "\n\n\n-----------------------------------\n";

	if (rightAnswersCounter > wrongAnswersCounter) {
		cout << "Final Results is PASS :-)\n";
	}
	else {
		cout << "Final Results is FAIL :-(\n";
	}
	cout << "-----------------------------------\n";


	cout << "\nNumber Of Questions     : " << howManyRounds << endl;
	cout << "Questions Level         : ";
	funcStringQuestionsLevel(questionLevel);
	cout << "\nOperation Type          : ";
	funcCharOpType(opType);
	cout << "\nNumber Of Right Answers : " << rightAnswersCounter << endl;
	cout << "Number Of Wrong Answers : " << wrongAnswersCounter;
}




int main() {

	srand((unsigned)time(NULL));

	char playAgain = 'y';
	do {

		funcStartGame(funcReadHowManyQuestions());

		cout << "\n\nDo You Want To Play Again?? [Y,N] : ";
		cin >> playAgain;

		if (playAgain == 'y' || playAgain == 'Y') {
			system("cls");
			system("color 0F");
		}

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "\n\n\n";
}