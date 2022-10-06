/**
 * @file Sphere.cpp
 * @Brief Sphere class definition
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#include "Sphere.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded Sphere constructor inits center and radius
 *
 * @Param cen		- Center of Sphere obj
 * @Param r		- Radius of Sphere obj
 */
/* ------------------------------------------------------------------------------------*/
Sphere::Sphere(point3 cen, double r)
	: center{cen}, radius{r} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Determines if Ray hits Sphere
 *
 * @Param r		- Radius
 * @Param t_min		- Min t val
 * @Param t_max		- Max t val
 * @Param rec		- Hit record
 *
 * @Returns bool	- Does the sphere get hit or not?
 */
/* ------------------------------------------------------------------------------------*/
bool Sphere::hit(Ray const &r, double t_min, double t_max, hit_record &rec) const {
	Vec3 oc           = r.origin() - center ;				///< origin of circle
	auto a            = r.direction().length_squared() ;
	auto half_b       = dot(oc, r.direction()) ;
	auto c            = oc.length_squared() - (radius*radius) ;

	auto discriminant = (half_b*half_b) - a*c ;
	if (discriminant < 0) {
		return false ;
	}
	auto sqrtd = std::sqrt(discriminant) ;

	// Find the nearest root that lies in the acceptable range
	auto root = (-half_b - sqrtd) / a ;
	if (root < t_min || t_max < root) {
		root = (-half_b + sqrtd) / a ;
		if (root < t_min || t_max < root) {
			return false ;
		}
	}

	rec.t               = root ;
	rec.p               = r.at(rec.t) ;
	// Set the surface side determination
	Vec3 outward_normal = (rec.p - center) / radius ;
	rec.set_face_normal(r, outward_normal) ;

	return true ;
}
