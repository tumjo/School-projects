#include "stack.h"

void introduction();
void instructions();
bool do_command(char, Stack &);
char get_command();

int main()
/*
Post: The program has executed simple arithmetic
	  commands entered by the user.
Uses: The class Stack and the functions
	  introduction, instructions, do_command, and get_command.
*/
{
	Stack stored_numbers;
	introduction();
	instructions();
	while (do_command(get_command(), stored_numbers));
	system("pause");
	return 0;
}

void introduction() {
	cout << "----PostFix-calculator----" << endl;
}

void instructions()
/*
Post: A help screen for the program is printed, giving the meaning of each
	  command that the user may enter.
*/

{
	cout << endl
		<< "This program allows the user to calculate simple arithmetic calculations" << endl

		<< "The valid commands are:" << endl
		<< "? - Push a real number to stack" << endl
		<< "= - Show the top number of the stack" << endl
		<< "x - Change the order of the numbers. (The top two of the stack)" << endl
		<< "+ - Addition" << endl
		<< "- - Subtraction" << endl
		<< "* - Multiplication" << endl
		<< "/ - Division" << endl
		<< "s - The sum of all numbers" << endl
		<< "a - The average of all numbers" << endl
		<< "r - Reset the calculator" << endl
		//<< "H - This help screen" << endl
		<< "Q - Quit" << endl

		<< "Press <Enter> to continue." << flush;

	char c;
	do {
		cin.get(c);
	} while (c != '\n');
}

bool do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
	  has been applied to the Stack of numbers given by the second parameter.
	  A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
	double p, q;
	switch (command) {
	case '?':
		cout << "Enter a real number: " << flush;
		cin >> p;
		if (numbers.push(p) == overflow)
			cout << "Warning: Stack full, lost number" << endl;
		break;

	case '=':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else
			cout << p << endl;
		break;

	case '+':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}

			else {
				numbers.pop();
				if (numbers.push(q + p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case '-':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}

			else {
				numbers.pop();
				if (numbers.push(q - p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case '*':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}

			else {
				numbers.pop();
				if (numbers.push(q * p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case '/':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}

			else {
				numbers.pop();
				if (p != 0) {
					if (numbers.push(q / p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
				else {
					cout << "Warning: Division by zero is undefined. No calculations have been made." << endl;
					if (numbers.push(q) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
					if (numbers.push(p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			}
		}
		break;

	case 'x':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}

			else {
				numbers.pop();
				if (numbers.push(p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
				if (numbers.push(q) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case 's':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			while (!numbers.empty()) {
				numbers.top(q);
				numbers.pop();
				p += q;
			}
			if (numbers.push(p) == overflow)
				cout << "Warning: Stack full, lost result" << endl;
		}
		break;

	case 'a':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			int divisor = numbers.size();
			numbers.pop();
			while (!numbers.empty()) {
				numbers.top(q);
				numbers.pop();
				p += q;
			}
			if (numbers.push(p / divisor) == overflow)
				cout << "Warning: Stack full, lost result" << endl;
		}
		break;

	case 'r':
		numbers.clear();
		cout << "The calculator has been reset" << endl;
		break;

		//   Add options for further user commands.

	case 'q':
		cout << "Calculation finished.\n";
		return false;
	}
	return true;
}

char get_command()
{
	char command;
	bool waiting = true;
	cout << "Select command and press <Enter>:";

	while (waiting) {
		cin >> command;
		command = tolower(command);
		if (command == '?' || command == '=' || command == '+' ||
			command == '-' || command == '*' || command == '/' ||
			command == 'q' || command == 'x' || command == 's' ||
			command == 'a' || command == 'r') waiting = false;


		else {
			cout << "Please enter a valid command:" << endl
				<< "[?]push to stack	[=]print top	[x]change the order of the numbers " << endl
				<< "[+] [-] [*] [/]   are arithmetic operations." << endl
				<< "[s]the sum of all numbers	[a]the average of all numbers" << endl
				<< "[Q]uit." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	return command;
}
