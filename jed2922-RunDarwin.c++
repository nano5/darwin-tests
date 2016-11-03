// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include "Darwin.h"
#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

// ----
// main
// ----

int main() {
  using namespace std;
  // ----
  // food
  // ----

  /*
   0: left
   1: go 0
  */
  Species food('f');
  food.addInstruction(LEFT, -1);
  food.addInstruction(GO, 0);

  // ------
  // hopper
  // ------

  /*
   0: hop
   1: go 0
  */
  Species hopper('h');
  hopper.addInstruction(HOP, -1);
  hopper.addInstruction(GO, 0);

  // -----
  // rover
  // -----

  /*
   0: if_enemy 9
   1: if_empty 7
   2: if_random 5
   3: left
   4: go 0
   5: right
   6: go 0
   7: hop
   8: go 0
   9: infect
  10: go 0
  */
  Species rover('r');
  rover.addInstruction(IF_ENEMY, 9);
  rover.addInstruction(IF_EMPTY, 7);
  rover.addInstruction(IF_RANDOM, 5);
  rover.addInstruction(LEFT, -1);
  rover.addInstruction(GO, 0);
  rover.addInstruction(RIGHT, -1);
  rover.addInstruction(GO, 0);
  rover.addInstruction(HOP, -1);
  rover.addInstruction(GO, 0);
  rover.addInstruction(INFECT, -1);
  rover.addInstruction(GO, 0);

  // ----
  // trap
  // ----
  /*

   0: if_enemy 3
   1: left
   2: go 0
   3: infect
   4: go 0
  */
  Species trap('t');
  trap.addInstruction(IF_ENEMY, 3);
  trap.addInstruction(LEFT, -1);
  trap.addInstruction(GO, 0);
  trap.addInstruction(INFECT, -1);
  trap.addInstruction(GO, 0);

  // -----------
  // terminator
  // -----------
  /*

   0: if_wall 4
   1: if_enemy 6
   2: hop
   3: go 0
   4: left
   5: go 0
   6: infect
   7: go 0
  */
  Species terminator('O');
  terminator.addInstruction(IF_WALL, 4);
  terminator.addInstruction(IF_ENEMY, 6);
  terminator.addInstruction(HOP, -1);
  terminator.addInstruction(GO, 0);
  terminator.addInstruction(LEFT, -1);
  terminator.addInstruction(GO, 0);
  terminator.addInstruction(INFECT, -1);
  terminator.addInstruction(GO, 0);

  // ----------
  // darwin 8x8
  // ----------

  cout << "*** Darwin 8x8 ***" << endl;
  /*
  8x8 Darwin
  Food,   facing east,  at (0, 0)
  Hopper, facing north, at (3, 3)
  Hopper, facing east,  at (3, 4)
  Hopper, facing south, at (4, 4)
  Hopper, facing west,  at (4, 3)
  Food,   facing north, at (7, 7)
  Simulate 5 moves.
  Print every grid.
  */
  Darwin D8x8(8, 8);

  D8x8.addCreature(&food, 0, 0, 1);
  D8x8.addCreature(&hopper, 3, 3, 0);
  D8x8.addCreature(&hopper, 3, 4, 1);
  D8x8.addCreature(&hopper, 4, 3, 3);
  D8x8.addCreature(&hopper, 4, 4, 2);
  D8x8.addCreature(&food, 7, 7, 0);

  for (int i = 0; i < 5; ++i) {
    D8x8.print();
    D8x8.simulate();
  }
  D8x8.print();

  // ----------
  // darwin 7x9
  // ----------

  /*
  7x9 Darwin
  Trap,   facing south, at (0, 0)
  Hopper, facing east,  at (3, 2)
  Rover,  facing north, at (5, 4)
  Trap,   facing west,  at (6, 8)
  Simulate 5 moves.
  Print every grid.
  */
  cout << "*** Darwin 7x9 ***" << endl;

  srand(0);

  Darwin D7x9(7, 9);

  D7x9.addCreature(&trap, 0, 0, 2);
  D7x9.addCreature(&hopper, 3, 2, 1);
  D7x9.addCreature(&rover, 5, 4, 0);
  D7x9.addCreature(&trap, 6, 8, 3);

  for (int i = 0; i < 5; ++i) {
    D7x9.print();
    D7x9.simulate();
  }
  D7x9.print();

  // ------------
  // darwin 72x72
  // without best
  // ------------

  /*
  Randomly place the following creatures facing randomly.
  Call rand(), mod it with 5184 (72x72), and use that for the position
  in a row-major order grid.
  Call rand() again, mod it with 4 and use that for it's direction with
  the ordering: west, north, east, south.
  Do that for each kind of creature.
  10 Food
  10 Hopper
  10 Rover
  10 Trap
  Simulate 1000 moves.
  Print the first 10 grids          (i.e. 0, 1, 2...9).
  Print every 100th grid after that (i.e. 100, 200, 300...1000).
  */
  // TODO: Piazza about "each kind of creature" and "every 100th"
  cout << "*** Darwin 72x72 without Best ***" << endl;

  srand(0);

  Darwin NoBest(72, 72);
  // four fors for creatures
  for (int i = 0; i < 10; ++i)
    NoBest.addCreature(&food);

  for (int i = 0; i < 10; ++i)
    NoBest.addCreature(&hopper);

  for (int i = 0; i < 10; ++i)
    NoBest.addCreature(&rover);

  for (int i = 0; i < 10; ++i)
    NoBest.addCreature(&trap);

  // print
  NoBest.print();
  for (int i = 0; i < 10; ++i) {
    NoBest.simulate();
    NoBest.print();
  }

  NoBest.simulate(91);
  NoBest.print();

  for (int i = 100; i < 1000; i += 100) {
    NoBest.simulate(100);
    NoBest.print();
  }

  // ------------
  // darwin 72x72
  // with best
  // ------------

  cout << "*** Darwin 72x72 with Best ***" << endl;
  /*
  Randomly place the following creatures facing randomly.
  Call rand(), mod it with 5184 (72x72), and use that for the position
  in a row-major order grid.
  Call rand() again, mod it with 4 and use that for it's direction with
  the ordering: 0:west, 1:north, 2:east, 3:south.
  Do that for each kind of creature.
  10 Food
  10 Hopper
  10 Rover
  10 Trap
  10 Best
  Simulate 1000 moves.
  Best MUST outnumber ALL other species for the bonus pts.
  Print the first 10 grids          (i.e. 0, 1, 2...9).
  Print every 100th grid after that (i.e. 100, 200, 300...1000).
  */
  srand(0);

  Darwin WithBest(72, 72);
  // four fors for creatures
  for (int i = 0; i < 10; ++i)
    WithBest.addCreature(&food);

  for (int i = 0; i < 10; ++i)
    WithBest.addCreature(&hopper);

  for (int i = 0; i < 10; ++i)
    WithBest.addCreature(&rover);

  for (int i = 0; i < 10; ++i)
    WithBest.addCreature(&trap);
  for (int i = 0; i < 10; ++i)
    WithBest.addCreature(&terminator);

  // print
  WithBest.print();
  for (int i = 0; i < 9; ++i) {
    WithBest.simulate();
    WithBest.print();
  }

  WithBest.simulate(91);
  WithBest.print();

  for (int i = 100; i < 1000; i += 100) {
    WithBest.simulate(100);
    WithBest.print();
  }

  return 0;
}
