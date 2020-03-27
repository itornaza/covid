#covid

A simple cpp program that generates the gnuplot command that is needed to plot the country curves at the same scale for direct comparisson.

An analysis for the resulted plots and how they can be used can be found at my [article](https://medium.com/@itornaza/covid-19-comparative-casualties-plot-7c25ac5412d9) on medium.

## Dependencies for running locally
* cmake >= 3.11
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* gnuplot >= 5.2.8
  * Linux: sudo apt-get install -y gnuplot
  * Mac: brew install gnuplot
  * Windows: [install-gnuplot-on-windows](https://stackoverflow.com/questions/47453376/how-to-install-gnuplot-on-windows)

## Basic build instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./covid <start_day> <end_day>`
5. Run gnuplot from within the build directory: `gnuplot`
6. Paste the result of the program to the gnuplot prompt.

