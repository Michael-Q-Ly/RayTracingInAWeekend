/**
 * @file Material.cpp
 * @brief 
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.2
 * @date 2022-10-11
 */
#include "Material.hpp"


/*-----------------------------------------------------------------------------
 * Lambertian 
 *-----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Initializes Lambertian object's albedo
 *
 * @param a		- Albedo; the portion of incident light reflected by surface 
 */
/* ------------------------------------------------------------------------------------*/
Lambertian::Lambertian(color const &a)
	: albedo{a} {

}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Determines if light will always scatter and attenuate by its
 *			  reflectance, R, or scatter with no attenuation but absorb the
 *			  fraction (1-R) of the r ays, or a mixture of these strategies
 *
 * @param r_in		- Incoming incident light ray
 * @param rec		- Record of light ray hitting
 * @param attenuation	- Attenuation of light
 * @param scattered	- Scattering of light
 *
 * @returns bool	- Does the light scatter or not?
 */
/* ------------------------------------------------------------------------------------*/
bool Lambertian::scatter(Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered) const {
	auto scatter_direction = rec.normal + random_unit_vector() ;

	// Catch degenerate scatter direction
	if (scatter_direction.near_zero()) {
		scatter_direction = rec.normal ;
	}

	scattered = Ray(rec.p, scatter_direction) ;
	attenuation = albedo ;
	return true ;
}








/*-----------------------------------------------------------------------------
 * Metal 
 *-----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Overloaded Metal constructor initializes metal material albedo
 *
 * @param a		- Albedo
 */
/* ------------------------------------------------------------------------------------*/
Metal::Metal(color const &a, double f)
	: albedo{a}, fuzz{(f < 1) ? f : 1} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Describes how light scatters on a metal object
 *
 * @param r_in		- Incident ray
 * @param rec		- Record of rays hitting
 * @param attenuation	- Light attenuation
 * @param scattered	- How much light is scattered
 *
 * @return bool		- Does the light scatter when it hits, or is it absorbed?
 */
/* ------------------------------------------------------------------------------------*/
bool Metal::scatter(const Ray &r_in, const hit_record &rec, color &attenuation, Ray &scattered) const {
	Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal) ;
	// Add dithering to reflected light with fuzz*random_in_unit_sphere (add noise to sphere reflection)
	scattered = Ray(rec.p, reflected + fuzz*random_in_unit_sphere()) ;
	attenuation = albedo ;
	return (dot(scattered.direction(), rec.normal) > 0) ;
}










/*-----------------------------------------------------------------------------
 * Dielectric 
 *-----------------------------------------------------------------------------*/

Dielectric::Dielectric(double index_of_refraction)
	: ir{index_of_refraction} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Describes how light scatters on a Dielectric object
 *
 * @param r_in		- Incident ray
 * @param rec		- Record of rays hitting
 * @param attenuation	- Light attenuation
 * @param scattered	- How much light is scattered
 *
 * @return bool		- Does the light scatter when it hits, or is it absorbed?
 */
/* ------------------------------------------------------------------------------------*/
bool Dielectric::scatter(Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered) const {
	attenuation             = color(1.0, 1.0, 1.0) ;
	// Refraction ratio will be a inverse of the index of refraction if light ray hits from front of object
	double refraction_ratio = rec.front_face ? (1.0/ir) : ir ;

	Vec3 unit_direction = unit_vector(r_in.direction()) ;
	Vec3 refracted      = refract(unit_direction, rec.normal, refraction_ratio) ;

	scattered = Ray(rec.p, refracted) ;
	return true ;
}
