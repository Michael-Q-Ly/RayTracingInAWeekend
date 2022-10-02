/**
 * @file main.cpp
 * @Brief main program
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#include "color.hpp"
#include "Vec3.hpp"
#include "Vec3_Utility.hpp"
#include <iostream>

int main() {
	// Image

	const int image_width = 256;
	const int image_height = 256;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height-1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush ;
		for (int i = 0; i < image_width; ++i) {
			color pixel_color(double(i) / (image_width-1), double(j) / (image_height-1), 0.25) ;
			write_color(std::cout, pixel_color) ;
        }
    }
	std::cerr << "\nDone." << std::endl ;
}
