/**
 * @file Hittable_List.cpp
 * @Brief Hittable List class definitions
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 *
 * @Note Stores a list of Hittable objects
 */
#include "Hittable_List.hpp"

/* ----------------------------------------------------------------------------*/
/**
 * @Brief			- Overloaded Hittable_List constructor that calls its add method for initialization
 *
 * @Param object		- Hittable object to add to objects class member
 */
/* ------------------------------------------------------------------------------------*/
Hittable_List::Hittable_List(std::shared_ptr<Hittable> object) {
	add(object) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief			- Adds a Hittable object to a vector of sharead pointers
 *
 * @Param object		- Hittable object to add to objects class member
 */
/* ------------------------------------------------------------------------------------*/
void Hittable_List::add(std::shared_ptr<Hittable> object) {
	objects.push_back(object) ;
}

/* ----------------------------------------------------------------------------*/
/**
 * @Brief			- Checks object hit records to see if anything was hit
 *
 * @Param r			- Ray object
 * @Param t_min			- Min t value
 * @Param t_max			- Max t value
 * @Param rec			- Object's hit record
 *
 * @Returns bool		- Did object records hit anything?
 *
 * @Notes			- Steps through each object so that we use recursion and eventually unroll
 *				- hit_record is a struct
 */
/* ------------------------------------------------------------------------------------*/
bool Hittable_List::hit(Ray const &r, double t_min, double t_max, hit_record &rec) const {
	hit_record temp_rec ;
	bool hit_anything   = false ;
	auto closest_so_far = t_max ;

	for (auto const &object : objects) {
		if (object->hit(r, t_min, closest_so_far, temp_rec)) {
			hit_anything   = true ;
			closest_so_far = temp_rec.t ;
			rec            = temp_rec ;
		}
	}

	return hit_anything ;
}
