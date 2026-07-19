#include "../processor/image_processor.hpp"
#include <string>
#include <iostream>

int main() {
    ImageProcessor image_processor;
    std::string images_directory = "../src/tests/images";
    int quality = 100;

    std::cout << "starting image compression test" << std::endl;

    if (image_processor.process_directory(images_directory, quality)) {
        std::cout << "every image compressed successful" << std::endl;
    }
    else {
        std::cout << "something has been wrong" << std::endl;
    }

    return 0;
}