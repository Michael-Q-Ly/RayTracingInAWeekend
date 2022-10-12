/**
 * @file main.cpp
 * @Brief main program
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.2
 * @date 2022-10-02
 */
#include "rtweekend.hpp"

#include "Camera.hpp"
#include "color.hpp"
#include "Hittable_List.hpp"
#include "Sphere.hpp"

#include <iostream>

static color ray_color(Ray const &r, Hittable const &world, int depth) ;

int main(int argc, char *argv[]) {

	/*-----------------------------------------------------------------------------
	 * Image 
	 *-----------------------------------------------------------------------------*/
	auto const aspect_ratio     = 16.0 / 9.0 ;
	int const image_width       = 2560 ;
	int const image_height      = static_cast<int>(image_width/aspect_ratio) ;
	int const samples_per_pixel = 100 ;
	int const max_depth         = 50 ;

	/*-----------------------------------------------------------------------------
	 * World 
	 *-----------------------------------------------------------------------------*/
	Hittable_List world ;
	world.add(std::make_shared<Sphere>(point3(0, 0, -1), 0.5)) ;
	world.add(std::make_shared<Sphere>(point3(0, -100.5, -1), 100)) ;

	/*-----------------------------------------------------------------------------
	 * Camera 
	 *-----------------------------------------------------------------------------*/
	Camera cam ;

	/*-----------------------------------------------------------------------------
	 * Render 
	 *-----------------------------------------------------------------------------*/

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j {image_height-1}; j >= 0; j--) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush ;
		for (int i {0}; i < image_width; i++) {
			color pixel_color(0, 0, 0) ;
			for (int s {0} ; s < samples_per_pixel ; s++) {
				auto u       = (i + random_double()) / (image_width-1) ;
				auto v       = (j + random_double()) / (image_height-1) ;
				Ray r        = cam.get_ray(u, v) ;
				pixel_color += ray_color(r, world, max_depth) ;
			}
			write_color(std::cout, pixel_color, samples_per_pixel) ;
        }
    }
	std::cerr << "\nDone." << std::endl ;
}


/*-----------------------------------------------------------------------------
 * Functions 
 *-----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
/**
 * @Brief		- Traces a color ray
 *
 * @Param r		- The color ray
 *
 * @Returns color	- Returns a color (Vec3 obj)
 *
 * @Notes		- 1. Calculates ray from cam eye to pixel
 *			\2. Determines which objects the ray intersects
 *			\3. Computes a color for that intersection point
 *			\We need to ignore hits very close to zero and use 0.001
 *			\to get ride of shadow acne problem
 */
/* ------------------------------------------------------------------------------------*/
static color ray_color(Ray const &r, Hittable const &world, int depth) {
	hit_record rec ;

	// If we've exceeded the ray bounce limit, no more light is gathered
	if (depth <= 0) {
		return color(0, 0, 0)  ;
	}

	if (world.hit(r, 0.001, infinity, rec)) {
		// Add dithering to the target
		point3 target = rec.p + rec.normal + random_in_hemisphere(rec.normal) ;
		return 0.5 * ray_color(Ray(rec.p, target - rec.p), world, depth-1) ;
	}

	Vec3 unit_direction = unit_vector(r.direction()) ;
	auto t = 0.5 * (unit_direction.y() + 1.0) ;
	// Return a lerp (linear interpolation), which is always of form
	// blendedValue = (1-t) * startValue + (t*endValue)
	return (1.0 - t) * color(1.0, 1.0, 1.0) + (t * color(0.5, 0.7, 1.0)) ;
}
