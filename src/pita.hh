#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <memory>

#include <ctype.h>
#include <stdio.h>

#define FS_SUCCESS_CODE_STANDARD 0
#define FS_ERROR_CODE_STANDARD -1

#define FS_SET_VALUE(s_value, k_value) ((s_value) = (k_value))
#define FS_FLUSH(ENDSTREAM) (std::cout << ENDSTREAM)

/*
 *PITA instructions
 *as predefs
*/
#define FS_INCREMENT_VALUE "pitaplus"
#define FS_DECREMENT_VALUE "pitasub"
#define FS_CELL_SHIFT_BACK "pitashiftback"
#define FS_CELL_SHIFT_FRONT "pitashiftfront"
#define FS_READ_STDIN_BUFFER "pitain"
#define FS_SHOW_STDOUT_BUFFER "pitaout"
#define FS_LOOP_BEGIN "pitabegin"
#define FS_LOOP_END "pitaend"
#define FS_RESET_BUFF "pitaset"
/*
 * PITA instructions as
 * opcode
*/
#define OPCODE_MOVE_FRONT 1
#define OPCODE_MOVE_BACK 2
#define OPCODE_INCREMENT 3
#define OPCODE_DECREMENT 4
#define OPCODE_READ_STDIN_BUFFER 5
#define OPCODE_SHOW_STDOUT_BUFFER 6
#define OPCODE_LOOP_BEGIN 7
#define OPCODE_LOOP_END 8
#define OPCODE_RESET 9

typedef char fs_word;
typedef uint32_t fs32;
typedef int fsint_t;


namespace pita {
  constexpr fs_word nullchar = '\0';
  const fsint_t max_memory_size = 30000; // tape

  template <typename FType>
  FType pita_should_succeed(FType successor, FType successor_value) {
    return (std::move(successor) == successor_value);
  }

  class Environment {
  public:
    std::deque<fsint_t> pita_instructions, pita_memory;
    std::deque<fsint_t>::iterator pita_instruction_pointer, fs_memory_pointer;
    explicit Environment();

    void initialize();
    void wipe_instruction_buffer(bool execparam);
    bool check_fs_source_extension(std::string fsource);
  };

  template <typename Fsarg>
  class Handler : public Environment {
  public:
    inline void pita_increment(Environment& env, Fsarg execparam);
    inline void pita_decrement(Environment& env, Fsarg execparam);
    inline void pita_shift_cell_frwd(Environment& env, Fsarg execparam);
    inline void pita_shift_cell_bkwrd(Environment& env, Fsarg execparam);
    inline void pita_read_stdin_buffer(Environment& env, Fsarg execparam);
    inline void pita_show_stdout_buffer(Environment& env, Fsarg execparam);
    inline void pita_reset_buffer(Environment& env, Fsarg execparam);
    inline void pita_loop_parser(Environment& env, Fsarg execparam);
    inline void pita_push_instruction(Environment& env, fsint_t instr, Fsarg execparam);
  private:
    //fs_word printablechar_;
    std::deque<fsint_t>::iterator loop_begin_ptr;
  };

  class Parser : public Handler<bool> {
  public:
    bool parse_fs_instructions(Environment& env, const char* sourcefilename);
    void interpret_fs_instructions(Environment& env, fsint_t sourceinstr);
  private:
    std::ifstream sourcestream;
    std::string instr_keyword;
  };

  namespace exp {
    #include <exception>
    class FSException : public std::exception {
    public:
      FSException(const char* const message): errmessage_ {message} {};

      const char* what() const noexcept { return errmessage_; }
    private:
      const char* errmessage_;
    };
  }

  bool pita_main(const fs_word*, bool pitamn);
}
