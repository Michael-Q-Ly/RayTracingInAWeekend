/**
 * @file Hittable_List.hpp
 * @Brief Hittable List class header
 * @author Michael Ly (github.com/Michael-Q-Ly)
 * @version 0.0.0
 * @date 2022-10-05
 */
#ifndef _HITTABLE_LIST_HPP_
#define _HITTABLE_LIST_HPP_
#include "Hittable.hpp"
#include <memory>
#include <vector>

class Hittable_List : public Hittable {
	public:
		Hittable_List(void) = default ;					///< No-args constructor
		Hittable_List(std::shared_ptr<Hittable> object) ;		///< Overloaded constructor

		void clear(void) ;						///< Clears Vector of Shared Pointers pointing to Hittable objects
		void add(std::shared_ptr<Hittable> object) ;			///< Adds to Vector of Shared Pointers pointing to Hittable objects

		virtual bool hit(Ray const &r, double t_min, double t_max, hit_record &rec) const override ;	///< Hit or not?
	
	public:
		std::vector<std::shared_ptr<Hittable>> objects ;		///< Vector of shared pointers pointing to Hittable objects
} ;

#endif /*  _HITTABLE_LIST_HPP_ */
