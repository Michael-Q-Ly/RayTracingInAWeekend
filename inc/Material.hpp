/**
 * @file Material.hpp
 * @Brief Material abstract class
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-11
 */
#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_
#include "Hittable.hpp"
#include "rtweekend.hpp"
#include "Ray.hpp"

struct hit_record ;
class Material {
	public:
		virtual bool scatter(
				Ray const &r_in, hit_record const &rec, color &attenuation, Ray &scattered
		) const = 0 ;
		virtual ~Material(void) = default ;
} ;

#endif /* _MATERIAL_HPP_ */
