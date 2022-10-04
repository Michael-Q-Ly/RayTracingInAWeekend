/**
 * @file Vec3.hpp
 * @Brief Vec3 class
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#ifndef _VEC3_HPP_
#define _VEC3_HPP_
#include <cmath>
#include <iostream>

/*-----------------------------------------------------------------------------
 * Vec3 Class 
 *-----------------------------------------------------------------------------*/
class Vec3 {
        public:
                Vec3(void) ;
                Vec3(double e0, double e1, double e2) ;

                double x() const ;
                double y() const ;
                double z() const ;

                Vec3 operator-(void) const ;
                double operator[](int i) const ;
                double &operator[](int i) ;

                Vec3 &operator+=(Vec3 const &v) ;
                Vec3 &operator*=(double const t) ;
                Vec3 &operator/=(double const t) ;

                double length(void) const ;
                double length_squared(void) const ;
        public:
                double e[3] ;
} ;

// Type aliases for Vec3
using point3 = Vec3 ;           // 3D point
using color  = Vec3 ;           // RGB color

/*-----------------------------------------------------------------------------
 * Vec3 Utility Functions 
 *-----------------------------------------------------------------------------*/


/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param out
 * @Param v
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline std::ostream &operator<<(std::ostream &out, Vec3 const &v) {
        return (out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2]) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param u
 * @Param v
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator+(Vec3 const &u, Vec3 const &v) {
        return (Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param u
 * @Param v
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator-(Vec3 const &u, Vec3 const &v) {
        return (Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param u
 * @Param v
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator*(Vec3 const &u, Vec3 const &v) {
        return (Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param t
 * @Param v
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator*(double t, Vec3 const &v) {
        return (Vec3(t * v.e[0], t * v.e[1], t * v.e[2])) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param v
 * @Param t
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator*(Vec3 const &v, double t) {
        return (t * v) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param v
 * @Param t
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 operator/(Vec3 v, double t) {
        return ((1 / t) * v) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief 
 *
 * @Param u
 * @Param v
 *
 * @Returns 
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
 * @Brief 
 *
 * @Param u
 * @Param v
 *
 * @Returns 
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
 * @Brief 
 *
 * @Param v
 *
 * @Returns 
 */
/* ------------------------------------------------------------------------------------*/
inline Vec3 unit_vector(Vec3 v) {
        return (v / v.length()) ;
}

#endif /* _VEC3_HPP_ */
