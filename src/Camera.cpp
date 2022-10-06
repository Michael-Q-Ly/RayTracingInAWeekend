/**
 * @file Camera.cpp
 * @Brief Camera class definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#include "Camera.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- No-args Camera constructor
 * @Notes		- Sets aspect ratio, viewport hieght, width, and focal length
 *			- Also sets origin, horizontal, vertical, and lower left corner
 */
/* ------------------------------------------------------------------------------------*/
Camera::Camera(void) {
	auto aspect_ratio = 16.0/9.0 ;
	auto viewport_height = 2.0 ;
	auto viewport_width  = aspect_ratio * viewport_height ;
	auto focal_length    = 1.0 ;

	origin            = point3(0, 0, 0) ;
	horizontal        = Vec3(viewport_width, 0, 0) ;
	vertical          = Vec3(0, viewport_height, 0) ;
	lower_left_corner = origin - (horizontal/2) - (vertical/2) - Vec3(0, 0, focal_length) ;
}
