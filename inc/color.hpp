/**
 * @file color.hpp
 * @brief Color Utility Functions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.1
 * @date 2022-10-02
 */
#ifndef _COLOR_HPP_
#define _COLOR_HPP_
#include "Vec3.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief			- Write a color to the std output
 *
 * @param out			- The std output
 * @param pixel_color		- Color ray returned
 * @param samples_per_pixel	- Samples of a pixel taken
 */
/* ------------------------------------------------------------------------------------*/
void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) ;		///< Writes color to output stream

#endif /* _COLOR_HPP_ */
