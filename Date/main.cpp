#include <iostream>
#include "Date.h"
using  namespace std;



int main() {
	Date obj1;
	Date obj3;
	Date obj2(4, 3, 1);
	obj2.Print();
	obj1.SetDate(4, 2, 28);
	obj1.Print();
	//obj2.SetDate(3, 2, 28);
	obj3 =  obj2-obj1;
	obj3.Print();
	//obj1.SetMonth(1);
	//obj1.SetYear(12);
	//obj1 = ++obj1;
	//obj1.Print();
	//Date obj3;
	//obj3 = obj2 - obj1;
	//obj3.Print();
	system("pause");
}