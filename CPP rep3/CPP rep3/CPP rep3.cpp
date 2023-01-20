#include <stdio.h>
#include <stdexcept>
using namespace std;

class InvalidInstruction : public runtime_error
{
public:
	InvalidInstruction() : runtime_error("Invalid instruction was passed") {}
};

void calc(char str[])
{	
	try
	{
		int a, b;
		char operation;
		float res;
		sscanf_s(str, "%i%c%i", &a, &operation, (unsigned) sizeof(char), &b);
		switch (operation)
		{
		case '+':
			res = a + b;
			break;
		case '-':
			res = a - b;
			break;
		case '*':
			res = a * b;
			break;
		case '/':
			res = (float) a / (float) b;
			break;
		default:
			throw InvalidInstruction();
		}
		printf("%i %c %i = %f", a, operation, b, res);
	}
	catch (const runtime_error& ex) {
		throw InvalidInstruction();
	}
}

int main()
{
	try
	{
		char str[100];
		scanf_s("%s", str, 100);
		calc(str);
	}
	catch (const InvalidInstruction& ex)
	{
		printf("Calculation failed for reason: %s", ex.what());
	}
	return 0;
}

