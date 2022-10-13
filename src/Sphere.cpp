/**
 * @file Sphere.cpp
 * @brief Sphere class definition
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#include "Sphere.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Overloaded Sphere constructor inits center and radius
 *
 * @param cen		- Center of Sphere obj
 * @param r		- Radius of Sphere obj
 */
/* ------------------------------------------------------------------------------------*/
Sphere::Sphere(point3 cen, double r, std::shared_ptr<Material> m)
	: center{cen}, radius{r}, mat_ptr{m} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Determines if Ray hits Sphere
 *
 * @param r		- Radius
 * @param t_min		- Min t val
 * @param t_max		- Max t val
 * @param rec		- Hit record
 *
 * @returns bool	- Does the sphere get hit or not?
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
	rec.mat_ptr = mat_ptr ;

	return true ;
}
