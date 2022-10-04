/**
 * @file Ray.cpp
 * @Brief Ray Class method definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-03
 */
#include "Ray.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Ray constructor
 */
/* ------------------------------------------------------------------------------------*/
Ray::Ray(void) = default ;

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Ray overloaded constructor
 *
 * @Param origin	- Origin of ray
 * @Param direction	- Direction ray is pointing
 */
/* ------------------------------------------------------------------------------------*/
Ray::Ray(point3 const &origin, Vec3 const &direction)
	: orig{origin}, dir{direction} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets origin of Ray object
 *
 * @Returns point3	- Origin of ray
 */
/* ------------------------------------------------------------------------------------*/
point3 Ray::origin(void) const {
	return orig ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets direction of Ray object
 *
 * @Returns Vec3	- Direction Ray object is pointing
 */
/* ------------------------------------------------------------------------------------*/
Vec3 Ray::direction(void) const {
	return dir ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Location of vector point
 *
 * @Param t		- Time
 *
 * @Returns Ray		- Location ray is at
 */
/* ------------------------------------------------------------------------------------*/
point3 Ray::at(double t) const {
	return orig + (t * dir) ;
}
