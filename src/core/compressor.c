#include "compressor.h"
#include <stdio.h>

//implement the function files declaration
#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

#define READ "rb"
#define WRITE "wb"
#define DESIRED_CHANNELS 0


bool compress_image(const char* file_path, int quality) {
    //define data image variables
    int width, height, channels_in_file;
    //reads the image and gets the size
    unsigned char* uncompress_image = stbi_load(file_path, &width, &height, &channels_in_file, DESIRED_CHANNELS);
    //check if the file could be opened
    if (uncompress_image == NULL) {
        return false;
    }
    //apply the compress process in the image
    int compression = stbi_write_jpg(file_path, width, height, channels_in_file, uncompress_image, quality);
    //close the file
    stbi_image_free(uncompress_image);
    //check if the process on the image results well
    if (compression <= 0) {
        return false;
    }
    return true;
}