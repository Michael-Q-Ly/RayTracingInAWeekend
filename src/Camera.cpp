/**
 * @file Camera.cpp
 * @brief Camera class definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.2
 * @date 2022-10-05
 */
#include "Camera.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief			- Overloaded Camera constructor initializing Camera angle
 *				  and orientation
 *
 * @param look_from		- Position where we look from / where camera is located
 * @param look_at		- Point we look at / where camera is pointed
 * @param v_up			- Specifies roll or sideways tilt with a "view up" vector that
 *				  lies in a plane orthogonal to the view direction
 * @param v_fov			- Vertical field of view in degrees
 * @param aspect_ratio		- Aspect ratio of Camera object
 */
/* ------------------------------------------------------------------------------------*/
Camera::Camera(point3 look_from, point3 look_at, Vec3 v_up, double v_fov, double aspect_ratio) {
	auto theta           = degrees_to_radians(v_fov) ;
	auto h               = std::tan(theta/2) ;	// Height of triangle formed from angle and z-axis
	auto viewport_height = 2.0*h ;
	auto viewport_width  = aspect_ratio * viewport_height ;

	// u, v, and w form an orthonormal basis after a couple of cross products
	auto w = unit_vector(look_from - look_at) ;
	auto u = unit_vector(cross(v_up, w)) ;
	auto v = cross(w, u) ;

	origin            = look_from ;
	horizontal        = viewport_width * u ;
	vertical          = viewport_height * v ;
	lower_left_corner = origin - (horizontal/2) - (vertical/2) - w ;
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
Ray Camera::get_ray(double s, double t) {
	return Ray(origin, lower_left_corner + s*horizontal + t*vertical - origin) ;
}
