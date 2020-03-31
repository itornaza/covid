#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

#include "covid.h"

void print_menu() {
  std::cout << "\n*** Supported countries menu ***\n"
            << "*\n"
            << "* 1.  France\n"
            << "* 2.  Germany\n"
            << "* 3.  Greece\n"
            << "* 4.  Italy\n"
            << "* 5.  Netherlands\n"
            << "* 6.  Norway\n"
            << "* 7.  South Korea\n"
            << "* 8.  Spain\n"
            << "* 9.  Sweden\n"
            << "* 10. Switzerland\n"
            << "* 11. UK\n"
            << "* 12. USA\n"
            << "***\n"
            << "\n> Select which countries to plot: (ex. 1 4 6): ";
}

std::string generate_country_command(std::string country, std::string start_day,
                                     std::string end_day, float population = 1.0) {
  std::string cmd;
  cmd.append("\"<(sed -n '");
  cmd.append(start_day);
  cmd.append(",");
  cmd.append(end_day);
  cmd.append("p' ../data/");
  cmd.append(country);
  cmd.append(".txt)\" using ($1):($2 /");
  cmd.append(std::to_string(population));
  cmd.append(") with lines lw 3 title \"");
  country[0] = toupper(country[0]);
  cmd.append(country);
  cmd.append("\", \\\n");
  return cmd;
}

void generate_plot_command(std::string start_day, std::string end_day, float w_pop) {
  std::string cmd = "plot ";
  std::string input;
  
  /* Display supported countries menu */
  print_menu();
  
  /* Get the user selected countries */
  getline(std::cin, input);
  std::istringstream iss(input);
  std::vector<int> countries{std::istream_iterator<int>{iss},
                             std::istream_iterator<int>{}};
  
  /* Generate gnuplot command */
  for (auto &country : countries) {
    switch(country) {
      case Countries::france: {
        cmd.append(generate_country_command("france", start_day, end_day,
                                            (w_pop) ? france_pop : 1.0));
        break;
      }
      case Countries::germany: {
        cmd.append(generate_country_command("germany", start_day, end_day,
                                            (w_pop) ? germany_pop : 1.0));
        break;
      }
      case Countries::greece: {
        cmd.append(generate_country_command("greece", start_day, end_day,
                                            (w_pop) ? greece_pop : 1.0));
        break;
      }
      case Countries::italy: {
        cmd.append(generate_country_command("italy", start_day, end_day,
                                            (w_pop) ? italy_pop : 1.0));
        break;
      }
      case Countries::netherlands: {
        cmd.append(generate_country_command("netherlands", start_day, end_day,
                                            (w_pop) ? netherlands_pop : 1.0));
        break;
      }
      case Countries::norway: {
        cmd.append(generate_country_command("norway", start_day, end_day,
                                            (w_pop) ? norway_pop : 1.0));
        break;
      }
      case Countries::south_korea: {
        cmd.append(generate_country_command("south_korea", start_day, end_day,
                                            (w_pop) ? south_korea_pop : 1.0));
        break;
      }
      case Countries::spain: {
        cmd.append(generate_country_command("spain", start_day, end_day,
                                            (w_pop) ? spain_pop : 1.0));
        break;
      }
      case Countries::sweden: {
        cmd.append(generate_country_command("sweden", start_day, end_day,
                                            (w_pop) ? sweden_pop : 1.0));
        break;
      }
      case Countries::switzerland: {
        cmd.append(generate_country_command("switzerland", start_day, end_day,
                                            (w_pop) ? switzerland_pop : 1.0));
        break;
      }
      case Countries::uk: {
        cmd.append(generate_country_command("uk", start_day, end_day,
                                            (w_pop) ? uk_pop : 1.0));
        break;
      }
      case Countries::usa: {
        cmd.append(generate_country_command("usa", start_day, end_day,
                                            (w_pop) ? usa_pop : 1.0));
        break;
      }
      default: {
        printf("Invalid number\n");
        break;
      }
    }
  }
  
  /* Delete the last comma and backslash */
  if (!cmd.empty()) {
    cmd.pop_back();
    cmd.pop_back();
    cmd.pop_back();
    cmd.pop_back();
  }
  
  /* Print resulting command to the terminal */
  std::cout << cmd << std::endl;
}

int main(int argc, char** argv) {
  if (argc != 3 && argc != 4) {
    printf("Usage: ./covid <start_day> <end_day> <-p>\n");
    exit(1);
  }
  
  if (argc == 3) {
    generate_plot_command(argv[1], argv[2], 0);
  } else if (argc == 4 && !strcmp(argv[3], "-p")) {
    generate_plot_command(argv[1], argv[2], 1);
  }
  
  return 0;
}
