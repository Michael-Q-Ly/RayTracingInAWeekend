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

#endif /* _VEC3_HPP_ */
