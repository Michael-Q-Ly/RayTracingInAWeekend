/**
 * @file Vec3.hpp
 * @Brief Vec3 class
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#ifndef _VEC3_HPP_
#define _VEC3_HPP_
#include "rtweekend.hpp"
#include <cmath>
#include <iostream>

/*-----------------------------------------------------------------------------
 * Vec3 Class 
 *-----------------------------------------------------------------------------*/
class Vec3 {
        public:
                Vec3(void) ;						///< No-args Vec3 constructor
                Vec3(double e0, double e1, double e2) ;			///< Overloaded Vec3 constructor

                double x() const ;					///< x-direction 
                double y() const ;					///< y-direction
                double z() const ;					///< z-direction

                Vec3 operator-(void) const ;				///< Overloaded Vec3 - operator
                double operator[](int i) const ;			///< Overloaded Vec3 [] const operator
                double &operator[](int i) ;				///< Overloaded Vec3 [] operator

                Vec3 &operator+=(Vec3 const &v) ;			///< Overloaded Vec3 += operator
                Vec3 &operator*=(double const t) ;			///< Overloaded Vec3 *= operator
                Vec3 &operator/=(double const t) ;			///< Overloaded Vec3 /= operator

                double length(void) const ;				///< Gets Vec3 length
                double length_squared(void) const ;			///< Gets Vec3 squared length

		/*-----------------------------------------------------------------------------
		 * Inline class functions 
		 *-----------------------------------------------------------------------------*/

		/* ----------------------------------------------------------------------------*/
		/**
		 * @Brief		- Create a Vec3 object with random element values
		 *
		 * @Returns Vec3	- Vec3 object with randomized elements
		 */
		/* ------------------------------------------------------------------------------------*/
		inline static Vec3 random(void) {
			return Vec3(random_double(), random_double(), random_double()) ;
		}

		/* ----------------------------------------------------------------------------*/
		/**
		 * @Brief		- Creates a Vec3 object with random elements in a range
		 *
		 * @Param min		- Min random number
		 * @Param max		- Max random number
		 *
		 * @Returns Vec3	- Vec3 object with randomized elements clustered together in range
		 */
		/* ------------------------------------------------------------------------------------*/
		inline static Vec3 random(double min, double max) {
			return Vec3(random_double(min, max), random_double(min, max), random_double(min, max)) ;
		}

        public:
                double e[3] ;						///< Vec3 elements
} ;

// Type aliases for Vec3
using point3 = Vec3 ;							///< 3D point
using color  = Vec3 ;							///< RGB color

/*-----------------------------------------------------------------------------
 * Vec3 Utility Functions 
 *-----------------------------------------------------------------------------*/


/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded inline output stream with Vec3 arg
 *
 * @Param out		- Reference to output stream
 * @Param v		- Vec3 object
 *
 * @Returns out		- The vector elements
 */
/* ------------------------------------------------------------------------------------*/
inline std::ostream &operator<<(std::ostream &out, Vec3 const &v) {
        return (out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2]) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded inline + operator with Vec3 args
 *
 * @Param u		- First vector
 * @Param v		- Second vector
 *
 * @Returns Vec3	- Vec3 object scaled with sum of two vectors
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator+(Vec3 const &u, Vec3 const &v) {
        return (Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded inline - operator with Vec3 args
 *
 * @Param u		- First vector
 * @Param v		- Second vector
 *
 * @Returns Vec3	- Vec3 object initialized with the difference of the two vectors
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator-(Vec3 const &u, Vec3 const &v) {
        return (Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded inline * operator with two Vec3 args
 *
 * @Param u		- The unit vector
 * @Param v		- The vector
 *
 * @Returns Vec3	- Vec3 object initialized with product of each element
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator*(Vec3 const &u, Vec3 const &v) {
        return (Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded inline * operator with one double and one Vec3 arg
 *
 * @Param t		- Time
 * @Param v		- The vector
 *
 * @Returns Vec3	- Vec3 object with scaled vector elements
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator*(double t, Vec3 const &v) {
        return (Vec3(t * v.e[0], t * v.e[1], t * v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded inline * operator with one Vec3 arg and one double 
 *
 * @Param v		- The vector
 * @Param t		- Time
 *
 * @Returns Vec3	- Vec3 object initialized with t scaling factor
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator*(Vec3 const &v, double t) {
        return (t * v) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded inline / operator with one Vec3 arg and one double 
 *
 * @Param v		- The vector
 * @Param t		- Time
 *
 * @Returns Vec3	- Vec3 object scaled by 1/t
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator/(Vec3 v, double t) {
        return ((1 / t) * v) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Dot product of two Vec3 objects
 *
 * @Param u		- First vector
 * @Param v		- Second vector
 *
 * @Returns Vec3	- The dot product of the two vectors
 */
/* ------------------------------------------------------------------------------------*/
inline double dot(Vec3 const &u, Vec3 const &v) {
        return (
                u.e[0] * v.e[0]
                + u.e[1] * v.e[1]
                + u.e[2] * v.e[2]
        ) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Cross product of two Vec3 objects
 *
 * @Param u		- First vector
 * @Param v		- Second vector
 *
 * @Returns		- The cross product of the two vectors
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 cross(Vec3 const &u, Vec3 const &v) {
        return (
                Vec3(
                        (u.e[1] * v.e[2]) - (u.e[2] * v.e[1]),
                        (u.e[2] * v.e[0]) - (u.e[0] * v.e[2]),
                        (u.e[0] * v.e[1]) - (u.e[1] * v.e[0])
                )
        ) ;
}
/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets unit vector of Vec3 object
 *
 * @Param v		- The vector
 *
 * @Returns		- The unit vector of the Vec3 object
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 unit_vector(Vec3 v) {
        return (v / v.length()) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Rejects points outside of an external unit sphere that determines
 *			\how light bounces off a sphere of diffuse material
 *
 * @Returns Vec3	- Light ray inside the unit sphere outside and tangent to actual sphere
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 random_in_unit_sphere(void) {
	while (true) {
		auto p = Vec3::random(-1, 1) ;
		if (p.length_squared() >= 1) {
			continue ;
		}
		return p ;
	}
}
#endif /* _VEC3_HPP_ */
