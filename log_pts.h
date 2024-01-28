#pragma once

#include <fstream>

void log_pts(double const& tx, double const& ty, double const& lx, double const& ly, double const& dx, double const& dy, double const& rx, double const& ry, int const& ti, int const& li, int const& di, int const& ri, double** arr, unsigned int const& size, std::ofstream& log);