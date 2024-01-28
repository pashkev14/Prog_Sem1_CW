#include <iostream>

/*
	������� ��������� ����� � ��������� ������.
	��������� ��-�� ������������ �������� ������������� �����,
	������� �������� �������� �� 12 ������ ����� �����.
*/

/*
	������� is_eq, �����������, ����� �� ��� �����.
*/

bool is_eq(double const& x, double const& y) {
	double eps = 1e-12;
	return (fabs(x - y) < eps);
}

/*
	������� is_lt, �����������, ������ �� ������ ����� �������.
*/

bool is_lt(double const& x, double const& y) {
	double eps = 1e-12;
	if (fabs(x - y) < eps) return false;
	return (x < y);
}

/*
	������� is_gt, �����������, ������ �� ������ ����� �������.
*/

bool is_gt(double const& x, double const& y) {
	double eps = 1e-12;
	if (fabs(x - y) < eps) return false;
	return (x > y);
}

/*
	������� vec_prod, ������������ ��������� ��������� � ��������������� ������������ ���� ��������, �������� �� ���� ������.
	������� ���������� �� ����������� ����� ������ � �����.
*/

double vec_prod(double const& ax, double const& ay, double const& bx, double const& by, double const& cx, double const& cy) {
	return ((bx - ax) * (cy - by)) - ((cx - bx) * (by - ay));
}