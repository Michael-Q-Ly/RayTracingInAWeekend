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

static double hit_sphere(point3 const &center, double radius, Ray const &r) ;
static color ray_color(Ray const &r) ;

int main(int argc, char *argv[]) {

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

	auto origin            = point3(0, 0, 0) ;
	auto horizontal        = Vec3(viewport_width, 0, 0) ;
	auto vertical          = Vec3(0, viewport_height, 0) ;
	auto lower_left_corner = origin - (horizontal/2) - (vertical/2) - Vec3(0, 0, focal_length) ;

	/*-----------------------------------------------------------------------------
	 * Render 
	 *-----------------------------------------------------------------------------*/

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j {image_height-1}; j >= 0; j--) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush ;
		for (int i  {0}; i < image_width; i++) {
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
 * @Brief		- Determines if a light ray hits a sphere by calculating a determinant
 *
 * @Param center	- Center of the sphere
 * @Param radius	- Radius of the sphere
 * @Param r		- Ray we test to see if it hits sphere
 *
 * @Returns double	- Where does the ray hit? Inside or outside?
 */
/* ------------------------------------------------------------------------------------*/
static double hit_sphere(point3 const &center, double radius, Ray const &r) {
	Vec3 oc           = r.origin() - center ;				///< origin of circle
	auto a            = dot(r.direction(), r.direction()) ;		///< <P(t) -C> dot <P(t) - C> = r^2
	auto b            = 2.0 * dot(oc, r.direction()) ;
	auto c            = dot(oc, oc) - radius*radius ;
	auto discriminant = (b*b) - (4*a*c) ;
	if (discriminant < 0) {
		return -1.0 ;
	}
	else {
		return (-b - std::sqrt(discriminant) / (2.0*a)) ;
	}
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
	auto t = hit_sphere(point3(0,0,-1), 0.5, r) ;
	if (t > 0.0) {
		/* Create a surface normal */
		Vec3 N = unit_vector(r.at(t) - Vec3(0, 0, -1)) ;
		return ( (0.5*color( N.x()+1, N.y()+1, N.z()+1 )) ) ;
	}
	Vec3 unit_direction = unit_vector(r.direction()) ;
	t = 0.5 * (unit_direction.y() + 1.0) ;
	return (1.0 - t) * color(1.0, 1.0, 1.0) + (t * color(0.5, 0.7, 1.0)) ;
}
