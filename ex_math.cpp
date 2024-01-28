#include <iostream>

/*
	‘ункции сравнени€ чисел с плавающей точкой.
	¬озникают из-за погрешностей хранени€ вышеуказанных чисел,
	поэтому вводитс€ точность до 12 знаков после точки.
*/

/*
	‘ункци€ is_eq, провер€юща€, равны ли два числа.
*/

bool is_eq(double const& x, double const& y) {
	double eps = 1e-12;
	return (fabs(x - y) < eps);
}

/*
	‘ункиц€ is_lt, провер€юща€, меньше ли первое число второго.
*/

bool is_lt(double const& x, double const& y) {
	double eps = 1e-12;
	if (fabs(x - y) < eps) return false;
	return (x < y);
}

/*
	‘ункци€ is_gt, провер€юща€, больше ли первое число второго.
*/

bool is_gt(double const& x, double const& y) {
	double eps = 1e-12;
	if (fabs(x - y) < eps) return false;
	return (x > y);
}

/*
	‘ункиц€ vec_prod, возвращающа€ смешанное векторное и псевдоскал€рное произведени€ двух векторов, заданных по трем точкам.
	¬екторы передаютс€ по координатам точек начала и конца.
*/

double vec_prod(double const& ax, double const& ay, double const& bx, double const& by, double const& cx, double const& cy) {
	return ((bx - ax) * (cy - by)) - ((cx - bx) * (by - ay));
}