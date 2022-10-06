/**
 * @file rtweekend.hpp
 * @Brief Ray Tracing in One Weekend header
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#ifndef _RTWEEKEND_HPP_
#define _HITTABLE_HPP_
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



/*-----------------------------------------------------------------------------
 * Common Headers 
 *-----------------------------------------------------------------------------*/

#include "Ray.hpp"
#include "Vec3.hpp"

#endif /*  _RTWEEKEND_HPP_ */
