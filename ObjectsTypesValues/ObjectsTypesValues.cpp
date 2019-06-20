#include "std_lib_facilities.h"
#include<limits>

//This functions prompt the user to enter two integer values and thereafter, 
//determine the smallest, sum, difference, product, and ratio of these values and 
//report them to the user

template<class T>
T& smallest(T& val1, T& val2)
//determine the smallest value between val1 and val2
{
	if (val1 > val2)return val2;
	return val1;
}

template<class T>
T& largest(T& val1, T& val2)
//determine the largest value between val1 and val2
{
	if (val1 > val2)return val1;
	return val2;
}

template<class T>
T sum(T& val1, T& val2)
//determine the sum of value between val1 and val2
{
	return (val1 + val2);
}

template<class T>
T difference(T& val1, T& val2)
//determine the difference of value between val1 and val2
{
	return abs(val1 - val2);
}

template<class T>
T product(T& val1, T& val2)
//determine the product of value between val1 and val2
{
	return (val1 * val2);
}

template<class T>
T divide(T& val1, T& val2)
//determine the product of value between val1 and val2
{
	if (val2 == 0)error("Error: denominator is equal to zero(0) ");
	return (val1 / val2);
}
//This class take an operation followed by two operands and output the result
class operation {

public:
	operation():oper(char()), val1(0),val2(0),check(22){}
	operation(const operation &op): oper(op.oper),val1(op.val1),val2(op.val2),check(22) {}
	//void operator=(operation& op) {
	//	oper = op.oper;
	//	val1 = op.val1;
	//	val2 = 0;
	//}
	~operation(){}
	const double check;

	//nonmodifiable operation
	char operator_type() const { return oper; }
	const double first_val()const { return val1; }
	 double second_val()const { return val2; }

	//modifiable operation
	void add_operator(const char& str) { oper = str; }
	void add_first_val(const double& d) { val1 = d; }
	void add_second_val(const double& d) { val2 = d; }
	void print();
private:
	char oper;
	double val1, val2;
};

void operation::print() {
	switch (oper)
	{
	case '+':
		cout << sum(val1,val2) << endl;
		break;
	case '-':
		cout << difference(val1,val2) << endl;
		break;
	case '*':
		cout << product(val1,val2) << endl;
		break;
	case '/':
		cout << divide(val1, val2) << endl;
		break;
	default:
		break;
	}
}
istream& operator>>(istream& ist, operation& op) {
	char ch;
	double val1, val2;
	ist >> ch >> val1 >> val2;

	//check for error in reading from the stream
	if (!ist) {
		ist.clear(ist.failbit);
		return ist;
	}

	op.add_first_val(val1);
	op.add_second_val(val2);
	op.add_operator(ch);
	return ist;
	
}

//   const int& check() {
//	int val = 2;
//	return val;
//
//}

int main(int argc, char* argv[]) {

	try {

		cout << "Please enter two integer/double precision values" <<
			" or type any character to terminate\n";

		double val1, val2;
		while (cin >> val1 >> val2)
		{
			cout << "The smallest value: " << smallest(val1, val2) << endl;
			cout << "The largest value: " << largest(val1, val2) << endl;
			cout << "The sum of their value: " << sum(val1, val2) << endl;
			cout << "The difference of their value: " << difference(val1, val2) << endl;
			cout << "The product of their value: " << product(val1, val2) << endl;
		}

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "Please enter operator followed by two operand in the format: \"operator oper1 oper2\"\n";

		operation opr;
		while (cin >> opr) {
			opr.print();
		}


		 operation op2 = opr;
		//  const int& t1 = check();
		//cout << t1 << endl;
		op2.print();
	}
	
	

	catch (exception& e) {
		cerr << e.what() << endl;
	}
	keep_window_open();
	return 0;
}