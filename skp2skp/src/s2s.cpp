#include <SketchUpAPI/SketchUp.h>
#include <iostream>
#include <string>
#include <exception>
#include <unordered_map>
#include <io.h>
#include "output_sketchup_error.h"

// #define SU_CALL(func) if ((func) != SU_ERROR_NONE) throw std::exception()

// Quick debugging
#define CHECK(r) if (r != SU_ERROR_NONE) { \
  std::cout << "SU Error line: " << __LINE__ << "\n"; \
  output_sketchup_error(r); return 1; }

#ifndef F_OK
#define F_OK 0
#define R_OK 4
#endif

void usage() {
  std::cout << "Usage:" << std::endl;
  std::cout << "  s2s version in_file outfile" << std::endl;
}

int main(int argc, char *argv[]) {

  if (argc != 4) {
    std::cout << "Wrong # of arguments, 3 required." << std::endl;
    usage();
    return EXIT_FAILURE;
  }

  std::string opt_version;
  std::string opt_input;
  std::string opt_output;

  opt_version = argv[1];
  opt_input = argv[2];
  opt_output = argv[3];

  std::unordered_map<std::string, SUModelVersion> version_table = {
    {"3", SUModelVersion_SU3},
    {"4", SUModelVersion_SU4},
    {"5", SUModelVersion_SU5},
    {"6", SUModelVersion_SU6},
    {"7", SUModelVersion_SU7},
    {"8", SUModelVersion_SU8},
    {"13", SUModelVersion_SU2013},
    {"2013", SUModelVersion_SU2013},
    {"14", SUModelVersion_SU2014},
    {"2014", SUModelVersion_SU2014},
    {"15", SUModelVersion_SU2015},
    {"2015", SUModelVersion_SU2015},
    {"16", SUModelVersion_SU2016},
    {"2016", SUModelVersion_SU2016}
  };

  // Check if opt_version is supported
  auto save_version_it = version_table.find(opt_version);
  if (save_version_it == version_table.end()) {
    std::cout << "SketchUp version \"" << opt_version << "\" not supported. Exiting." << std::endl;
    std::cout << "Supported versions: 3, 4, 5, 6, 7, 8, 2013, 2014, 2015, 2016" << std::endl;
    return EXIT_FAILURE;
  }
  SUModelVersion save_version = save_version_it->second;

  if (_access(opt_input.c_str(), F_OK) != 0) {
    std::cout << "Input file \"" << opt_input << "\" does not exist. Exiting." <<  std::endl;
    return EXIT_FAILURE;
  }

  // int retval = PathFileExists(opt_input.c_str());

  if (_access(opt_input.c_str(), R_OK) != 0) {
    std::cout << "Can not get read permission for input file \"" << opt_input << "\". Exiting." <<  std::endl;
    return EXIT_FAILURE;
  }
  if (_access(opt_output.c_str(), F_OK) == 0) {
    std::cout << "Output file \"" << opt_output << "\" already exists. Exiting." <<  std::endl;
    return EXIT_FAILURE;
  }

  // Always initialize the API before using it
  SUInitialize();

  // Create the model
  SUModelRef model = SU_INVALID;
  SUResult res = SUModelCreateFromFile(&model, opt_input.c_str());
  CHECK(res);

  int major, minor, build;
  res = SUModelGetVersion(model, &major, &minor, &build);
  CHECK(res);

  res = SUModelSaveToFileWithVersion(model, opt_output.c_str(), save_version);
  CHECK(res);

  res = SUModelRelease(&model);
  CHECK(res);

  SUTerminate();

  return EXIT_SUCCESS;
}
