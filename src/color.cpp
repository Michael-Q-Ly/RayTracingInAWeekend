/**
 * @file color.cpp
 * @brief Color utility definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.1
 * @date 2022-10-02
 */
#include "rtweekend.hpp"
#include "color.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @brief			- Writes color to output stream
 *
 * @param out			- The output steam
 * @param pixel_color		- The pixel color to be outputted
 */
/* ------------------------------------------------------------------------------------*/
void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
	auto r = pixel_color.x() ;
	auto g = pixel_color.y() ;
	auto b = pixel_color.z() ;

	// Divide the color by the number of samples and gamma-correct for gamma=2.0
	auto scale = 1.0 / samples_per_pixel ;
	r = std::sqrt(scale * r) ;
	g = std::sqrt(scale * g) ;
	b = std::sqrt(scale * b) ;

        // Write the translated [0,255] value of each color component
        out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
            << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << std::endl ;
}
