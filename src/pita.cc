/*
      The PITA Programming Language
                Written as joke...I think..
                 
                 Why use PITA?
                ===================
              - IIf you like a challenge, here you go
              - Fun for the whole family.. or might cause World War III. 
              - That's all you're gonna get, you're on your own now. Good luck may your journey be a PITA.
*/

/*
              Language Basics (Brainfuck bindings)
              ====================================
  pitaplus: increments the current value of the memory pointer (cell)
  pitasub: decrements the current value of the memory pointer (cell)
  pitashiftfront: moves the memory pointer to the next cell
  pitashiftback: moves the memory pointer backwards to the previous cell
  pitain: user input, reads a character to stdin
  pitaout: outputs current value in the cell to stdout
  pitabegin: enters a while loop
  pitaend: marks the end of the loop
  pitaset: sets the memory pointer to 0

*/

#include "pita.hh"

namespace pita {

  std::unordered_map<std::string, fsint_t> pita_instr_map;

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_increment(Environment& env, Fsarg execparam) {
    if (execparam) *env.fs_memory_pointer += 1; else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_decrement(Environment& env, Fsarg execparam) {
    if (execparam) *env.fs_memory_pointer -= 1; else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_shift_cell_frwd(Environment& env, Fsarg execparam) {
    if (execparam) {
      if (env.fs_memory_pointer != env.pita_memory.end()--) {
        env.fs_memory_pointer++;
      }
    } else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_shift_cell_bkwrd(Environment& env, Fsarg execparam) {
    if (execparam) {
      if (env.fs_memory_pointer != env.pita_memory.begin()) {
        env.fs_memory_pointer--;
      }
    } else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_show_stdout_buffer(Environment& env, Fsarg execparam) {
    if (execparam) {
      fs_word printablechar_;
      printablechar_ = char (*env.fs_memory_pointer);
      std::cout << printablechar_;
      /*
      if (!isprint(printablechar_)) {
        std::cout << std::dec << static_cast<fsint_t> (printablechar_);
      }
      */
    } else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_read_stdin_buffer(Environment& env, Fsarg execparam) {
    if (execparam) {
      fs_word fsinput; std::cin >> fsinput;
      (*env.fs_memory_pointer) = fsinput;
    } else return;

  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_push_instruction(Environment& env, fsint_t instr, Fsarg execparam) {
    if (execparam) env.pita_instructions.push_back(instr); else return;
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_loop_parser(Environment& env, Fsarg execparm) {
    Parser parser;
    env.pita_instruction_pointer++;
    loop_begin_ptr = env.pita_instruction_pointer;
    while (*env.fs_memory_pointer) {
      env.pita_instruction_pointer = loop_begin_ptr;
      while (*env.pita_instruction_pointer != OPCODE_LOOP_END) {
        parser.interpret_fs_instructions(env, *env.pita_instruction_pointer);
        env.pita_instruction_pointer++;
      }
    }
  }

  template <typename Fsarg>
  inline void Handler<Fsarg>::pita_reset_buffer(Environment& env, Fsarg execparam) {
    *env.fs_memory_pointer = FS_SUCCESS_CODE_STANDARD;
  }

  bool Parser::parse_fs_instructions(Environment& env, const char* sourcefilename) {
    sourcestream = std::ifstream(sourcefilename, std::ios::in);
    if (sourcestream.is_open()) {
      while (sourcestream >> instr_keyword) {
        if (bool kw_found = pita_instr_map.find(instr_keyword) != pita_instr_map.end()) {
          pita_push_instruction(env, pita_instr_map[instr_keyword], true);
        } else if (!kw_found) {
            std::cerr << "(error): invalid pita instruction: "
              << instr_keyword;
            break;
        }
      }
    } else { throw exp::FSException("(error): .pita source cannot be located\n"); }
    return false;
  }

  void Parser::interpret_fs_instructions(Environment& env, fsint_t sourceinstr) {
    switch (sourceinstr) {
      case OPCODE_INCREMENT: pita_increment(env, true); break;
      case OPCODE_DECREMENT: pita_decrement(env, true); break;
      case OPCODE_MOVE_FRONT: pita_shift_cell_frwd(env, true); break;
      case OPCODE_MOVE_BACK: pita_shift_cell_bkwrd(env, true); break;
      case OPCODE_READ_STDIN_BUFFER: pita_read_stdin_buffer(env, true); break;
      case OPCODE_SHOW_STDOUT_BUFFER: pita_show_stdout_buffer(env, true); break;
      case OPCODE_LOOP_BEGIN: pita_loop_parser(env, true); break;
      case OPCODE_RESET: pita_reset_buffer(env, true); break;
    }
  }

  Environment::Environment() : pita_memory(pita::max_memory_size) {
    wipe_instruction_buffer(true);
    fs_memory_pointer = pita_memory.begin();
  }

  void Environment::initialize() {
    pita_instr_map[FS_INCREMENT_VALUE] = OPCODE_INCREMENT;
    pita_instr_map[FS_DECREMENT_VALUE] = OPCODE_DECREMENT;
    pita_instr_map[FS_CELL_SHIFT_BACK] = OPCODE_MOVE_BACK;
    pita_instr_map[FS_CELL_SHIFT_FRONT] = OPCODE_MOVE_FRONT;
    pita_instr_map[FS_READ_STDIN_BUFFER] = OPCODE_READ_STDIN_BUFFER;
    pita_instr_map[FS_SHOW_STDOUT_BUFFER] = OPCODE_SHOW_STDOUT_BUFFER;
    pita_instr_map[FS_LOOP_BEGIN] = OPCODE_LOOP_BEGIN;
    pita_instr_map[FS_LOOP_END] = OPCODE_LOOP_END;
    pita_instr_map[FS_RESET_BUFF] = OPCODE_RESET;
  }

  void Environment::wipe_instruction_buffer(bool execparam) {
    pita_instructions.clear();
    pita_instruction_pointer = pita_instructions.begin();
  }

  bool Environment::check_fs_source_extension(std::string fsource) {
    if (fsource.substr(fsource.find_last_of(".") + 1) == "pita") {
      return true;
    } else { return false; }
  }

  bool pita_main(const fs_word* fssource, bool pitamn) {
    std::unique_ptr<pita::Environment> env = std::make_unique<pita::Parser>();
    std::unique_ptr<pita::Parser> parser = std::make_unique<pita::Parser>();
    fsint_t loop_counter = 0;

    if (pitamn) { env->initialize(); } else return false;

    bool good_ext = env->check_fs_source_extension(fssource);
    if (pita_should_succeed<bool> (good_ext, true)) {
      parser->parse_fs_instructions(*env, fssource);
      for (env->pita_instruction_pointer = env->pita_instructions.begin();
        env->pita_instruction_pointer != env->pita_instructions.end(); ++env->pita_instruction_pointer) {
          if (*env->pita_instruction_pointer == OPCODE_LOOP_BEGIN) {
            ++loop_counter;
          } else if (*env->pita_instruction_pointer == OPCODE_LOOP_END) {
            --loop_counter;
          }
      }
      for (env->pita_instruction_pointer = env->pita_instructions.begin();
        env->pita_instruction_pointer != env->pita_instructions.end(); ++env->pita_instruction_pointer) {
          parser->interpret_fs_instructions(*env, *env->pita_instruction_pointer);
      }

      if (loop_counter != FS_SUCCESS_CODE_STANDARD) {
        std::cerr << "(error): 'pitabegin' has no matching 'pitaend'";
      }
    } else {
        throw exp::FSException("(error): source file must contain a valid pita extension\n");
    }

    return true;
  }

} // namespace: pita
