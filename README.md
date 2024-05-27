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
<link rel="stylesheet" type="text/css" href="assets/styles.css">
<div style="display: flex; justify-content: space-between;">
    <div class="image-container">
        <img src="assets/input.jpg" alt="input.jpg" style="width: 40vw;"/>
        <p class="caption">jpg</p>
    </div>
    <div class="image-container">
        <img src="assets/output.png" alt="output.jpg" style="width: 40vw;"/>
        <p class="caption">png</p>
    </div>
</div>
<div class="image-container" style="display: flex; justify-content: center; align-items: center; margin-top: 6px;">
    <img src="assets/difference.png" alt="output.jpg" style="width: 50%; height: 50%;"/>
    <p class="minor_caption">image differencies</p>
</div>