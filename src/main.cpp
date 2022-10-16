/**
 * @file main.cpp
 * @brief main program
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 1.0.0
 * @date 2022-10-02
 */
#include "rtweekend.hpp"

#include "Camera.hpp"
#include "color.hpp"
#include "Hittable_List.hpp"
#include "Material.hpp"
#include "Sphere.hpp"

#include <iostream>

static color ray_color(Ray const &r, Hittable const &world, int depth) ;
static Hittable_List random_scene(void) ;

int main(int argc, char *argv[]) {

	/*-----------------------------------------------------------------------------
	 * Image 
	 *-----------------------------------------------------------------------------*/
	auto const aspect_ratio     = 16.0 / 9.0 ;
	int const image_width       = 2560 ;
	int const image_height      = static_cast<int>(image_width/aspect_ratio) ;
	int const samples_per_pixel = 500 ;
	int const max_depth         = 50 ;

	/*-----------------------------------------------------------------------------
	 * World 
	 *-----------------------------------------------------------------------------*/
	auto world = random_scene() ;

	/*-----------------------------------------------------------------------------
	 * Camera 
	 *-----------------------------------------------------------------------------*/
	// Create a point to look at an image from a certain height
	point3 look_from(13, 2, 3) ;
	point3 look_at(0, 0, 0) ;
	Vec3 v_up(0, 1, 0) ;
	// The distance from projection point and the plane where everything is in focus is the focus distance (focal length)
	auto dist_to_focus = 10.0 ;
	// Aperture is a hole to control how big the lens is effectively. The bigger the aperture, the more light comes in and the more defoucs blur we get
	auto aperture = 0.1 ;

	Camera cam(look_from, look_at, v_up, 20, aspect_ratio, aperture, dist_to_focus) ;

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
 * @brief		- Traces a color ray
 *
 * @param r		- The color ray
 *
 * @returns color	- Returns a color (Vec3 obj)
 *
 * @notes		- 1. Calculates ray from cam eye to pixel
 *			  2. Determines which objects the ray intersects
 *			  3. Computes a color for that intersection point
 *			  We need to ignore hits very close to zero and use 0.001
 *			  to get ride of shadow acne problem
 */
/* ------------------------------------------------------------------------------------*/
static color ray_color(Ray const &r, Hittable const &world, int depth) {
	hit_record rec ;

	// If we've exceeded the ray bounce limit, no more light is gathered
	if (depth <= 0) {
		return color(0, 0, 0)  ;
	}

	if (world.hit(r, 0.001, infinity, rec)) {
		Ray scattered ;
		color attenuation ;
		if (rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
			return attenuation * ray_color(scattered, world, depth-1) ;
		}
		return color(0, 0, 0) ;
	}

	Vec3 unit_direction = unit_vector(r.direction()) ;
	auto t = 0.5 * (unit_direction.y() + 1.0) ;
	// Return a lerp (linear interpolation), which is always of form
	// blendedValue = (1-t) * startValue + (t*endValue)
	return (1.0 - t) * color(1.0, 1.0, 1.0) + (t * color(0.5, 0.7, 1.0)) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @brief			- Create a random scene of hittable objects
 *
 * @return Hittable_List	- A list of hittable objects ; the world / scene to be shown
 */
/* ------------------------------------------------------------------------------------*/
static Hittable_List random_scene(void) {
	Hittable_List world ;

	// Create the ground in which all the objects sit
	auto ground_material = std::make_shared<Lambertian>(color(0.5, 0.5, 0.5)) ;
	world.add(std::make_shared<Sphere>(point3(0, -1000, 0), 1000, ground_material)) ;

	// Create many random objects to sit on the ground
	for (int a = -11 ; a < 11 ; a++) {
		for (int b = -11 ; b < 11 ; b++) {
			auto choose_mat = random_double() ;
			point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double()) ;

			if ((center - point3(4, 0.2, 0)).length() > 0.9) {
				std::shared_ptr<Material> sphere_material ;
				if (choose_mat < 0.8 ) {
					// Diffuse
					auto albedo     = color::random() * color::random() ;
					sphere_material = std::make_shared<Lambertian>(albedo) ;
					world.add(std::make_shared<Sphere>(center, 0.2, sphere_material)) ;
				}
				else if (choose_mat < 0.95) {
					// Metal
					auto albedo     = color::random(0.5, 1) ;
					auto fuzz       = random_double(0, 0.5) ;
					sphere_material = std::make_shared<Metal>(albedo, fuzz) ;
					world.add(std::make_shared<Sphere>(center, 0.2, sphere_material)) ;
				}
				else {
					// Glass
					sphere_material = std::make_shared<Dielectric>(1.5) ;
					world.add(std::make_shared<Sphere>(center, 0.2, sphere_material)) ;
				} /* End inner if */
			}
		} /* End inner for loop */
	}

	// Add 3 main objects of Dielectric, Lambertian, and Metal material
	auto material1 = std::make_shared<Dielectric>(1.5) ;
	world.add(std::make_shared<Sphere>(point3(0, 1, 0), 1.0, material1)) ;

	auto material2 = std::make_shared<Lambertian>(color(0.4, 0.2, 0.1)) ;
	world.add(std::make_shared<Sphere>(point3(-4, 1, 0), 1.0, material2)) ;

	auto material3 = std::make_shared<Metal>(color(0.7, 0.6, 0.5), 0.0) ;
	world.add(std::make_shared<Sphere>(point3(4, 1, 0), 1.0, material3)) ;

	return world ;
}
