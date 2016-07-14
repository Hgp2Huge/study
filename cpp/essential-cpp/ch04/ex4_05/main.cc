/*
 *Exercise 4.5
 *Implement a 4x4 Matrix class supporting at least the following general interface: addition and
 *multiplication of two Matrix objects, a print() member function, a compound += operator, and
 *subscripting supported through a pair of overloaded function call operators, as follows:
 *float& operator()(int row, int column);
 *float operator()(int row, int column) const;
 *Provide a default constructor taking an optional 16 data values and a constructor taking an array of
 *16 elements. You do not need a copy constructor, copy assignment operator, or destructor for this
 *class (these are required in Chapter 6 when we reimplement the Matrix class to support arbitrary
 *rows and columns).
 */

#include "matrix.h"

#include <iostream>
using std::cout; using std::cin;
using std::endl;

int main()
{
	Matrix m;
	cout << "defalut \n" << m << endl;

	elemType arr16[16] = {
		1., 0., 0., 0., 0., 1., 0., 0.,
		0., 0., 1., 0., 0., 0., 0., 1. };

	Matrix m_from_arr16(arr16);
	cout << "m_from_arr16 = \n" << m_from_arr16 << endl;

	m = m_from_arr16;
	cout << "m = \n" << m << endl;

	Matrix m2(m);
	cout << "m2 = \n" << m2 << endl;

	elemType arr2[16] = {
		1.3, 0.4, 2.6, 8.2, 6.2, 1.7, 1.3, 8.3,
		4.2, 7.4, 2.7, 1.9, 6.3, 8.1, 5.6, 6.6};

	Matrix m3(arr2);
	cout << "m3 = \n" << m3 << endl;

	Matrix m4 = m3 * m2;
	cout << "after m4 = m3 * m2, m4 = \n" << m4 << endl;

	Matrix m5 = m3 + m4;
	cout << "after m5 = m3 + m4, m5 = \n" << m5 << endl;

	m3 += m4;
	cout <<  "after m3 += m4, m3 = \n" << m3 << endl;

	return 0;
}
