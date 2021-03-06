/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright (C) 2015-2016 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef UCI_H
#define UCI_H

#include <string.h>

#include "types.h"

struct Option;
typedef struct Option Option;

typedef void (*OnChange)(Option *);

// no options are of type combo
#define OPT_TYPE_CHECK    0
#define OPT_TYPE_SPIN     1
#define OPT_TYPE_BUTTON   2
#define OPT_TYPE_STRING   3
#define OPT_TYPE_DISABLED 4

#define OPT_CORRESPONDENCEMODE    0
#define OPT_CLEAN_SEARCH    1
#define OPT_RAZORING        2
#define OPT_FUTILITY        3
#define OPT_PRUNING         4
#define OPT_NULLMOVE        5
#define OPT_PROBCUT         6
#define OPT_DEBUG_LOG_FILE  7
#define OPT_CONTEMPT        8
#define OPT_THREADS         9
#define OPT_HASH            10
#define OPT_CLEAR_HASH      11
#define OPT_PONDER          12
#define OPT_MULTI_PV        13
#define OPT_REP_FIX         14
#define OPT_SKILL_LEVEL     15
#define OPT_MOVE_OVERHEAD   16
#define OPT_NODES_TIME      17
#define OPT_CHESS960        18
#define OPT_SYZ_PATH        19
#define OPT_SYZ_PROBE_DEPTH 20
#define OPT_SYZ_50_MOVE     21
#define OPT_SYZ_PROBE_LIMIT 22
#define OPT_SYZ_USE_DTM     23
#define OPT_LARGE_PAGES     24
#define OPT_VARIETY         25
#define OPT_NUMA            26

struct Option {
  char *name;
  int type;
  int def, min_val, max_val;
  char *def_string;
  OnChange on_change;
  int value;
  char *val_string;
};

void options_init(void);
void options_free(void);
void print_options(void);
int option_value(int opt);
char *option_string_value(int opt);
void option_set_value(int opt, int value);
int option_set_by_name(char *name, char *value);

void setoption(char *str);
void position(Pos *pos, char *str);

void uci_loop(int argc, char* argv[]);
char *uci_value(char *str, Value v);
char *uci_square(char *str, Square s);
char *uci_move(char *str, Move m, int chess960);
void print_pv(Pos *pos, Depth depth, Value alpha, Value beta);
Move uci_to_move(const Pos *pos, char *str);

#endif

