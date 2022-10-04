/**
 * @file Ray.hpp
 * @Brief Ray Class declarations
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-03
 *
 */
/*-----------------------------------------------------------------------------
 * Notes:
 * P(t) = A + tb. P is a 3D position along a line in 3D.
 * A is the ray origin and b is the ray direction.
 * The ray parameter t is a real number (double).
 * Plug in a different t and P(t) moves the point along the ray.
 *-----------------------------------------------------------------------------*/
#ifndef _RAY_HPP_
#define _RAY_HPP_
#include "Vec3.hpp"

/*-----------------------------------------------------------------------------
 * Ray Class 
 *-----------------------------------------------------------------------------*/
class Ray {
	public:
		Ray(void) ;						///< Default constructor
		Ray( point3 const &origin, Vec3 const &direction) ;	///< Overloaded Ray constructor

		point3 origin(void) const ;				///< point3 origin
		Vec3 direction(void) const ;				///< Vec3 direction

		point3 at(double t) const ;				///< point3 location

	public:
		point3 orig ;						///< Ray point3 origin
		Vec3 dir ;						///< Vec3 Ray direction
} ;

#endif /*  _RAY_HPP_ */
