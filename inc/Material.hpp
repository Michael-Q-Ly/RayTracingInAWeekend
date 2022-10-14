/**
 * @file Material.hpp
 * @brief Material abstract class
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.2
 * @date 2022-10-11
 */
#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_
#include "Hittable.hpp"
#include "rtweekend.hpp"
#include "Ray.hpp"

struct hit_record ;

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Abstract class for material of an object in R3
 */
/* ------------------------------------------------------------------------------------*/
class Material {
	public:
		virtual bool scatter(
				Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered
		) const = 0 ;
		virtual ~Material(void) = default ;
} ;

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Lambertian Material class inherited from Material class
 */
/* ------------------------------------------------------------------------------------*/
class Lambertian : public Material {
	public:
		Lambertian(color const &a) ;										///< Overloaded Lambertian constructor

		virtual bool scatter(											///< Overidden scatter function to determine light scatter on Lambertian material
				Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered
				) const override ;

	public:
		color albedo ;												///< The portion of incident light or radiation that is reflected by a Lambertian surface
} ;

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Metal Material class
 */
/* ------------------------------------------------------------------------------------*/
class Metal : public Material {
	public:
		Metal(color const & a, double f) ;
		virtual bool scatter(											///< Overridden scatter function for Metal material
				Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered
		) const override ;
		virtual ~Metal(void) = default ;

	public:
		color albedo ;												///< The portion of incident light or radiation that is reflected by a metal surface
		double fuzz ;												///< Fuzziness of reflections
} ;

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Dielectric material class
 */
/* ------------------------------------------------------------------------------------*/
class Dielectric : public Material {
	public:
		Dielectric(double index_of_refraction) ;								///< Dielectric Material's index of refraction, Eta
		
		virtual bool scatter(											///< Overridden scatter function for Dielectric Material
				Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered
		) const override ;
		virtual ~Dielectric(void) = default ;

	public:
		double ir ;												///< Index of refraction of Dielectric object
} ;

#endif /* _MATERIAL_HPP_ */
