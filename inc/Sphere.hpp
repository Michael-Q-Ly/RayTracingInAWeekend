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
		Sphere(void) = default ;
		Sphere(point3 cen, double r) ;

		virtual bool hit(Ray const &r, double t_min, double t_max, hit_record &rec) const override ;
		virtual ~Sphere(void) = default ;

	public:
		point3 center ;
		double radius ;
} ;

#endif /* _SPHERE_HPP_ */
