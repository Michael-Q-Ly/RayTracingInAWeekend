/**
 * @file Vec3_Utility.hpp
 * @Brief Vec3_Utility functions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#ifndef _VEC3_UTILITY_HPP_
#define _VEC3_UTILITY_HPP_
#include "Vec3.hpp"

inline std::ostream &operator<<(std::ostream &out, Vec3 const &v) ;
inline Vec3 operator+(Vec3 const &u, Vec3 const v) ;
inline Vec3 operator-(Vec3 const &u, Vec3 const v) ;
inline Vec3 operator*(Vec3 const &u, Vec3 const v) ;
inline Vec3 operator*(double t, Vec3 const v) ;
inline Vec3 operator*(Vec3 const &v, double t) ;
inline Vec3 operator/(Vec3 v, double t) ;
inline double dot(Vec3 const &u, Vec3 const &v) ;
inline Vec3 cross(Vec3 const &u, Vec3 const &v) ;
inline Vec3 unit_vector(Vec3 v) ;

#endif /*_VEC3_UTILITY_HPP_ */
