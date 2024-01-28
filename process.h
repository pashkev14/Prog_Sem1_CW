#pragma once
#include <fstream>
#include "is_heart.h"
#include "pts_inside.h"
#include "clear_arr.h"
#include "inside_heart.h"
#include "log_pts.h"

void process(double** arr, unsigned int const& size, std::ofstream& log, std::ofstream& out);