#include "Tests.h"

void test(void array_creation(int*, int), void sorting(int*, int), std::ofstream* output_file)
{
	std::cout << "Dolna granica = 10000 elemntow\n";
	std::cout << "Podaj gorna granica testow: ";
	int test_lim;
	std::cin >> test_lim;
	for (int i = 10000; i <= test_lim; i += 2000)
	{
		int* unsorted_array = new int[i];
		array_creation(unsorted_array, i);
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		sorting(unsorted_array, i);
		std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		*output_file << i << "	" << duration.count() << std::endl;
		delete[] unsorted_array;
	}
}

void menu()
{
	bool test_active = true;
	void (*array_creation)(int*, int) = nullptr;
	void (*sorting_algh)(int*, int) = nullptr;
	std::string array_type;
	std::string sort_type;
	int option;
	while (test_active)
	{
		std::cout << "Wybierz rodzaj tablicy(liczba):\n1.Losowa\n2.Rosnaca\n3.Malejaca\n4.Stala\n5.V - ksztaltna\n6.A-ksztaltna\nOpcja: ";
		std::cin >> option;
		switch (option)
		{
		case 1:
			array_type = "random";
			array_creation = &generate_random_array;
			break;
		case 2:
			array_type = "increasing";
			array_creation = &generate_increasing_array;
			break;
		case 3:
			array_type = "decreasing";
			array_creation = &generate_decreasing_array;
			break;
		case 4:
			array_type = "constant";
			array_creation = &generate_constant_array;
			break;
		case 5:
			array_type = "v_shaped";
			array_creation = &generate_vshaped_array;
			break;
		case 6:
			array_type = "a_shaped";
			array_creation = &generate_ashaped_array;
			break;
		default:
			break;
		}

		std::cout << "Wybierz typ sortowania(liczba):\n1.Insertion\n2.Selection\n3.Heap\n4.Merge\n5.Quick\nOpcja: ";
		std::cin >> option;
		switch (option)
		{
		case 1:
			sort_type = "insertion";
			sorting_algh = &insertion_sort_main;
			break;
		case 2:
			sort_type = "selection";
			sorting_algh = &selection_sort_main;
			break;
		case 3:
			sort_type = "heap";
			sorting_algh = &heap_sort_main;
			break;
		case 4:
			sort_type = "merge";
			sorting_algh = &merge_sort_main;
			break;
		case 5:
			sort_type = "quick";
			sorting_algh = &quick_sort_main;
			break;
		default:
			break;
		}

		std::ofstream output_file("./wyniki/" + array_type + sort_type + ".txt", std::ofstream::out);
		output_file << "Liczba elementow	czas\n";
		test(array_creation, sorting_algh, &output_file);
		output_file.close();

		std::cout << "Czy chcesz przeprowadzic jeszcze inny test (1 / 0) : ";
		std::cin >> option;
		if (option != 1)
			test_active = false;
	}
}