/**
 * @file Camera.hpp
 * @brief Camera class header
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.3
 * @date 2022-10-05
 */
#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_
#include "rtweekend.hpp"
#include "Ray.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Camera object that gets a ray back from a projection in R3 made
 *			  from a ray
 */
/* ------------------------------------------------------------------------------------*/
class Camera {
	public:
		Camera (					///< Overloaded Camera constructor with positioning, orientation, aperture, and focus distance arguments
			point3 look_from,
			point3 look_at,
			Vec3 v_up,
			double v_fov,			///< Vertical field of view
			double aspect_ratio,
			double aperture,
			double focus_dist
		) ;
		Ray get_ray(double s, double t) ;		///< Gets Ray object

	private:
		point3 origin ;					///< Origin of Camera object
		point3 lower_left_corner ;			///< Lower left corner of Camera object
		Vec3 horizontal ;				///< Horizontal vector of Camera object
		Vec3 vertical ;					///< Vertical vector of Camera object
		Vec3 u ;
		Vec3 v ;
		Vec3 w ;
		double lens_radius ;
} ;

#endif /* _CAMERA_HPP_ */
