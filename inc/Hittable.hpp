/**
r* @file Hittable.hpp
 * @Brief Abstract class for hit function
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#ifndef _HITTABLE_HPP_
#define _HITTABLE_HPP_
#include "Ray.hpp"

struct hit_record {
	point3 p ;						///< hit point
	Vec3 normal ;						///< Surface normal
	double t ;						///< Time or trace

	bool front_face ;					///< Is ray front-facing or not?

	/* ----------------------------------------------------------------------------*/
	/**
	 * @Brief			- Determine if the normal should point inwards or outwards to or out from the surface
	 *
	 * @Param r			- Radius
	 * @Param outward_normal	- Vec3 object pointing in or out of shape
	 *
	 * @Notes			- Is the ray coming from inside or from outside?
	 */
	/* ------------------------------------------------------------------------------------*/
	inline void set_face_normal(Ray const &r, Vec3 const &outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0 ;
		normal = front_face ? outward_normal : -outward_normal ;
	}
} ;

class Hittable {
	public:
		virtual bool hit(Ray const &r, double t_min, double t_max, hit_record &rec) const = 0 ;		///< Pure virtual
		virtual ~Hittable(void) ;
} ;

#endif /*  _HITTABLE_HPP_ */