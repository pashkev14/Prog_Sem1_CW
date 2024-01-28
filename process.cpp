#include <fstream>
#include "ex_math.h"

/*
	������� is_heart, �����������, ����� �� ��������� �������� ����� ���������� ������.
	�������� ������� ����������� ������:
	1. ������ ����� �������� ���� ���������� ��������: ����, ���, ����� � ������ ����
	2. ��������� �� 1: ������� �� ����� ������������� ���� �� ����� (�� ���������� ���������� ����� ������������� �� ����� ���������� ������� �����)
	3. ����� �������� �� ����� �� ���� �����; ���������� � � ��������� �� �����
	4. ��� �� ����� ���� �� ����� ������ � ������������ ����� ������ (��� �� x, ��� � �� y)
	5. ���� �� ����� ���������� ������ ������� ������������ (����� �������, ������������ ��������������� ������ ���� ��������)
	6. ���������� ����� �� ����� ������� ����� �� ������ ���������� ���� �� ��� �� �����
*/

bool is_heart(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry) {
	double leng2dl = ((dx - lx) * (dx - lx)) + ((dy - ly) * (dy - ly)), leng2dr = ((dx - rx) * (dx - rx)) + ((dy - ry) * (dy - ry)); // �������� ���������� �� ����� ���� �� ����� �����
	double leng2tl = ((tx - lx) * (tx - lx)) + ((ty - ly) * (ty - ly)), leng2tr = ((tx - rx) * (tx - rx)) + ((ty - ry) * (ty - ry)); // �������� ���������� �� ����� ����� �� ����� �����
	double cx = (lx + rx) / 2.0, cy = (ly + ry) / 2.0; // ���������� ���������� �����
	double leng2dc = ((dx - cx) * (dx - cx)) + ((dy - cy) * (dy - cy)), leng2tc = ((tx - cx) * (tx - cx)) + ((ty - cy) * (ty - cy)); // �������� ���������� �� ����� ������ ����� �����
	double lined = vec_prod(dx, dy, lx, ly, rx, ry), linetc = vec_prod(tx, ty, lx, ly, rx, ry), linetl = vec_prod(tx, ty, dx, dy, lx, ly), linetr = vec_prod(tx, ty, rx, ry, dx, dy); // ��������� ������������ ��� ���������� ������ �������
	// ������� �������� ������� ��������� ���������� ����������� ��������� ��������
	// ��������� ������� ������� - ��������, ��� ����� ����� �� ��������� ������ ������������, ������������� ����� � ������
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
	������� inside_heart, �����������, ��������� �� ��������� ����� ������ ������.
	�������� ������� �������������� ������:
	1. ����� ����� �� ����� �� ������ ��� ���������������
	2. ����� �������� � ������� ����� �� ����������� � ����������� ����� ����� ����� �������
	3. ����� �������� � ������� ������� ������������ (���� � ����� �����)
	4. ����� �������� � ������� �������� ������������ (��� ���� ������������ ����������� �� �����������)
*/

bool inside_heart(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry, double const& x, double const& y) {
	double clx = (lx + tx) / 2.0, cly = (ly + ty) / 2.0, crx = (rx + tx) / 2.0, cry = (ry + ty) / 2.0; // ���������� �������� ��������, ��� �� ������ �����������
	double rad2l = (((tx - lx) * (tx - lx)) + ((ty - ly) * (ty - ly))) / 4.0, rad2r = (((tx - rx) * (tx - rx)) + ((ty - ry) * (ty - ry))) / 4.0; // �������� �������� �����������
	double c2l = ((x - clx) * (x - clx)) + ((y - cly) * (y - cly)), c2r = ((x - crx) * (x - crx)) + ((y - cry) * (y - cry)); // ��������� ����������� ��� �������� �����
	double ldl = vec_prod(x, y, dx, dy, lx, ly), ldr = vec_prod(x, y, rx, ry, dx, dy), lc = vec_prod(x, y, lx, ly, rx, ry), ltl = vec_prod(x, y, tx, ty, lx, ly), ltr = vec_prod(x, y, rx, ry, tx, ty); // ��������� ������������ ��� ���������� ������ �������
 if (�������_��������������) return true;
 return false;
	// ����� ������ ���������� ��������� ������ ���� ��������� �������
	}

/*
	������� log_pts, ���������� �������� � �������� ���� ���������� �����.
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
	������� pts_inside, �������������� ���-�� ����� �� ����� ������, ������������� ���������� ������.
*/

unsigned int pts_inside(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry, int const& ti, int const& li, int const& di, int const& ri, double** arr, unsigned int const& size) {
	unsigned int count = 4; // ������� ���� ����������� ������
	// ������������ �����, ������� �� �������, ��������� �� ���� ����� ������ �/��� �������� ���� �� � ���� �� �����������
	for (int i = 0; i < size; ++i) {
		if (i != ti && i != li && i != di && i != ri) {
			double x = arr[i][0], y = arr[i][1];
			if (inside_heart(tx, ty, lx, ly, dx, dy, rx, ry, x, y)) ++count;
		}
	}
	return count;
}

/*
	������� process, � ������� ���������� ��� ��������� ������� �����, ����� ������ � ������ �� ������.
*/

void process(double** arr, unsigned int const& size, std::ofstream& log, std::ofstream& out) {
	unsigned int max_points = 4, hearts = 0, pts = 0;
	log << "��������� ������:\n";
	// ������� ���������� ������ � ������������ ����� �����
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			for (int k = j + 1; k < size; ++k) {
				for (int m = k + 1; m < size; ++m) {
					double ax = arr[i][0], ay = arr[i][1], bx = arr[j][0], by = arr[j][1], cx = arr[k][0], cy = arr[k][1], dx = arr[m][0], dy = arr[m][1];
					if (is_heart(ax, ay, bx, by, cx, cy, dx, dy)) {
						++hearts;
						log << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << cx << "; " << cy << "); ���� - (" << bx << "; " << by << "); ����� - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(ax, ay, bx, by, dx, dy, cx, cy)) {
						++hearts;
						log << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << dx << "; " << dy << "); ���� - (" << bx << "; " << by << "); ����� - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(ax, ay, cx, cy, bx, by, dx, dy)) {
						++hearts;
						log << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << bx << "; " << by << "); ���� - (" << cx << "; " << cy << "); ����� - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(bx, by, ax, ay, cx, cy, dx, dy)) {
						++hearts;
						log << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << cx << "; " << cy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(bx, by, ax, ay, dx, dy, cx, cy)) {
						++hearts;
						log << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << dx << "; " << dy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(bx, by, cx, cy, ax, ay, dx, dy)) {
						++hearts;
						log << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << ax << "; " << ay << "); ���� - (" << cx << "; " << cy << "); ����� - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(cx, cy, ax, ay, bx, by, dx, dy)) {
						++hearts;
						log << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << bx << "; " << by << "); ���� - (" << ax << "; " << ay << "); ����� - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(cx, cy, ax, ay, dx, dy, bx, by)) {
						++hearts;
						log << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << dx << "; " << dy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << bx << "; " << by << ")\n";
						pts = pts_inside(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(cx, cy, bx, by, ax, ay, dx, dy)) {
						++hearts;
						log << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << ax << "; " << ay << "); ���� - (" << bx << "; " << by << "); ����� - (" << dx << "; " << dy << ")\n";
						pts = pts_inside(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(dx, dy, ax, ay, bx, by, cx, cy)) {
						++hearts;
						log << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << bx << "; " << by << "); ���� - (" << ax << "; " << ay << "); ����� - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(dx, dy, ax, ay, cx, cy, bx, by)) {
						++hearts;
						log << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << cx << "; " << cy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << bx << "; " << by << ")\n";
						pts = pts_inside(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
					if (is_heart(dx, dy, bx, by, ax, ay, cx, cy)) {
						++hearts;
						log << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << ax << "; " << ay << "); ���� - (" << bx << "; " << by << "); ����� - (" << cx << "; " << cy << ")\n";
						pts = pts_inside(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size);
						log << "����� ������: " << pts << "\n���������� �����:\n";
						log_pts(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size, log);
						if (pts > max_points) max_points = pts;
					}
				}
			}
		}
	}
	if (!hearts) { // ������, ��� ������ ��� ������
		log << "��������, ���������� ������, ���������� �� ����.\n";
		out << "�� ���� ����� �� ���� ���������� �� ������ ������. ����� �� �������.\n����������� � ���-����� log.txt";
	}
	else if (max_points == 4) { // ������, ��� ������ ����, �� ��� ����� � ��� - �������
		log << "��� ������������ ������ �������� ������ �������: ������ ����� ��� �� ��������.\n";
		out << "��� ������������ ������ �������� ������ �������: ������ ����� ��� �� ��������. ����� �� �������.\n ����������� � ���-����� log.txt";
	}
	else {
		log << "���������� ������������ ����� �����, ������� ����� ��������� ������������ ������: " << max_points << ".\n������ ����� ������:\n";
		out << "���������� ������������ ����� �����, ������� ����� ��������� ������������ ������: " << max_points << ".\n������ ����� ������:\n";
		hearts = 0;
		// � ��� ������ ������� ������
		for (int i = 0; i < size; ++i) {
			for (int j = i + i; j < size; ++j) {
				for (int k = j + 1; k < size; ++k) {
					for (int m = k + 1; m < size; ++m) {
						double ax = arr[i][0], ay = arr[i][1], bx = arr[j][0], by = arr[j][1], cx = arr[k][0], cy = arr[k][1], dx = arr[m][0], dy = arr[m][1];
						if (is_heart(ax, ay, bx, by, cx, cy, dx, dy) && pts_inside(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << cx << "; " << cy << "); ���� - (" << bx << "; " << by << "); ����� - (" << dx << "; " << dy << ")\n";
							log << "���������� �����:\n";
							log_pts(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size, log);
							out << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << cx << "; " << cy << "); ���� - (" << bx << "; " << by << "); ����� - (" << dx << "; " << dy << ")\n";
							out << "���������� �����:\n";
							log_pts(ax, ay, bx, by, cx, cy, dx, dy, i, j, k, m, arr, size, out);
						}
						if (is_heart(ax, ay, bx, by, dx, dy, cx, cy) && pts_inside(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << dx << "; " << dy << "); ���� - (" << bx << "; " << by << "); ����� - (" << cx << "; " << cy << ")\n";
							log << "���������� �����:\n";
							log_pts(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size, log);
							out << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << dx << "; " << dy << "); ���� - (" << bx << "; " << by << "); ����� - (" << cx << "; " << cy << ")\n";
							out << "���������� �����:\n";
							log_pts(ax, ay, bx, by, dx, dy, cx, cy, i, j, m, k, arr, size, out);
						}
						if (is_heart(ax, ay, cx, cy, bx, by, dx, dy) && pts_inside(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << bx << "; " << by << "); ���� - (" << cx << "; " << cy << "); ����� - (" << dx << "; " << dy << ")\n";
							log << "���������� �����:\n";
							log_pts(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size, log);
							out << hearts << ") ���� - (" << ax << "; " << ay << "); ��� - (" << bx << "; " << by << "); ���� - (" << cx << "; " << cy << "); ����� - (" << dx << "; " << dy << ")\n";
							out << "���������� �����:\n";
							log_pts(ax, ay, cx, cy, bx, by, dx, dy, i, k, j, m, arr, size, out);
						}
						if (is_heart(bx, by, ax, ay, cx, cy, dx, dy) && pts_inside(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << cx << "; " << cy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << dx << "; " << dy << ")\n";
							log << "���������� �����:\n";
							log_pts(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size, log);
							out << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << cx << "; " << cy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << dx << "; " << dy << ")\n";
							out << "���������� �����:\n";
							log_pts(bx, by, ax, ay, cx, cy, dx, dy, j, i, k, m, arr, size, out);
						}
						if (is_heart(bx, by, ax, ay, dx, dy, cx, cy) && pts_inside(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << dx << "; " << dy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << cx << "; " << cy << ")\n";
							log << "���������� �����:\n";
							log_pts(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size, log);
							out << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << dx << "; " << dy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << cx << "; " << cy << ")\n";
							out << "���������� �����:\n";
							log_pts(bx, by, ax, ay, dx, dy, cx, cy, j, i, m, k, arr, size, out);
						}
						if (is_heart(bx, by, cx, cy, ax, ay, dx, dy) && pts_inside(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << ax << "; " << ay << "); ���� - (" << cx << "; " << cy << "); ����� - (" << dx << "; " << dy << ")\n";
							log << "���������� �����:\n";
							log_pts(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size, log);
							out << hearts << ") ���� - (" << bx << "; " << by << "); ��� - (" << ax << "; " << ay << "); ���� - (" << cx << "; " << cy << "); ����� - (" << dx << "; " << dy << ")\n";
							out << "���������� �����:\n";
							log_pts(bx, by, cx, cy, ax, ay, dx, dy, j, k, i, m, arr, size, out);
						}
						if (is_heart(cx, cy, ax, ay, bx, by, dx, dy) && pts_inside(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << bx << "; " << by << "); ���� - (" << ax << "; " << ay << "); ����� - (" << dx << "; " << dy << ")\n";
							log << "���������� �����:\n";
							log_pts(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size, log);
							out << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << bx << "; " << by << "); ���� - (" << ax << "; " << ay << "); ����� - (" << dx << "; " << dy << ")\n";							
							out << "���������� �����:\n";
							log_pts(cx, cy, ax, ay, bx, by, dx, dy, k, i, j, m, arr, size, out);
						}
						if (is_heart(cx, cy, ax, ay, dx, dy, bx, by) && pts_inside(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << dx << "; " << dy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << bx << "; " << by << ")\n";
							log << "���������� �����:\n";
							log_pts(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size, log);
							out << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << dx << "; " << dy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << bx << "; " << by << ")\n";
							out << "���������� �����:\n";
							log_pts(cx, cy, ax, ay, dx, dy, bx, by, k, i, m, j, arr, size, out);
						}
						if (is_heart(cx, cy, bx, by, ax, ay, dx, dy) && pts_inside(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << ax << "; " << ay << "); ���� - (" << bx << "; " << by << "); ����� - (" << dx << "; " << dy << ")\n";
							log << "���������� �����:\n";
							log_pts(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size, log);
							out << hearts << ") ���� - (" << cx << "; " << cy << "); ��� - (" << ax << "; " << ay << "); ���� - (" << bx << "; " << by << "); ����� - (" << dx << "; " << dy << ")\n";
							out << "���������� �����:\n";
							log_pts(cx, cy, bx, by, ax, ay, dx, dy, k, j, i, m, arr, size, out);
						}
						if (is_heart(dx, dy, ax, ay, bx, by, cx, cy) && pts_inside(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << bx << "; " << by << "); ���� - (" << ax << "; " << ay << "); ����� - (" << cx << "; " << cy << ")\n";
							log << "���������� �����:\n";
							log_pts(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size, log);
							out << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << bx << "; " << by << "); ���� - (" << ax << "; " << ay << "); ����� - (" << cx << "; " << cy << ")\n";
							out << "���������� �����:\n";
							log_pts(dx, dy, ax, ay, bx, by, cx, cy, m, i, j, k, arr, size, out);
						}
						if (is_heart(dx, dy, ax, ay, cx, cy, bx, by) && pts_inside(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << cx << "; " << cy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << bx << "; " << by << ")\n";
							log << "���������� �����:\n";
							log_pts(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size, log);
							out << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << cx << "; " << cy << "); ���� - (" << ax << "; " << ay << "); ����� - (" << bx << "; " << by << ")\n";
							out << "���������� �����:\n";
							log_pts(dx, dy, ax, ay, cx, cy, bx, by, m, i, k, j, arr, size, out);
						}
						if (is_heart(dx, dy, bx, by, ax, ay, cx, cy) && pts_inside(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size) == max_points) {
							++hearts;
							log << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << ax << "; " << ay << "); ���� - (" << bx << "; " << by << "); ����� - (" << cx << "; " << cy << ")\n";
							log << "���������� �����:\n";
							log_pts(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size, log);
							out << hearts << ") ���� - (" << dx << "; " << dy << "); ��� - (" << ax << "; " << ay << "); ���� - (" << bx << "; " << by << "); ����� - (" << cx << "; " << cy << ")\n";		
							out << "���������� �����:\n";
							log_pts(dx, dy, bx, by, ax, ay, cx, cy, m, j, i, k, arr, size, out);
						}
					}
				}
			}
		}
	}
}

/*
	������� clear_arr, ���������� ������� ������� ��������� ������ � ����������� ���������� ��� ���� ������.
*/

void clear_arr(double** arr, unsigned int const& size) {
	for (int i = 0; i < size; ++i) {
 i = delete[] arr[i];
	}
 i = delete[] arr;
	arr = NULL;
}