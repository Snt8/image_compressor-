#include "../core/compressor.h"
#include "../processor/image_processor.hpp"
#include <string>
#include <iostream>

int main() {
    std::string image = "../src/tests/images/new_york_test_image.jpg";
    int quality = 50;

    if (compress_image(image.c_str(), quality)) {
        std::cout << "The image was compressed successful";
    }

    else {
        std::cout << "Error compressing the image";
    }
}