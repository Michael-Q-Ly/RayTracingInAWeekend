/**
 * @file rtweekend.hpp
 * @Brief Ray Tracing in One Weekend header
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#ifndef _RTWEEKEND_HPP_
#define _RTWEEKEND_HPP_

#define CSTDLIB

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>

/*-----------------------------------------------------------------------------
 * Constants 
 *-----------------------------------------------------------------------------*/
double const infinity = std::numeric_limits<double>::infinity() ;
double const pi       = 3.1415926535897932385 ;

/*-----------------------------------------------------------------------------
 * Utility Functions 
 *-----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Convert degrees to radians
 *
 * @Param degrees	- Angle
 *
 * @Returns double	- Radian equivalant of angle
 */
/* ------------------------------------------------------------------------------------*/
inline double degrees_to_radians(double degrees) {
	return degrees * (pi/180.0) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Clamps value x to range [min,max]
 *
 * @Param x		- Value to clamp
 * @Param min		- Min val
 * @Param max		- Max val
 *
 * @Returns double	- Clamped value of number passed
 */
/* ------------------------------------------------------------------------------------*/
inline double clamp(double x, double min, double max) {
	if (x < min) { return min ; }
	if (x > max) { return max ; }
	return x ;
}

#ifdef CSTDLIB
/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- No-args randome double generator from cstdlib
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline double random_double(void) {
	static std::uniform_real_distribution<double> distribution(0.0, 1.0) ;
	static std::mt19937 generator ;
	return distribution(generator) ;
}
#else
/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Returns a random real in [0, 1)
 *
 * @Returns double	- Random double in [0, 1)
 */
/* ------------------------------------------------------------------------------------*/
inline double random_double(void) {
	return rand() / (RAND_MAX + 1.0) ;
}
#endif /* CSTDLIB */

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Returns a random real in [min, max] (overloaded)
 *
 * @Param min		- Min number boundary
 * @Param max		- Max number bounder
 *
 * @Returns double	- Scaled random number between a range
 */
/* ------------------------------------------------------------------------------------*/
inline double random_double(double min, double max) {
	return min + (max - min)*random_double() ;
}



/*-----------------------------------------------------------------------------
 * Common Headers 
 *-----------------------------------------------------------------------------*/

#include "Ray.hpp"
#include "Vec3.hpp"

#endif /* _RTWEEKEND_HPP_ */
