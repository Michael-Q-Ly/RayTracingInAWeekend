 /**
 * @file Sphere.hpp
 * @Brief Sphere class
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#ifndef _SPHERE_HPP_
#define _SPHERE_HPP_

#include "Hittable.hpp"
#include "Vec3.hpp"

class Sphere : public Hittable {
	public:
		Sphere(void) = default ;										///< No-args Sphere constructor
		Sphere(point3 cen, double r) ;										///< Overloaded Sphere constructer to initialize center and radius

		virtual bool hit(Ray const &r, double t_min, double t_max, hit_record &rec) const override ;		///< Does a ray hit a shphere or not?
		virtual ~Sphere(void) = default ;									///< Sphere destructor

	public:
		point3 center ;												///< Center of sphere
		double radius ;												///< Radius of sphere
} ;

#endif /* _SPHERE_HPP_ */
