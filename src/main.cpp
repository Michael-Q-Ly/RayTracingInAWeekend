/**
 * @file main.cpp
 * @Brief main program
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#include "color.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"
#include <iostream>

static color ray_color(Ray const &r) ;

int main() {

	/*-----------------------------------------------------------------------------
	 * Image 
	 *-----------------------------------------------------------------------------*/
	auto const aspect_ratio = 16.0 / 9.0 ;
	int const image_width   = 400 ;
	int const image_height  = static_cast<int>(image_width/aspect_ratio) ;

	/*-----------------------------------------------------------------------------
	 * Camera 
	 *-----------------------------------------------------------------------------*/
	auto viewport_height = 2.0 ;
	auto viewport_width  = aspect_ratio * viewport_height ;
	auto focal_length    = 1.0 ;

	auto origin = point3(0, 0, 0) ;
	auto horizontal = Vec3(viewport_width, 0, 0) ;
	auto vertical = Vec3(0, viewport_height, 0) ;
	auto lower_left_corner = origin - (horizontal/2) - (vertical/2) - Vec3(0, 0, focal_length) ;
	(void)lower_left_corner ;

	/*-----------------------------------------------------------------------------
	 * Render 
	 *-----------------------------------------------------------------------------*/

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j {image_height-1}; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush ;
		for (int i  {0}; i < image_width; ++i) {
			auto u = double(i) / (image_width-1) ;
			auto v = double(j) / (image_height-1) ;
			Ray r(origin, lower_left_corner + (u*horizontal) + (v*vertical) - origin) ;
			color pixel_color = ray_color(r) ;
			write_color(std::cout, pixel_color) ;
        }
    }
	std::cerr << "\nDone." << std::endl ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Traces a color ray
 *
 * @Param r		- The color ray
 *
 * @Returns color	- Returns a color (Vec3 obj)
 *
 * @Notes		- 1. Calculates ray from cam eye to pixel
 *			\2. Determines which objects the ray intersects
 *			\3. Computes a color for that intersection point
 */
/* ------------------------------------------------------------------------------------*/
static color ray_color(Ray const &r) {
	Vec3 unit_direction = unit_vector(r.direction()) ;
	auto t = 0.5 * (unit_direction.y() + 1.0) ;
	return (1.0 - t) * color(1.0, 1.0, 1.0) + (t * color(0.5, 0.7, 1.0)) ;
}
