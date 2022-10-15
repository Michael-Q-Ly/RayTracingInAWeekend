/**
 * @file Camera.cpp
 * @brief Camera class definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.3
 * @date 2022-10-05
 */
#include "Camera.hpp"

/* ----------------------------------------------------------------------------*/
/**
 */
/* ------------------------------------------------------------------------------------*/
/* ----------------------------------------------------------------------------*/
/**
 * @brief			- Overloaded Camera constructor with adjustable depth-of-field
 *
 * @param look_from		- Position where we look from / where camera is located
 * @param look_at		- Point we look at / where camera is pointed
 * @param v_up			- Specifies roll or sideways tilt with a "view up" vector that
 *				  lies in a plane orthogonal to the view direction
 * @param v_fov			- Vertical field of view in degrees
 * @param aspect_ratio		- Aspect ratio of Camera object
 * @param aperture		- A hole to control how big a Camera lens is ; bigger aperture means more defocus blur
 * @param focus_dist		- Focal length ; the distance between the projection point and the plane that is in focus
 *
 * @notes			- v_up, v, and w are all in the same plane
 */
/* ------------------------------------------------------------------------------------*/
Camera::Camera(point3 look_from, point3 look_at, Vec3 v_up, double v_fov, double aspect_ratio, double aperture, double focus_dist) {
	auto theta           = degrees_to_radians(v_fov) ;
	auto h               = std::tan(theta/2) ;	// Height of triangle formed from angle and z-axis
	auto viewport_height = 2.0*h ;
	auto viewport_width  = aspect_ratio * viewport_height ;

	// u, v, and w form an orthonormal basis after a couple of cross products
	w = unit_vector(look_from - look_at) ;
	u = unit_vector(cross(v_up, w)) ;
	v = cross(w, u) ;

	// Define the frame dimensions we look at
	origin            = look_from ;
	horizontal        = focus_dist * viewport_width * u ;
	vertical          = focus_dist * viewport_height * v ;
	lower_left_corner = origin - (horizontal/2) - (vertical/2) - (focus_dist*w) ;

	lens_radius = aperture/2 ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets Camera object ray
 *
 * @param s		- Horizontal vector
 * @param t		- Vertical vector
 *
 * @returns Ray		- Ray projecting out of Camera object
 */
/* ------------------------------------------------------------------------------------*/
Ray Camera::get_ray(double s, double t) {
	Vec3 rd = lens_radius * random_in_unit_disk() ;		// Random Disk / the lens
	Vec3 offset = u * rd.x() *rd.y() ;
	Vec3 offset_origin = origin + offset ;
	return Ray(offset_origin, lower_left_corner + s*horizontal + t*vertical - offset_origin) ;
}
