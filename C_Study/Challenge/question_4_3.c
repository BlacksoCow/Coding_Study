#include <stdio.h>
typedef struct
{
	double real, imaginary;
} Complex;
void Add(Complex* num1, Complex* num2)
{
	double Real = num1->real + num2->real;
	double Imagine = num1->imaginary + num2->imaginary;
	printf("Add result] Real: %lf, Imaginary: %lf", Real, Imagine);
	putchar('\n');
	return;
}
void Multiply(Complex* num1, Complex* num2)
{
	double Real = (num1->real * num2->real)
			   - (num1->imaginary * num2->imaginary);
	double Imagine = (num1->imaginary * num2->real)
			   + (num1->real * num2->imaginary);
	printf("Mul result] Real: %lf, Imaginary: %lf", Real, Imagine);
	putchar('\n');
}
int main(int argc, char** argv)
{
	Complex num[2];
	for(int i = 0; i < 2; i++)
	{
		printf("Input complex %d[real, imaginary]: ", i + 1);
		scanf("%lf%lf", &(num[i].real), &(num[i].imaginary));
		getchar();
	}
	Add(&num[0], &num[1]);
	Multiply(num, num + 1);
	return 0;
}