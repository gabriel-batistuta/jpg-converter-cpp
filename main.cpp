#include <iostream>
#include <fstream>
#include <vector>
#include <jpeglib.h>
#include "lodepng.h"
#include <cstdlib>

// Função para ler arquivo JPG
bool read_jpeg_file(const char *filename, std::vector<unsigned char> &image, unsigned &width, unsigned &height) {
    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        std::cerr << "Error opening JPEG file " << filename << std::endl;
        return false;
    }

    jpeg_decompress_struct cinfo;
    jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    width = cinfo.output_width;
    height = cinfo.output_height;
    unsigned row_stride = width * cinfo.output_components;

    image.resize(row_stride * height);
    while (cinfo.output_scanline < height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = &image[cinfo.output_scanline * row_stride];
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    jpeg_finish_decompress(&cinfo); // Removido o ponteiro
    jpeg_destroy_decompress(&cinfo); // Removido o ponteiro
    fclose(infile);
    return true;
}

// Função para salvar arquivo PNG
bool save_png_file(const char *filename, const std::vector<unsigned char> &image, unsigned width, unsigned height) {
    unsigned error = lodepng::encode(filename, image, width, height);
    if (error) {
        std::cerr << "Error encoding PNG file " << filename << ": " << lodepng_error_text(error) << std::endl;
        return false;
    }
    return true;
}

int compare() {
    const char* image1 = "input.jpg";
    const char* image2 = "output.png";
    const char* output = "difference.png";

    std::string command = "compare ";
    command += image1;
    command += " ";
    command += image2;
    command += " ";
    command += output;

    int result = system(command.c_str());

    std::cout << "Image comparison successful. Output saved to " << output << std::endl;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.jpg> <output.png>" << std::endl;
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    std::vector<unsigned char> image;
    unsigned width, height;

    if (!read_jpeg_file(input_filename, image, width, height)) {
        return 1;
    }

    // Converter RGB para RGBA adicionando canal alfa
    std::vector<unsigned char> image_rgba;
    image_rgba.reserve(width * height * 4);
    for (size_t i = 0; i < image.size(); i += 3) {
        image_rgba.push_back(image[i]);
        image_rgba.push_back(image[i + 1]);
        image_rgba.push_back(image[i + 2]);
        image_rgba.push_back(255); // Alpha
    }

    if (!save_png_file(output_filename, image_rgba, width, height)) {
        return 1;
    }

    std::cout << "Image converted successfully!" << std::endl;
    
    // salvando a diferença entre os dois
    compare();

    return 0;
}
