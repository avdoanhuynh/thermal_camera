# thermal_camera

# I2C Configuration
Source: https://learn.sparkfun.com/tutorials/raspberry-pi-spi-and-i2c-tutorial/all

Use the Desktop GUI by heading to the Pi Start Menu > Preferences > Raspberry Pi Configuration > Interfaces tab. > Select Enable for I2C > OK.
You might need to restart the Raspberry Pi

# Connect MLX90640 to Raspberry Pi
## Pin:
VCC: Pin 2 (5V)
SDA: Pin 3
SCL: Pin 5
GND: Pin 9

## Test
In Terminal:

    sudo apt-get install i2c-tools
    i2cdetect -y 1

It should be showing this output:

    00: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    30: -- -- -- -- 33 -- -- -- -- -- -- -- -- -- -- --
    40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
    70: -- -- -- -- -- -- -- --

    
# MLX90640-library
MLX90640 library functions
Source: https://github.com/pimoroni/mlx90640-library

## Raspberry Pi Users

** EXPERIMENTAL **

This port uses either generic Linux I2C or the  bcm2835 library.
Upon building, the mode is set with the I2C_MODE property, i.e. `make I2C_MODE=LINUX` or `make I2C_MODE=RPI`. The default is LINUX, without the need for the bcm2835 library or root access.

### Generic Linux I2C Mode

Make sure the Linux I2C dev library is installed:

```text
sudo apt-get install libi2c-dev
```

To get the best out of your sensor you should modify `/boot/config.txt` and change your I2C baudrate.

The fastest rate recommended for compatibility with other sensors is 400kHz. This is compatible with SMBus devices:

```text
dtparam=i2c1_baudrate=400000
```

This will give you a framerate of - at most - 8FPS.

If you're just using the MLX90640 and, for example, the 1.12" OLED, you can safely use 1MHz:

```text
dtparam=i2c1_baudrate=1000000
```

This will give you a framerate of - at most - 32FPS.

Now build the MLX90640 library and examples in LINUX I2C mode:

```text
make clean
make I2C_MODE=LINUX
```

### BCM2835 Library Mode

To use the bcm2835 library, install like so:


```text
make bcm2835
```

Or, step by step:

```text
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.55.tar.gz
tar xvfz bcm2835-1.55.tar.gz
cd bcm2835-1.55
./configure
make
sudo make install
```

### Dependencies

libav for `video` example:

```text
sudo apt-get install libavutil-dev libavcodec-dev libavformat-dev
```

SDL2 for `sdlscale` example:

```text
sudo apt install libsdl2-dev
```

# Building

After installing the dependencies, you can build the library. Build-modes are:

* `make` or `make all`: build the library and all dependencies. Default is to use standard linux I2C-Drivers, specify Raspberry Pi driver with `make I2C_MODE=RPI`
* `make examples`: only build examples, see below
* `sudo make install`: install libraries and headers into `$PREFIX`, default is `/usr/local`

Afterwards you can run the examples or build the python binding, see readme in the subfolder.
If you built the examples or library using the native bcm2835 I2C-Driver, you need to run all applications and examples as root.
Hence, `sudo examples/<exampleame>` for one of the examples listed below, or without `sudo` when using the standard Linux driver.

# Examples
## fbuf

```
make examples/fbuf
sudo examples/fbuf
```

This example uses direct-to-framebuffer rendering and black-blue-green-yellow-red-purple-white false colouring.

If you gave issues with the output image, set "`IMAGE_SCALE`" to a smaller number.

## interp

```
make examples/interp
sudo examples/interp
```

This example uses direct-to-framebuffer rendering and black-blue-green-yellow-red-purple-white false colouring.

It also has 2x bicubic resize filter.

If you have issues with the output image, set "`IMAGE_SCALE`" to a smaller number.

## test

```
make examples/test
sudo examples/test
```

This example draws out to the console using ANSI colours and the full block char.

To see the actual temperature values, change "`FMT_STRING`" from the block char to the float format.

## step

```
make examples/step
sudo examples/step
```

Attempt to run in step by step mode (experimental)

## sdlscale

Displays the MLX90640 sensor full-screen using hardware acceleration in SDL2.

Hit Spacebar to change from aspect-ratio correct to full-screen-stretched modes.

Hit Escape to exit.

```
make examples/sdlscale
sudo examples/sdlscale
```

Requires SDL2 libraries:

```
sudo apt install libsdl2-dev
```

On Raspbian Lite you may wish to build SDL2 from source with X support disabled to avoid pulling in ~200MB of dependencies. Before configuring/compiling ensure you have `libudev-dev` installed for input support.

# OpenCV

## Installation
Source: https://www.learnopencv.com/install-opencv-4-on-raspberry-pi/

### Select OpenCV version to install

    sudo apt-get -y purge wolfram-engine
    sudo apt-get -y purge libreoffice*
    sudo apt-get -y clean
    sudo apt-get -y autoremove
    
    echo "OpenCV installation by learnOpenCV.com"
    cvVersion="master"
    
We are also going to clean build directories and create installation directory.

    #Clean build directories
    rm -rf opencv/build
    rm -rf opencv_contrib/build

    #Create directory for installation
    mkdir installation
    mkdir installation/OpenCV-"$cvVersion"

Finally, we will be storing the current working directory in cwd variable. We are also going to refer to this directory as OpenCV_Home_Dir throughout this blog.

    #Save current working directory
    cwd=$(pwd)

### Update Packages

    sudo apt -y update
    sudo apt -y upgrade
    
### Install OS Libraries

    sudo apt-get -y remove x264 libx264-dev

    ## Install dependencies
    sudo apt-get -y install build-essential checkinstall cmake pkg-config yasm
    sudo apt-get -y install git gfortran
    sudo apt-get -y install libjpeg8-dev libjasper-dev libpng12-dev

    sudo apt-get -y install libtiff5-dev

    sudo apt-get -y install libtiff-dev

    sudo apt-get -y install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev

    sudo apt-get -y install libxine2-dev libv4l-dev
    cd /usr/include/linux
    sudo ln -s -f ../libv4l1-videodev.h videodev.h
    cd $cwd

    sudo apt-get -y install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
    sudo apt-get -y install libgtk2.0-dev libtbb-dev qt5-default
    sudo apt-get -y install libatlas-base-dev
    sudo apt-get -y install libmp3lame-dev libtheora-dev
    sudo apt-get -y install libvorbis-dev libxvidcore-dev libx264-dev
    sudo apt-get -y install libopencore-amrnb-dev libopencore-amrwb-dev
    sudo apt-get -y install libavresample-dev
    sudo apt-get -y install x264 v4l-utils

    #Optional dependencies

    sudo apt-get -y install libprotobuf-dev protobuf-compiler
    sudo apt-get -y install libgoogle-glog-dev libgflags-dev
    sudo apt-get -y install libgphoto2-dev libeigen3-dev libhdf5-dev doxygen

### Install Python Libraries

    sudo apt-get -y install python3-dev python3-pip
    sudo -H pip3 install -U pip numpy
    sudo apt-get -y install python3-testresources
    
We are also going to install virtualenv and virtualenvwrapper modules to create Python virtual environments.

    cd $cwd
    # Install virtual environment
    python3 -m venv OpenCV-"$cvVersion"-py3
    echo "# Virtual Environment Wrapper" >> ~/.bashrc
    echo "alias workoncv-$cvVersion=\"source $cwd/OpenCV-$cvVersion-py3/bin/activate\"" >> ~/.bashrc
    source "$cwd"/OpenCV-"$cvVersion"-py3/bin/activate
    #############

Next, we create the Python virtual environment.

    ############ For Python 3 ############
    # now install python libraries within this virtual environment
    sudo sed -i 's/CONF_SWAPSIZE=100/CONF_SWAPSIZE=1024/g' /etc/dphys-swapfile
    sudo /etc/init.d/dphys-swapfile stop
    sudo /etc/init.d/dphys-swapfile start
    pip install numpy dlib
    # quit virtual environment
    deactivate

### Download opencv and opencv_contrib

    git clone https://github.com/opencv/opencv.git
    cd opencv
    git checkout $cvVersion
    cd ..

    git clone https://github.com/opencv/opencv_contrib.git
    cd opencv_contrib
    git checkout $cvVersion
    cd ..

### Compile and install OpenCV with contrib modules
First we navigate to the build directory.

    cd opencv
    mkdir build
    cd build

Next, we start the compilation and installation process.


    cmake -D CMAKE_BUILD_TYPE=RELEASE \
                -D
    CMAKE_INSTALL_PREFIX=$cwd/installation/OpenCV-"$cvVersion" \
                    -D INSTALL_C_EXAMPLES=ON \
                    -D INSTALL_PYTHON_EXAMPLES=ON \
                    -D WITH_TBB=ON \
                    -D WITH_V4L=ON \
                    -D OPENCV_PYTHON3_INSTALL_PATH=$cwd/OpenCV-$cvVersion-py3/lib/python3.5/site-packages \
                    -D WITH_QT=ON \
                    -D WITH_OPENGL=ON \
                    -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
                    -D BUILD_EXAMPLES=ON ..

For system wide installation of OpenCV, change CMAKE_INSTALL_PREFIX to CMAKE_INSTALL_PREFIX=/usr/local \.

    make -j$(nproc)
    make install

### Reset swap file
Once we are done with installing heavy Python modules like Numpy, it’s time to reset the swap file.

    sudo sed -i 's/CONF_SWAPSIZE=1024/CONF_SWAPSIZE=100/g' /etc/dphys-swapfile
    sudo /etc/init.d/dphys-swapfile stop
    sudo /etc/init.d/dphys-swapfile start

Finally, we also need to add a simple statement to make sure that VideoCapture(0) works on our Raspberry Pi.

    echo "sudo modprobe bcm2835-v4l2" >> ~/.profile

### Install the development package as:

    sudo apt install libopencv-dev

## Configuration

Add change to .cpp file
    
    #include "opencv2/opencv.hpp"

    using namespace cv;
    using namespace std;

Make additions to the makefile.txt
   
    CPPFLAGS = `pkg-config --cflags opencv`
    LDLIBS = `pkg-config --libs opencv`
    
and $(I2C_LIBS) $(CPPFLAGS to the following command:
   
    fbuf: examples/fbuf.o examples/lib/fb.o libMLX90640_API.a
    $(CXX) -L/home/pi/mlx90640-library $^ -o $@ $(I2C_LIBS) $(CPPFLAGS) $(LDLIBS)
    
# Qt - Graphical User Interface
## Installation:

    sudo apt-get install qt4-dev-tools
    sudo apt-get install qtcreator
    
## Problem when combine OpenCV and Qt:
    
    Error: “Gtk-ERROR **: GTK+ 2.x symbols detected. Using GTK+ 2.x and GTK+ 3 in the same process is not supported”

--> Solution 1: OpenCV with full support from gtk+3 when compiled (When run cmake, use Flag: WITH_GTK_2_X =OFF) 
--> Solution 2: Using another GUI-Style for QT (for examples: CDE, Window,…)
            
            #Im Terminal
            sudo apt-get install qt4-qtconfig
            qtconfig-qt4
            #Choose another GUI-Style
            
# Data transfer
## SSH/VNC Configuration

Use the Desktop GUI by heading to the Pi Start Menu > Preferences > Raspberry Pi Configuration > Interfaces tab. > Select Enable for SSH and/or VNC > OK.
You might need to restart the Raspberry Pi

## Application for Data transfer

There are many difference appications that you can install on your Computer / Laptop in order to do a data transfer between your Computer/Laptop and your Raspberry Pi
Ex.:     winscp (you can download it here: https://winscp.net/eng/download.php)   or
           vncviewer (download: https://www.realvnc.com/en/connect/download/viewer/ ), you will also need an account        for it (sign up here: https://www.realvnc.com/en/)

Most of these application will ask for the Raspberry Pi's IP-Address, Username and Password.

## How to find out your Raspberry Pi's IP-Address

Im Terminal, type:
    
    ifconfig

The IP-Address will be there, for ex.: 192.168.0.11

## Static IP
Source: https://www.ionos.com/digitalguide/server/configuration/provide-raspberry-pi-with-a-static-ip-address/

In some cases, when you do a lot of data transfer through SSH or VNC, you might need to set an static IP for your Raspberry Pi.

In Terminal:

    sudo nano /etc/dhcpcd.conf

You’ll now carry out the configuration of the static IP address. If your Raspberry Pi is connected to the internet via an Ethernet or network cable, then enter the command ‘interface eth0’; if it takes place over Wi-Fi, then use the ‘interface wlan’ command.

To assign an IP address to Raspberry Pi, use the command ‘static ip_address=’ followed by the desired IPv4 address and the suffix ‘/24’ (an abbreviation of the subnet mak 255.255.255.0). For example, if you want to link a computer with the IPv4 address 192.168.0.10, then you need to use the command ‘static ip_address=192.168.0.10/24’.

For ex.:

    interface eth0

    static ip_address=192.168.0.10/24
    static routers=192.168.0.1
    static domain_name_servers=8.8.8.8 208.67.222.222

    interface wlan

    static ip_address=192.168.0.200/24
    static routers=192.168.0.1
    static domain_name_servers=8.8.8.8 208.67.222.222

Save the file with Ctrl +X --> Y --> Enter

# Hide mouse cursor

Source: https://raspberrypi.stackexchange.com/questions/53127/how-to-permanently-hide-mouse-pointer-or-cursor-on-raspberry-pi

Im Terminal:
    
    sudo nano /etc/lightdm/lightdm.conf

Looking for the line that say:

    xserver-command = X

and change it to:

    xserver-command = X -nocursor

Save the file with Ctrl +X --> Y --> Enter and restart your Pi.

# Setting an application to automatically run at start up

Source: https://raspberry-projects.com/pi/pi-operating-systems/raspbian/auto-running-programs-gui

Im Terminal:

    sudo nano /etc/xdg/lxsession/LXDE-pi/autostart

 To run an application you simply add it on a line starting with a ‘@’ character and give the path to the executable file, which in this example is called “thermal_camera_app”:
 
    @/home/pi/projects/myfolder/thermal_camera_app
    
Save the file with Ctrl+X --> Y --> Enter and restart your Pi

 
