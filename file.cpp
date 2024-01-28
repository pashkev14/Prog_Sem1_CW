#include <fstream>
#include "ex_math.h"

/*
	Функция def_size, определяющая потенциальный размер массива данных.
	Возвращаемое число не окончательное, поскольку после def_size запускается второй обход файла на запись, во время которого отбрасываются дубли.
	Алгоритм считывания такой:
	1. Пробуем считать очередную последовательность символов в double
	2. Если получилось, бежим посимвольно до следующей последовательности
	3. Если не получилось, сбрасываем флаги и также идем посимвольно до следующей последовательности
	4. Соблюдаем последовательность: y не будет считываться без x, соответственно, если файловый указатель дошел до перехода на новую строку, всё накопленное сбрасывается
*/

unsigned int def_size(std::ifstream& in, std::ofstream& log) {
	unsigned int size = 0;
	int cur = 0;
	char tmpc = 0;
	double tmpx = 0.0, tmpy = 0.0;
	bool x = false, y = false;
	while (true) {
		if (!x) {
			if (in >> tmpx) {
				x = true;
				in.unsetf(std::ios::skipws);
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc != ' ' && tmpc != '\t');
				if (in.eof()) break;
				if (tmpc == '\n') {
					in.setf(std::ios::skipws);
					x = false;
					continue;
				}
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc == ' ' || tmpc == '\t');
				if (in.eof()) break;
				in.setf(std::ios::skipws);
				if (tmpc == '\n') {
					x = false;
				}
				else {
					cur = in.tellg();
					in.seekg(cur - 1, std::ios::beg);
				}
			}
			else {
				in.clear();
				in.unsetf(std::ios::skipws);
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc != ' ' && tmpc != '\t');
				if (in.eof()) break;
				if (tmpc == '\n') {
					in.setf(std::ios::skipws);
					x = false;
					continue;
				}
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc == ' ' || tmpc == '\t');
				if (in.eof()) break;
				in.setf(std::ios::skipws);
				if (tmpc == '\n') {
					x = false;
				}
				else {
					cur = in.tellg();
					in.seekg(cur - 1, std::ios::beg);
				}
			}
		}
		else {
			if (!y && in >> tmpy) {
				++size;
				if (size == 1) {
					log << "Обнаружены точки:\n";
				}
				log << size << ") x = " << tmpx << "; y = " << tmpy << "\n";
				y = true;
			}
			else in.clear();
			in.unsetf(std::ios::skipws);
			do {
				in >> tmpc;
				if (in.eof() || tmpc == '\n') break;
			} 
			while (tmpc != ' ' && tmpc != '\t');
			if (in.eof()) break;
			if (tmpc == '\n') {
				in.setf(std::ios::skipws);
				x = false;
				y = false;
				continue;
			}
			do {
				in >> tmpc;
				if (in.eof() || tmpc == '\n') break;
			} 
			while (tmpc == ' ' || tmpc == '\t');
			if (in.eof()) break;
			in.setf(std::ios::skipws);
			if (tmpc == '\n') {
				x = false;
				y = false;
			}
			else {
				cur = in.tellg();
				in.seekg(cur - 1, std::ios::beg);
			}
		}
	}
	in.clear();
	in.seekg(0, std::ios::beg);
	return size;
}

/*
	Функция fill_arr, записывающая точки из файла в массив. Также определяет окончательный размер массива.
	Алгоритм считывания аналогичен def_size, только добавляется проверка на то, что очередная точка не встречалась в массиве ранее.
*/

unsigned int fill_arr(std::ifstream& in, std::ofstream& log, double** arr, unsigned int const& size) {
	unsigned int count = 0;
	int cur = 0;
	char tmpc = 0;
	double tmpx = 0.0, tmpy = 0.0;
	bool x = false, y = false, met = false;
	while (true) {
		if (!x) {
			if (in >> tmpx) {
				x = true;
				in.unsetf(std::ios::skipws);
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc != ' ' && tmpc != '\t');
				if (in.eof()) break;
				if (tmpc == '\n') {
					in.setf(std::ios::skipws);
					x = false;
					continue;
				}
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc == ' ' || tmpc == '\t');
				if (in.eof()) break;
				in.setf(std::ios::skipws);
				if (tmpc == '\n') {
					x = false;
					continue;
				}
				else {
					cur = in.tellg();
					in.seekg(cur - 1, std::ios::beg);
				}
			}
			else {
				in.clear();
				in.unsetf(std::ios::skipws);
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc != ' ' && tmpc != '\t');
				if (in.eof()) break;
				if (tmpc == '\n') {
					in.setf(std::ios::skipws);
					x = false;
					continue;
				}
				do {
					in >> tmpc;
					if (in.eof() || tmpc == '\n') break;
				} 
				while (tmpc == ' ' || tmpc == '\t');
				if (in.eof()) break;
				in.setf(std::ios::skipws);
				if (tmpc == '\n') {
					x = false;
					continue;
				}
				else {
					cur = in.tellg();
					in.seekg(cur - 1, std::ios::beg);
				}
			}
		}
		else {
			if (!y && in >> tmpy) {
				for (int i = 0; i < count; ++i) {
					if (is_eq(arr[i][0], tmpx) && is_eq(arr[i][1], tmpy)) {
						met = true;
						break;
					}
				}
				if (!met) {
					arr[count][0] = tmpx; arr[count][1] = tmpy;
					++count;
					if (count == 1) log << "Записаны следующие точки:\n";
					log << count << ") x = " << tmpx << "; y = " << tmpy << "\n";
				}
				met = false;
				y = true;
			}
			else in.clear();
			in.unsetf(std::ios::skipws);
			do {
				in >> tmpc;
				if (in.eof() || tmpc == '\n') break;
			} 
			while (tmpc != ' ' && tmpc != '\t');
			if (in.eof()) break;
			if (tmpc == '\n') {
				in.setf(std::ios::skipws);
				x = false;
				y = false;
				continue;
			}
			do {
				in >> tmpc;
				if (in.eof() || tmpc == '\n') break;
			} 
			while (tmpc == ' ' || tmpc == '\t');
			if (in.eof()) break;
			in.setf(std::ios::skipws);
			if (tmpc == '\n') {
				x = false;
				y = false;
				continue;
			}
			else {
				cur = in.tellg();
				in.seekg(cur - 1, std::ios::beg);
			}
		}
	}
	return count;
}