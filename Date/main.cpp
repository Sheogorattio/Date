#include <iostream>
#include "Date.h"
using  namespace std;

int main() {
	Date obj1;
	Date obj2(4, 3, 1);
	obj1.SetDate(3, 2, 28);
	Date obj3;
	obj3 = obj2 - obj1;
	obj3.Print();
	system("pause");
}