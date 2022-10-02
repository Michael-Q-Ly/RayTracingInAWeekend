/**
 * @file color.cpp
 * @Brief Color utility definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-02
 */
#include "color.hpp"

void write_color(std::ostream &out, color pixel_color) {
        // Write the translated [0,255] value of each color component
        out << static_cast<int>(255.999 * pixel_color.x()) << ' '
            << static_cast<int>(255.999 * pixel_color.y()) << ' '
            << static_cast<int>(255.999 * pixel_color.z()) << ' '
            << std::endl ;
}
