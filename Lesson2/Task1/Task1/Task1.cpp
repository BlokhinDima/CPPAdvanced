#include <iostream>
using namespace std;

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = y; // y -> m_y
	}
}; // missing ; added

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

int main() // Main -> main
{
	int i;
	for (i = 0; i < 5; i++) { // redundant ; removed
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}

/*
Second definition of print_point after main function 
(has to be one definition before main)

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}
*/ 