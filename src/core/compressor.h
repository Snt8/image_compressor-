#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
    bool compress_image(const char* image_path, int quality);

#ifdef __cplusplus
}
#endif