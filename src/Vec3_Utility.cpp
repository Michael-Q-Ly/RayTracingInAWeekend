#include "Vec3_Utility.hpp"

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
inline Vec3 operator+(Vec3 const &u, Vec3 const v) {
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
inline Vec3 operator-(Vec3 const &u, Vec3 const v) {
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
inline Vec3 operator*(Vec3 const &u, Vec3 const v) {
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
inline Vec3 operator*(double t, Vec3 const v) {
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