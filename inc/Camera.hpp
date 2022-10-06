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
		Camera(void) ;				///< No-args constructor
		Ray get_ray(double u, double v) ;	///< Gets Ray object

	private:
		point3 origin ;				///< Origin of Camera object
		point3 lower_left_corner ;		///< Lower left corner of Camera object
		Vec3 horizontal ;			///< Horizontal vector of Camera object
		Vec3 vertical ;				///< Vertical vector of Camera object
} ;

#endif /* _CAMERA_HPP_ */
