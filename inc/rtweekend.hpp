/**
 * @file rtweekend.hpp
 * @brief Ray Tracing in One Weekend header
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
 * @brief		- Convert degrees to radians
 *
 * @param degrees	- Angle
 *
 * @returns double	- Radian equivalant of angle
 */
/* ------------------------------------------------------------------------------------*/
inline double degrees_to_radians(double degrees) {
	return degrees * (pi/180.0) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Clamps value x to range [min,max]
 *
 * @param x		- Value to clamp
 * @param min		- Min val
 * @param max		- Max val
 *
 * @returns double	- Clamped value of number passed
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
 * @brief		- No-args randome double generator from cstdlib
 *
 * @returns 
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
 * @brief		- Returns a random real in [0, 1)
 *
 * @returns double	- Random double in [0, 1)
 */
/* ------------------------------------------------------------------------------------*/
inline double random_double(void) {
	return rand() / (RAND_MAX + 1.0) ;
}
#endif /* CSTDLIB */

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Returns a random real in [min, max] (overloaded)
 *
 * @param min		- Min number boundary
 * @param max		- Max number bounder
 *
 * @returns double	- Scaled random number between a range
 */
/* ------------------------------------------------------------------------------------*/
inline double random_double(double min, double max) {
	return min + (max - min)*random_double() ;
}



/*-----------------------------------------------------------------------------
 * Common Headers 
 *-----------------------------------------------------------------------------*/

/* #include "Ray.hpp" */
/* #include "Vec3.hpp" */

#endif /* _RTWEEKEND_HPP_ */
