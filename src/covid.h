#ifndef ION_COVID_H_
#define ION_COVID_H_

#include <string>

// Types
enum Countries {
  france = 1,
  germany,
  greece,
  italy,
  netherlands,
  norway,
  south_korea,
  spain,
  sweden,
  switzerland,
  uk,
  usa
};

// Constants
static float france_pop = 66.99;
static float germany_pop = 82.79;
static float greece_pop = 10.74;
static float italy_pop = 60.48;
static float netherlands_pop = 17.18;
static float norway_pop = 5.368;
static float south_korea_pop = 51.47;
static float spain_pop = 46.66;
static float sweden_pop = 10.12;
static float switzerland_pop = 8.57;
static float uk_pop = 66.44;
static float usa_pop = 327.2;

// Function prototypes
void print_menu();
void print_zero_to_lock();
std::string generate_country_command(std::string, std::string, std::string,
                                     float pop);
void generate_plot_command(int, int, bool);

#endif /* # ION_COVID_H_ */
