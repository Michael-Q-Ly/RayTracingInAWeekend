/**
 * @file Camera.cpp
 * @brief Camera class definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.1
 * @date 2022-10-05
 */
#include "Camera.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief			- Overloaded Camera constructor initializing vertical
 *				  field of view and aspect ratio
 *
 * @param vfov			- Vertical field of view in degrees
 * @param aspect_ratio		- Aspect ratio of Camera object
 */
/* ------------------------------------------------------------------------------------*/
Camera::Camera(double vfov, double aspect_ratio) {
	auto theta           = degrees_to_radians(vfov) ;
	auto h               = std::tan(theta/2) ;	// Height of triangle formed from angle and z-axis
	auto viewport_height = 2.0*h ;
	auto viewport_width  = aspect_ratio * viewport_height ;

	auto focal_length    = 1.0 ;

	origin            = point3(0, 0, 0) ;
	horizontal        = Vec3(viewport_width, 0, 0) ;
	vertical          = Vec3(0, viewport_height, 0) ;
	lower_left_corner = origin - (horizontal/2) - (vertical/2) - Vec3(0, 0, focal_length) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets Camera object ray
 *
 * @param u		- Horizontal vector
 * @param v		- Vertical vector
 *
 * @returns Ray		- Ray projecting out of Camera object
 */
/* ------------------------------------------------------------------------------------*/
Ray Camera::get_ray(double u, double v) {
	return Ray(origin, lower_left_corner + (u*horizontal) + (v*vertical) - origin) ;
}
