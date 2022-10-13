/**
 * @file Vec3.cpp
 * @brief Vec3 class definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#include "Vec3.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Vec3 constructor initializing all to zero
 */
/* ------------------------------------------------------------------------------------*/
Vec3::Vec3(void)
        : e{0, 0, 0} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Overloaded Vec3 constructor expecting 3 doubles
 *
 * @param e0		- 1st element
 * @param e1		- 2nd element
 * @param e2		- 3rd element
 */
/* ------------------------------------------------------------------------------------*/
Vec3::Vec3(double e0, double e1, double e2)
        : e{e0, e1, e2} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets x position
 *
 * @returns Vec3	- x coordinate / 1st element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::x(void) const {
        return e[0] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets y position
 *
 * @returns double	- y coordinate / 2nd element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::y(void) const {
        return e[1] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets z position
 *
 * @returns double	- z coordinate / 3rd element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::z(void) const {
        return e[2] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Makes all vector elements negative
 *
 * @returns Vec3	- Vec3 object with negative elements
 */
/* ------------------------------------------------------------------------------------*/
Vec3 Vec3::operator-(void) const {
        return Vec3(-e[0], -e[1], -e[2]) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets Vec3 object array element
 *
 * @param i		- Element index
 *
 * @returns double	- Array element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::operator[](int i) const {
        return e[i] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets Vec3 object array element
 *
 * @param i		- Element index
 *
 * @returns double	- Array element
 */
/* ------------------------------------------------------------------------------------*/
double &Vec3::operator[](int i) {
        return e[i] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Overloaded Vec3 += operator; does 1:1 addition on elements
 *
 * @param v		- The vector whose elements we are adding to the Vec3 obj
 *
 * @returns double	- Vec3 array summed with the referenced vector
 */
/* ------------------------------------------------------------------------------------*/
Vec3 &Vec3::operator+=(Vec3 const &v) {
        e[0] += v.e[0] ;
        e[1] += v.e[1] ;
        e[2] += v.e[2] ;
        return *this ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Overloaded Vec3 *= operator; does 1:1 scalar multiplication on elements
 *
 * @param t		- Time
 *
 * @returns Vec3	- Scaled Vec3 elements (multiplcation)
 */
/* ------------------------------------------------------------------------------------*/
Vec3 &Vec3::operator*=(double const t) {
        e[0] *= t ;
        e[1] *= t ;
        e[2] *= t ;
        return *this ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Overloaded /= operator; does 1:1 scalar multiplcation on elements (int division)
 *
 * @param t		- Time
 *
 * @returns Vec3	- Scaled Vec3 elements (int division)
 */
/* ------------------------------------------------------------------------------------*/
Vec3 &Vec3::operator/=(double const t) {
        return (*this *= (1/t)) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets Ray object length
 *
 * @returns double	- Ray length
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::length(void) const {
        return (std::sqrt(length_squared())) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Gets Squared Ray object length
 *
 * @returns double	- Squared Ray length
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::length_squared(void) const {
        return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief		- Checks if the vector is close to zero in all directions
 *
 * @return bool		- True if vector is close to zero in all directions
 */
/* ------------------------------------------------------------------------------------*/
bool Vec3::near_zero(void) const {
	auto const s = 1e-8 ;
	return (fabs(e[0]) < s) && (fabs(e[1]) < s) &&  (fabs(e[2]) < s) ;
}
