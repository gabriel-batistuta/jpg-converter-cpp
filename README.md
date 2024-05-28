# Image Converter

this software **transforms a jpg image into png** using c++ libraries

# Using

## download dependencie

```bash
# used for compare the diference betwen the images
sudo apt-get install imagemagick
```

## Compile
```bash
g++ -o image_converter main.cpp lodepng.cpp -ljpeg
```
## Running
```bash
./image_converter input.jpg output.png
```

# Result
Please see the result <a href="https://gabriel-batistuta.github.io/jpg-converter-cpp">here</a>