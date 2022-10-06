/**
 * @file color.cpp
 * @Brief Color utility definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#include "color.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @Brief			- Writes color to output stream
 *
 * @Param out			- The output steam
 * @Param pixel_color		- The pixel color to be outputted
 */
/* ------------------------------------------------------------------------------------*/
void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
	auto r = pixel_color.x() ;
	auto g = pixel_color.y() ;
	auto b = pixel_color.z() ;

	// Divide the color by the number of samples
	r *= scale ;
	g *= scale ;
	b *= scale ;

        // Write the translated [0,255] value of each color component
        out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << std::endl ;
}
