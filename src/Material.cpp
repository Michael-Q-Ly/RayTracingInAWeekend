/**
 * @file Material.cpp
 * @Brief 
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-11
 */
#include "Material.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Initializes Lambertian object's albedo
 *
 * @Param a		- Albedo; the portion of incident light reflected by surface 
 */
/* ------------------------------------------------------------------------------------*/
Lambertian::Lambertian(color const &a)
	: albedo{a} {

}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Determines if light will always scatter and attenuate by its
 *			\reflectance, R, or scatter with no attenuation but absorb the
 *			\fraction (1-R) of the r ays, or a mixture of these strategies
 *
 * @Param r_in		- Incoming incident light ray
 * @Param rec		- Record of light ray hitting
 * @Param attenuation	- Attenuation of light
 * @Param scattered	- Scattering of light
 *
 * @Returns bool	- Does the light scatter or not?
 */
/* ------------------------------------------------------------------------------------*/
bool Lambertian::scatter(Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered) const {
	auto scatter_direction = rec.normal + random_unit_vector() ;
	scattered = Ray(rec.p, scatter_direction) ;
	attenuation = albedo ;
	return true ;
}
