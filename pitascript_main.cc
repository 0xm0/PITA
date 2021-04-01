#include "src/pita.hh"

int main(int argc, char** argv) {
  if (argc == FS_SUCCESS_CODE_STANDARD + 1) {
    std::cerr << "(error): pita program must be provided.\n";
  } else {
    pita::pita_main(argv[1], true);
  }

  return 0;
}
