/**
 * @file Vec3.cpp
 * @Brief Vec3 class definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#include "Vec3.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Vec3 constructor initializing all to zero
 */
/* ------------------------------------------------------------------------------------*/
Vec3::Vec3(void)
        : e{0, 0, 0} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded Vec3 constructor expecting 3 doubles
 *
 * @Param e0		- 1st element
 * @Param e1		- 2nd element
 * @Param e2		- 3rd element
 */
/* ------------------------------------------------------------------------------------*/
Vec3::Vec3(double e0, double e1, double e2)
        : e{e0, e1, e2} {
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets x position
 *
 * @Returns Vec3	- x coordinate / 1st element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::x(void) const {
        return e[0] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets y position
 *
 * @Returns double	- y coordinate / 2nd element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::y(void) const {
        return e[1] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets z position
 *
 * @Returns double	- z coordinate / 3rd element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::z(void) const {
        return e[2] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Makes all vector elements negative
 *
 * @Returns Vec3	- Vec3 object with negative elements
 */
/* ------------------------------------------------------------------------------------*/
Vec3 Vec3::operator-(void) const {
        return Vec3(-e[0], -e[1], -e[2]) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets Vec3 object array element
 *
 * @Param i		- Element index
 *
 * @Returns double	- Array element
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::operator[](int i) const {
        return e[i] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets Vec3 object array element
 *
 * @Param i		- Element index
 *
 * @Returns double	- Array element
 */
/* ------------------------------------------------------------------------------------*/
double &Vec3::operator[](int i) {
        return e[i] ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Overloaded Vec3 += operator; does 1:1 addition on elements
 *
 * @Param v		- The vector whose elements we are adding to the Vec3 obj
 *
 * @Returns double	- Vec3 array summed with the referenced vector
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
 * @Brief		- Overloaded Vec3 *= operator; does 1:1 scalar multiplication on elements
 *
 * @Param t		- Time
 *
 * @Returns Vec3	- Scaled Vec3 elements (multiplcation)
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
 * @Brief		- Overloaded /= operator; does 1:1 scalar multiplcation on elements (int division)
 *
 * @Param t		- Time
 *
 * @Returns Vec3	- Scaled Vec3 elements (int division)
 */
/* ------------------------------------------------------------------------------------*/
Vec3 &Vec3::operator/=(double const t) {
        return (*this *= (1/t)) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets Ray object length
 *
 * @Returns double	- Ray length
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::length(void) const {
        return (std::sqrt(length_squared())) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Gets Squared Ray object length
 *
 * @Returns double	- Squared Ray length
 */
/* ------------------------------------------------------------------------------------*/
double Vec3::length_squared(void) const {
        return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]) ;
}
