/**
 * @file Ray.cpp
 * @brief Ray Class method definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-03
 */
#include "Ray.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Ray constructor
 */
/* ------------------------------------------------------------------------------------*/
Ray::Ray(void) = default ;

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Ray overloaded constructor
 *
 * @param origin	- Origin of ray
 * @param direction	- Direction ray is pointing
 */
/* ------------------------------------------------------------------------------------*/
Ray::Ray(point3 const &origin, Vec3 const &direction)
	: orig{origin}, dir{direction} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets origin of Ray object
 *
 * @returns point3	- Origin of ray
 */
/* ------------------------------------------------------------------------------------*/
point3 Ray::origin(void) const {
	return orig ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets direction of Ray object
 *
 * @returns Vec3	- Direction Ray object is pointing
 */
/* ------------------------------------------------------------------------------------*/
Vec3 Ray::direction(void) const {
	return dir ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Location of vector point
 *
 * @param t		- Time
 *
 * @returns Ray		- Location ray is at
 */
/* ------------------------------------------------------------------------------------*/
point3 Ray::at(double t) const {
	return orig + (t * dir) ;
}
