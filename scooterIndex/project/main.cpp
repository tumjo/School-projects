#include <iostream>
#include "AppRun.h"

using std::cout; using std::endl;

int main() {

	try {
		AppRun app{"Scooter"};
		app.run();
	}
	catch (std::out_of_range& ex) {
		cout << "out-of-range error: " << ex.what() << endl;
	}
	catch (std::exception& ex) {
		cout << "exception: " << ex.what() << endl;
	}
	catch (...) {
		cout << "Error" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;

	// LOPPUUU
}


