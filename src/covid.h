#ifndef ION_COVID_H_
#define ION_COVID_H_

#include <ctime>
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

// Function prototypes
void print_menu();
void print_zero_to_lock();
std::string generate_country_command(std::string, std::string, std::string);
void generate_plot_command(int, int);

#endif /* # ION_COVID_H_ */
