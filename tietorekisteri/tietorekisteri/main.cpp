#include <iostream>
#include "Sovellus.h"
using std::cout; using std::endl;


int main() {


	try {
		Sovellus amk("Tamk");
		amk.aja();
	}
	catch (std::out_of_range& ex) {
		cout << "virheellinen indeksointi: " << ex.what() << endl;
	}
	catch (std::exception& ex) {
		cout << "virhe: " << ex.what() << endl;
	}
	catch (...) {
		cout << "Virhe tapahtunut" << endl;
	}
	system("pause");
	return 0;
}
