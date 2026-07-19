#pragma once
#include <string>
#include <vector>
#include <filesystem>

class ImageProcessor {
public:
    //principal class method that gets the directory path and quality and starts the compression process
    bool process_directory(const std::string& directory_path, int quality);
private:
    //saves the images into a vector from the directory referenced on the parameters
    std::vector<std::filesystem::path> get_images_from_directory(const std::string& directory_path);
    //compress the image
    bool compress_single_image(const std::filesystem::path& file_path, int quality);
};