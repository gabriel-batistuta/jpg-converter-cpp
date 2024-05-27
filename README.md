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

<style>
.image-container {
  position: relative;
}

.minor_caption {
    position: relative;
    bottom: 0;
    left: 0;
    width: calc(100% / 2);
    background-color: rgba(0, 0, 0, 0.5);
    color: white;
    padding: 10px;
    text-align: center;
}

.minor_caption::before,
.minor_caption::after {
    content: '';
    position: absolute;
    top: 50%;
    width: 0;
    height: 0;
    border-style: solid;
}

.minor_caption::before {
    right: 100%;
    margin-top: -10px;
    border-width: 10px;
    border-color: transparent transparent transparent rgba(0, 0, 0, 0.5);
}

.minor_caption::after {
    right: calc(100% - 20px);
    margin-top: -10px;
    border-width: 10px;
    border-color: transparent transparent transparent rgba(0, 0, 0, 0);
}


.caption {
  position: absolute;
  bottom: 0;
  left: 0;
  width: 94%;
  background-color: rgba(0, 0, 0, 0.5);
  color: white;
  padding: 10px;
  text-align: center;
}

</style>
