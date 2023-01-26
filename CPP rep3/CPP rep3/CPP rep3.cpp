#include <stdio.h>
#include <stdexcept>

class Fraction
{
private:
	float numenator, denumenator;

public:
	Fraction() = default;
	Fraction(float numenator, float denumenator) {
		if (denumenator == 0) {
			throw std::runtime_error("Invalid denumenator: 0");
		}
		this->numenator = numenator;
		this->denumenator = denumenator;
	}

	float value() const{
		return numenator / denumenator;
	}

	void print() const{
		printf("%f/%f\n", numenator, denumenator);
	}

	friend Fraction operator + (const Fraction& a, const Fraction& b);
	friend Fraction operator - (const Fraction& a, const Fraction& b);
	friend Fraction operator * (const Fraction& a, const Fraction& b);
	friend Fraction operator / (const Fraction& a, const Fraction& b);
	friend bool operator == (const Fraction& a, const Fraction& b);

	Fraction operator - () {
		Fraction res = Fraction(-numenator, denumenator);
		return res;
	}
};

Fraction operator + (const Fraction& a, const Fraction& b) {
	Fraction res;
	if (a.denumenator == b.denumenator) {
		res = Fraction(a.numenator + b.numenator, a.denumenator);
	}
	else {
		res = Fraction((a.numenator * b.denumenator) + (b.numenator * a.denumenator), a.denumenator * b.denumenator);
	}
	return res;
}

Fraction operator - (const Fraction& a, const Fraction& b) {
	Fraction res;
	if (a.denumenator == b.denumenator) {
		res = Fraction(a.numenator - b.numenator, a.denumenator);
	}
	else {
		res = Fraction((a.numenator * b.denumenator) - (b.numenator * a.denumenator), a.denumenator * b.denumenator);
	}
	return res;
}

Fraction operator * (const Fraction& a, const Fraction& b) {
	Fraction res = Fraction(a.numenator * b.numenator, a.denumenator * b.denumenator);
	return res;
}

Fraction operator / (const Fraction& a, const Fraction& b) {
	Fraction res = Fraction(a.numenator * b.denumenator, a.denumenator * b.numenator);
	return res;
}

bool operator == (const Fraction& a, const Fraction& b) {
	return a.value() == b.value();
}

bool operator != (const Fraction& a, const Fraction& b) {
	return !operator ==(a, b);
}

bool operator > (const Fraction& a, const Fraction& b) {
	return a.value() > b.value();
}

bool operator < (const Fraction& a, const Fraction& b) {
	return a.value() < b.value();
}

bool operator >= (const Fraction& a, const Fraction& b) {
	return a.value() >= b.value();
}

bool operator <= (const Fraction& a, const Fraction& b) {
	return a.value() <= b.value();
}

int main()
{
	Fraction a = Fraction(3, 2) + Fraction(5, 2);
	printf("a = ");
	a.print();

	Fraction b = Fraction(3, 2) - Fraction(5, 2);
	printf("b = ");
	b.print();

	Fraction c = Fraction(3, 2) * Fraction(5, 2);
	printf("c = ");
	c.print();

	Fraction d = Fraction(3, 2) / Fraction(5, 2);
	printf("d = ");
	d.print();

	printf("Fraction(4, 5) == Fraction(20, 25)\n");
	if (Fraction(4, 5) == Fraction(20, 25)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	printf("Fraction(4, 5) != Fraction(20, 25)\n");
	if (Fraction(4, 5) != Fraction(20, 25)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	printf("Fraction(4, 5) > Fraction(15, 25)\n");
	if (Fraction(4, 5) > Fraction(15, 25)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	printf("Fraction(4, 5) <= Fraction(20, 25)\n");
	if (Fraction(4, 5) <= Fraction(20, 25)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	return 0;
}

