/**
 * @file rtweekend.hpp
 * @Brief Ray Tracing in One Weekend header
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#ifndef _RTWEEKEND_HPP_
#define _RTWEEKEND_HPP_
#include <cmath>
#include <limits>
#include <memory>

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
inline double degrees_to_radiuans(double degrees) {
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



/*-----------------------------------------------------------------------------
 * Common Headers 
 *-----------------------------------------------------------------------------*/

#include "Ray.hpp"
#include "Vec3.hpp"

#endif /* _RTWEEKEND_HPP_ */
