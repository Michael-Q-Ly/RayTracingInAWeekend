/**
 * @file Camera.hpp
 * @Brief Camera class header
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_
#include "rtweekend.hpp"

class Camera {
	public:
		Camera(void) ;

		Ray get_ray(double u, double v) ;

	private:
		point3 origin ;
		point3 lower_left_corner ;
		Vec3 horizontal ;
		Vec3 vertical ;
} ;

#endif /* _CAMERA_HPP_ */
