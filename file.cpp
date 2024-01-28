#include <fstream>
#include "ex_math.h"

/*
	������� def_size, ������������ ������������� ������ ������� ������.
	������������ ����� �� �������������, ��������� ����� def_size ����������� ������ ����� ����� �� ������, �� ����� �������� ������������� �����.
	�������� ���������� �����:
	1. ������� ������� ��������� ������������������ �������� � double
	2. ���� ����������, ����� ����������� �� ��������� ������������������
	3. ���� �� ����������, ���������� ����� � ����� ���� ����������� �� ��������� ������������������
	4. ��������� ������������������: y �� ����� ����������� ��� x, ��������������, ���� �������� ��������� ����� �� �������� �� ����� ������, �� ����������� ������������
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
					log << "���������� �����:\n";
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
	������� fill_arr, ������������ ����� �� ����� � ������. ����� ���������� ������������� ������ �������.
	�������� ���������� ���������� def_size, ������ ����������� �������� �� ��, ��� ��������� ����� �� ����������� � ������� �����.
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
					if (count == 1) log << "�������� ��������� �����:\n";
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