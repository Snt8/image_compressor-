#include "image_processor.hpp"
#include "../core/compressor.h"
#include <filesystem>

std::vector<std::filesystem::path> ImageProcessor::get_images_from_directory(const std::string& directory_path) {
    //inicializate an empty vector for the images and the directory path
    std::vector<std::filesystem::path> images;
    std::filesystem::path path(directory_path);
    //check if the path exists and if it is a directory
    if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path)) {
        return images;
    }
    //iterate in the directory to check the files
    for (const auto& entry: std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            auto extension = entry.path().extension().string();
            //apply lower format on extension
            for (char& character : extension) {
                character = static_cast<char>(std::tolower(character));
            }
            //check if the extension is allowed for the system
            if (extension == ".png" || extension == ".jpg" || extension == ".jpeg") {
                images.push_back(entry.path());
            }
        }
    }

    return images;
}

bool ImageProcessor::compress_single_image(const std::filesystem::path& file_path, int quality) {
    //cast the data type to string
    std::string file = file_path.string();
    //call the compressing function
    bool status = compress_image(file.c_str(), quality);
    //return the process result
    return status;
}

bool ImageProcessor::process_directory(const std::string& directory_path, int quality) {
    //build the images path vector
    std::vector<std::filesystem::path> images = get_images_from_directory(directory_path);
    bool all_successful = true;
    //check if the directory is not empty
    if (images.empty()) {
        return false;
    }
    //iterate the vector and compress every single image
    for (const auto& image : images) {
        bool status = compress_single_image(image, quality);
        if (!status) {
            all_successful = false;
        }
    }

    return all_successful;
}