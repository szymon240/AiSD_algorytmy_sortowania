#pragma once
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include "Arrays.h"
#include "Sorts.h"

void menu();

void test(void array_creation(int*, int), void sorting(int*, int), std::ofstream* output_file);