/*
	�������� ������ �� 1 �������. ������� 7�:
	���� N ����� �� ���������. ����� ����� ��� �����, ���������� ��������� ������, 
	���������� ������������ ����� �������� �����.
	������: ������
	�����: ����� ����� ����������, ������ 2309.
	����: ������: 17.11.2022 ��������� 15.12.2022
*/

// ��������� ��� ��������� �� ������������ ������, � main ����� ���������� ������ ��
#include "ex_math.h"
#include "file.h"
#include "process.h"

int main() {
	// ������� ������� ��� �����: ������� � �������, ���-���� ��� ������ ����� ������������� � �������� ��� ������ ��������� ������ �� ������
	std::ifstream infile("in.txt");
	std::ofstream logfile("log.txt");
	std::ofstream outfile("out.txt");
	logfile << "��������� ������ ������.\n������������ ������� �������� �������� �����.\n";
	if (infile) { // ���� ������� ���� ��������, �������� ������, �����...
		logfile << "�������� ����������� ��� ���������.\n";
		unsigned int pts_cnt = def_size(infile, logfile); // ��������� ������ �����, ���� ���������� �����
		if (pts_cnt < 4) { // ������ ������� �� 4 ����� ������, ������� ����� ����� � ������ �� ����� ������
			if (!pts_cnt) logfile << "���������� ��� ���������, ���������� �����, �� �������.\n��������� ��������� ������.";
			else logfile << "������������ ��� ��������� ������ ������������ (4).\n��������� ��������� ������.";
			outfile << "������������ ����� ��� ���������� ���� �� ������ ������. ����� �� �������.\n����������� � ���-����� log.txt";
			return 0;
		}
		logfile << "�������� �����: " << pts_cnt << ".\n������������ ������ ����� �������� ����� � ������� ������ ������� ������ � ������.\n";
		// � ����� ���������� ���������� �����, �������� ������ ��� ������
		double** A = new double* [pts_cnt];
		for (int i = 0; i < pts_cnt; ++i) A[i] = new double[2];
		unsigned int arr_len = fill_arr(infile, logfile, A, pts_cnt); // ��������� ������ ����� � ������ ������ � ������
		if (arr_len < pts_cnt) { // ����� ���� �����, �� ���������� ��� �������������, ��������������, ����� ������ ����� ����� ������ �����������
			logfile << "��� ��������� ������ ���� ���������� �����.\n";
			if (arr_len < 4) {
				if (arr_len == 1) logfile << "���� ���� ������� �� ������ ����� �����, ��� ������������ ��� ������������ ������ (4).\n��������� ��������� ������.";
				else logfile << "������������ ������ ������� � ����, ��� ����� ���� ������ ������������ (4).\n��������� ��������� ������.";
				outfile << "��� ������ ����� � �������� ����� ���� ���������� �����.\n�� ������������ ������� � ����, ��� ����� ���� ������ ������������ ���� �� ��� ������ ������. ����� �� �������.\n����������� � ���-����� log.txt";
				clear_arr(A, pts_cnt); // ��������� ������ ��� �������� � � ��� ��� ���-�� ������������, ������� ���������� ��� ���� ������
				return 0;
			}
		}
		process(A, arr_len, logfile, outfile); // ��������� ���������
		clear_arr(A, pts_cnt); // ������ ���������, ����� ���������� ������
	}
	else { // ...����� ��������, ��� ��� �����, � ������������
		logfile << "���� �� ������.\n";
		outfile << "������ ������ �������� �����.\n����������� � ���-����� log.txt";
	}
	logfile << "��������� ��������� ������.";
	infile.close();
	outfile.close();
	logfile.close();
	return 0;
}