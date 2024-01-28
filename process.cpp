#include <fstream>
#include "ex_math.h"

/*
	Функция is_heart, проверяющая, может ли очередная четверка точек образовать сердце.
	Ключевые условия образования сердца:
	1. Каждая точка является явно выраженной вершиной: верх, низ, левый и правый края
	2. Следствие из 1: вершины не могут накладываться друг на друга (по соглашению одинаковые точки отбрасываются на этапе заполнения массива точек)
	3. Длины отрезков от краев до низа равны; аналогично и с отрезками до верха
	4. Низ не может быть на одной прямой с одновременно двумя краями (как по x, так и по y)
	5. Верх не может находиться внутри нижнего треугольника (иными словами, получающийся четырехугольник должен быть выпуклым)
	6. Расстояние верха до линии краевых точек не больше расстояния низа до той же линии
*/

bool is_heart(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry) {
	double leng2dl = ((dx - lx) * (dx - lx)) + ((dy - ly) * (dy - ly)), leng2dr = ((dx - rx) * (dx - rx)) + ((dy - ry) * (dy - ry)); // квадраты расстояний от точки низа до точек краев
	double leng2tl = ((tx - lx) * (tx - lx)) + ((ty - ly) * (ty - ly)), leng2tr = ((tx - rx) * (tx - rx)) + ((ty - ry) * (ty - ry)); // квадраты расстояний от точки верха до точек краев
	double cx = (lx + rx) / 2.0, cy = (ly + ry) / 2.0; // координаты серединной точки
	double leng2dc = ((dx - cx) * (dx - cx)) + ((dy - cy) * (dy - cy)), leng2tc = ((tx - cx) * (tx - cx)) + ((ty - cy) * (ty - cy)); // квадраты расстояний от точки центра линии краев
	double lined = vec_prod(dx, dy, lx, ly, rx, ry), linetc = vec_prod(tx, ty, lx, ly, rx, ry), linetl = vec_prod(tx, ty, dx, dy, lx, ly), linetr = vec_prod(tx, ty, rx, ry, dx, dy); // векторные произведения для сокращения записи условия
	// порядок проверки условий обусловен логическим исключением выходящих ситуаций
	// последнее длинное условие - проверка, что точка верха не находится внутри треугольника, образованного низом и краями
	 if ()
 /*if ((tx == dx && ty == dy) ||
		(!is_eq(leng2dl, leng2dr)) ||
		(!is_eq(leng2tl, leng2tr)) ||
		(is_eq(lined, 0.0)) ||
		(is_gt(leng2tc, leng2dc)) ||
		((!is_eq(linetc, 0.0)) && ((is_lt(linetc, 0.0) && is_lt(linetl, 0.0) && is_lt(linetr, 0.0)) || (is_gt(linetc, 0.0) && is_gt(linetl, 0.0) && is_gt(linetr, 0.0)))))      */
		return false;
	return true;
}

/*
	Функция inside_heart, проверяющая, находится ли очередная точка внутри сердца.
	Ключевые условия принадлежности сердцу:
	1. Точка лежит на одной из прямых или полуокружностей
	2. Точка попадает в область одной из окружностей и обязательно лежит между двумя прямыми
	3. Точка попадает в область нижнего треугольника (края и линия краев)
	4. Точка попадает в область верхнего треугольника (при этом соответствие окружностям не учитывается)
*/

bool inside_heart(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry, double const& x, double const& y) {
	double clx = (lx + tx) / 2.0, cly = (ly + ty) / 2.0, crx = (rx + tx) / 2.0, cry = (ry + ty) / 2.0; // координаты середины отрезков, они же центры окружностей
	double rad2l = (((tx - lx) * (tx - lx)) + ((ty - ly) * (ty - ly))) / 4.0, rad2r = (((tx - rx) * (tx - rx)) + ((ty - ry) * (ty - ry))) / 4.0; // квадраты радиусов окружностей
	double c2l = ((x - clx) * (x - clx)) + ((y - cly) * (y - cly)), c2r = ((x - crx) * (x - crx)) + ((y - cry) * (y - cry)); // уравнения окружностей для заданной точки
	double ldl = vec_prod(x, y, dx, dy, lx, ly), ldr = vec_prod(x, y, rx, ry, dx, dy), lc = vec_prod(x, y, lx, ly, rx, ry), ltl = vec_prod(x, y, tx, ty, lx, ly), ltr = vec_prod(x, y, rx, ry, tx, ty); // векторные произведения для сокращения записи условия
 if (условие_принадлежности) return true;
 return false;
	// такой каскад обусловлен удобством записи всех возможных случаев
	}

/*
	Функция log_pts, призванная записать в выходной файл полученные точки.
*/

void log_pts(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry, int const& ti, int const& li, int const& di, int const& ri, double** arr, unsigned int const& size, std::ofstream& log) {
	log << "(" << tx << "; " << ty << ")\n";
	log << "(" << lx << "; " << ly << ")\n";
	log << "(" << dx << "; " << dy << ")\n";
	log << "(" << rx << "; " << ry << ")\n";
	for (int i = 0; i < size; ++i) {
		if (i != ti && i != li && i != di && i != ri) {
			double x = arr[i][0], y = arr[i][1];
			if (inside_heart(tx, ty, lx, ly, dx, dy, rx, ry, x, y)) log << "(" << x << "; " << y << ")\n";
		}
	}
}

/*
	Функция pts_inside, подсчитывающая кол-во точек из всего набора, принадлежащих очередному сердцу.
*/

unsigned int pts_inside(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry, int const& ti, int const& li, int const& di, int const& ri, double** arr, unsigned int const& size) {
	unsigned int count = 4; // вершины тоже принадлежат сердцу
	// подсчитываем точки, которые не вершины, находятся не ниже обоих прямых и/или попадают хотя бы в одну из окружностей
	for (int i = 0; i < size; ++i) {
		if (i != ti && i != li && i != di && i != ri) {
			double x = arr[i][0], y = arr[i][1];
			if (inside_heart(tx, ty, lx, ly, dx, dy, rx, ry, x, y)) ++count;
		}
	}
	return count;
}

/*
	Функция process, в которой содержится вся обработка массива точек, поиск сердец и ответа на задачу.
*/

void process(double** arr, unsigned int const& size, std::ofstream& log, std::ofstream& out) {
	unsigned int max_points = 4, hearts = 0, pts = 0;
	log << "Построены сердца:\n";
	// сначала определяем сердца и максимальное число точек
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			for (int k = j + 1; k < size; ++k) {
				for (int m = k + 1; m < size; ++m) {
					double ax = arr[i][0], ay = arr[i][1], bx = arr[j][0], by = arr[j][1], cx = arr[k][0], cy = arr[k][1], dx = arr[m][0], dy = arr[m][1];
					if (is_heart(ax, ay, bx, by, cx, cy, dx, dy)) {
						++hearts;
						log << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << cx << "; " << cy << "); лево - (" << bx << "; " << by << "); право - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(ax, ay, bx, by, dx, dy, cx, cy)) {
						++hearts;
						log << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << dx << "; " << dy << "); лево - (" << bx << "; " << by << "); право - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(ax, ay, cx, cy, bx, by, dx, dy)) {
						++hearts;
						log << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << bx << "; " << by << "); лево - (" << cx << "; " << cy << "); право - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(bx, by, ax, ay, cx, cy, dx, dy)) {
						++hearts;
						log << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << cx << "; " << cy << "); лево - (" << ax << "; " << ay << "); право - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(bx, by, ax, ay, dx, dy, cx, cy)) {
						++hearts;
						log << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << dx << "; " << dy << "); лево - (" << ax << "; " << ay << "); право - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(bx, by, cx, cy, ax, ay, dx, dy)) {
						++hearts;
						log << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << ax << "; " << ay << "); лево - (" << cx << "; " << cy << "); право - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(cx, cy, ax, ay, bx, by, dx, dy)) {
						++hearts;
						log << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << bx << "; " << by << "); лево - (" << ax << "; " << ay << "); право - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(cx, cy, ax, ay, dx, dy, bx, by)) {
						++hearts;
						log << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << dx << "; " << dy << "); лево - (" << ax << "; " << ay << "); право - (" << bx << "; " << by << ")\n";
						pts = pts_inside(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(cx, cy, bx, by, ax, ay, dx, dy)) {
						++hearts;
						log << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << ax << "; " << ay << "); лево - (" << bx << "; " << by << "); право - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(dx, dy, ax, ay, bx, by, cx, cy)) {
						++hearts;
						log << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << bx << "; " << by << "); лево - (" << ax << "; " << ay << "); право - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(dx, dy, ax, ay, cx, cy, bx, by)) {
						++hearts;
						log << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << cx << "; " << cy << "); лево - (" << ax << "; " << ay << "); право - (" << bx << "; " << by << ")\n";
						pts = pts_inside(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(dx, dy, bx, by, ax, ay, cx, cy)) {
						++hearts;
						log << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << ax << "; " << ay << "); лево - (" << bx << "; " << by << "); право - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size);
						log << "Точек внутри: " << pts << "\nКоординаты точек:\n";
						log_pts(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
				}
			}
		}
	}
	if (!hearts) { // бывает, что сердец нет вообще
		log << "Четверок, образующих сердца, обнаружено не было.\n";
		out << "Из всех точек не было обнаружено ни одного сердца. Ответ не получен.\nПодробности в лог-файле log.txt";
	}
	else if (max_points == 4) { // бывает, что сердца есть, но все точки в них - вершины
		log << "Все определенные сердца содержат только вершины: прочих точек они не содержат.\n";
		out << "Все определенные сердца содержат только вершины: прочих точек они не содержат. Ответ не получен.\n Подробности в лог-файле log.txt";
	}
	else {
		log << "Определено максимальное число точек, которое могут содержать обнаруженные сердца: " << max_points << ".\nСписок таких сердец:\n";
		out << "Определено максимальное число точек, которое могут содержать обнаруженные сердца: " << max_points << ".\nСписок таких сердец:\n";
		hearts = 0;
		// а вот теперь выводим сердца
		for (int i = 0; i < size; ++i) {
			for (int j = i + i; j < size; ++j) {
				for (int k = j + 1; k < size; ++k) {
					for (int m = k + 1; m < size; ++m) {
						double ax = arr[i][0], ay = arr[i][1], bx = arr[j][0], by = arr[j][1], cx = arr[k][0], cy = arr[k][1], dx = arr[m][0], dy = arr[m][1];
						if (is_heart(ax, ay, bx, by, cx, cy, dx, dy) && pts_inside(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << cx << "; " << cy << "); лево - (" << bx << "; " << by << "); право - (" << dx << "; " << dy << ")\n";
							log << "Координаты точек:\n";
							log_pts(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size, log);
							out << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << cx << "; " << cy << "); лево - (" << bx << "; " << by << "); право - (" << dx << "; " << dy << ")\n";
							out << "Координаты точек:\n";
							log_pts(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size, out);
						}
						if (is_heart(ax, ay, bx, by, dx, dy, cx, cy) && pts_inside(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << dx << "; " << dy << "); лево - (" << bx << "; " << by << "); право - (" << cx << "; " << cy << ")\n";
							log << "Координаты точек:\n";
							log_pts(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size, log);
							out << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << dx << "; " << dy << "); лево - (" << bx << "; " << by << "); право - (" << cx << "; " << cy << ")\n";
							out << "Координаты точек:\n";
							log_pts(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size, out);
						}
						if (is_heart(ax, ay, cx, cy, bx, by, dx, dy) && pts_inside(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << bx << "; " << by << "); лево - (" << cx << "; " << cy << "); право - (" << dx << "; " << dy << ")\n";
							log << "Координаты точек:\n";
							log_pts(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size, log);
							out << hearts << ") верх - (" << ax << "; " << ay << "); низ - (" << bx << "; " << by << "); лево - (" << cx << "; " << cy << "); право - (" << dx << "; " << dy << ")\n";
							out << "Координаты точек:\n";
							log_pts(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size, out);
						}
						if (is_heart(bx, by, ax, ay, cx, cy, dx, dy) && pts_inside(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << cx << "; " << cy << "); лево - (" << ax << "; " << ay << "); право - (" << dx << "; " << dy << ")\n";
							log << "Координаты точек:\n";
							log_pts(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size, log);
							out << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << cx << "; " << cy << "); лево - (" << ax << "; " << ay << "); право - (" << dx << "; " << dy << ")\n";
							out << "Координаты точек:\n";
							log_pts(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size, out);
						}
						if (is_heart(bx, by, ax, ay, dx, dy, cx, cy) && pts_inside(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << dx << "; " << dy << "); лево - (" << ax << "; " << ay << "); право - (" << cx << "; " << cy << ")\n";
							log << "Координаты точек:\n";
							log_pts(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size, log);
							out << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << dx << "; " << dy << "); лево - (" << ax << "; " << ay << "); право - (" << cx << "; " << cy << ")\n";
							out << "Координаты точек:\n";
							log_pts(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size, out);
						}
						if (is_heart(bx, by, cx, cy, ax, ay, dx, dy) && pts_inside(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << ax << "; " << ay << "); лево - (" << cx << "; " << cy << "); право - (" << dx << "; " << dy << ")\n";
							log << "Координаты точек:\n";
							log_pts(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size, log);
							out << hearts << ") верх - (" << bx << "; " << by << "); низ - (" << ax << "; " << ay << "); лево - (" << cx << "; " << cy << "); право - (" << dx << "; " << dy << ")\n";
							out << "Координаты точек:\n";
							log_pts(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size, out);
						}
						if (is_heart(cx, cy, ax, ay, bx, by, dx, dy) && pts_inside(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << bx << "; " << by << "); лево - (" << ax << "; " << ay << "); право - (" << dx << "; " << dy << ")\n";
							log << "Координаты точек:\n";
							log_pts(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size, log);
							out << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << bx << "; " << by << "); лево - (" << ax << "; " << ay << "); право - (" << dx << "; " << dy << ")\n";							
							out << "Координаты точек:\n";
							log_pts(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size, out);
						}
						if (is_heart(cx, cy, ax, ay, dx, dy, bx, by) && pts_inside(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << dx << "; " << dy << "); лево - (" << ax << "; " << ay << "); право - (" << bx << "; " << by << ")\n";
							log << "Координаты точек:\n";
							log_pts(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size, log);
							out << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << dx << "; " << dy << "); лево - (" << ax << "; " << ay << "); право - (" << bx << "; " << by << ")\n";
							out << "Координаты точек:\n";
							log_pts(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size, out);
						}
						if (is_heart(cx, cy, bx, by, ax, ay, dx, dy) && pts_inside(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << ax << "; " << ay << "); лево - (" << bx << "; " << by << "); право - (" << dx << "; " << dy << ")\n";
							log << "Координаты точек:\n";
							log_pts(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size, log);
							out << hearts << ") верх - (" << cx << "; " << cy << "); низ - (" << ax << "; " << ay << "); лево - (" << bx << "; " << by << "); право - (" << dx << "; " << dy << ")\n";
							out << "Координаты точек:\n";
							log_pts(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size, out);
						}
						if (is_heart(dx, dy, ax, ay, bx, by, cx, cy) && pts_inside(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << bx << "; " << by << "); лево - (" << ax << "; " << ay << "); право - (" << cx << "; " << cy << ")\n";
							log << "Координаты точек:\n";
							log_pts(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size, log);
							out << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << bx << "; " << by << "); лево - (" << ax << "; " << ay << "); право - (" << cx << "; " << cy << ")\n";
							out << "Координаты точек:\n";
							log_pts(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size, out);
						}
						if (is_heart(dx, dy, ax, ay, cx, cy, bx, by) && pts_inside(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << cx << "; " << cy << "); лево - (" << ax << "; " << ay << "); право - (" << bx << "; " << by << ")\n";
							log << "Координаты точек:\n";
							log_pts(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size, log);
							out << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << cx << "; " << cy << "); лево - (" << ax << "; " << ay << "); право - (" << bx << "; " << by << ")\n";
							out << "Координаты точек:\n";
							log_pts(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size, out);
						}
						if (is_heart(dx, dy, bx, by, ax, ay, cx, cy) && pts_inside(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << ax << "; " << ay << "); лево - (" << bx << "; " << by << "); право - (" << cx << "; " << cy << ")\n";
							log << "Координаты точек:\n";
							log_pts(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size, log);
							out << hearts << ") верх - (" << dx << "; " << dy << "); низ - (" << ax << "; " << ay << "); лево - (" << bx << "; " << by << "); право - (" << cx << "; " << cy << ")\n";		
							out << "Координаты точек:\n";
							log_pts(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size, out);
						}
					}
				}
			}
		}
	}
}

/*
	Функция clear_arr, призванная очищать входной двумерный массив и освобождать выделенную под него память.
*/

void clear_arr(double** arr, unsigned int const& size) {
	for (int i = 0; i < size; ++i) {
 i = delete[] arr[i];
	}
 i = delete[] arr;
	arr = NULL;
}