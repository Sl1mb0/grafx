#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

color ray_color(const ray &r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

   // Image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int i = image_height - 1; i >= 0; --i){
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for(int j = 0; j < image_width; ++j){
	    color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1), 0.25);
	    write_color(std::cout, pixel_color);
	}
    }

    std::cerr << "\nDone.\n";
}
