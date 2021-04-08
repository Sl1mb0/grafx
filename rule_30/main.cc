#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "rule.h"

#include <iostream>

int main() {

    const int image_width = 256;
    const int image_height = 256;

    rule image(image_width, image_height);
    image.rule30();

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int i = image_height - 1; i >= 0; --i){
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for(int j = 0; j < image_width; ++j){
            if(image.array[i][j]) {
	        color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1), 0.25);
		write_color(std::cout, pixel_color);
	    }
            else {
	        color pixel_color(0, 0, 0);
	        write_color(std::cout, pixel_color);
            }
	}
    }

    std::cerr << "\nDone.\n";
}
