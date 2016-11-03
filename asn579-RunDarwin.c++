// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Darwin.h"

// ----
// main
// ----

int main () 
{
    using namespace std;

    // ----
    // food
    // ----

    /*
     0: left
     1: go 0
    */

    Species food('f');
    food.add_instruction(LEFT);             //0
    food.add_instruction(GO,0);             //1

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    Species hopper('h');                
    hopper.add_instruction(HOP);            //0
    hopper.add_instruction(GO, 0);          //1

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
    rover.add_instruction(IF_ENEMY, 9);         //0
    rover.add_instruction(IF_EMPTY, 7);         //1
    rover.add_instruction(IF_RANDOM, 5);        //2
    rover.add_instruction(LEFT);                //3
    rover.add_instruction(GO, 0);               //4
    rover.add_instruction(RIGHT);               //5
    rover.add_instruction(GO, 0);               //6
    rover.add_instruction(HOP);                 //7
    rover.add_instruction(GO, 0);               //8
    rover.add_instruction(INFECT);              //9
    rover.add_instruction(GO, 0);               //10

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
    trap.add_instruction(IF_ENEMY, 3);          //0
    trap.add_instruction(LEFT);                 //1
    trap.add_instruction(GO, 0);                //2
    trap.add_instruction(INFECT);               //3
    trap.add_instruction(GO, 0);                //4

    Species best('b');
    best.add_instruction(IF_ENEMY, 9);
    best.add_instruction(IF_EMPTY, 7);
    best.add_instruction(IF_RANDOM, 5);
    best.add_instruction(LEFT);
    best.add_instruction(GO, 0);
    best.add_instruction(RIGHT);
    best.add_instruction(GO, 0);
    best.add_instruction(HOP);
    best.add_instruction(GO, 0);
    best.add_instruction(INFECT);
    best.add_instruction(GO, 0);

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
    
    
    Darwin a(8, 8);
    a.add_creature(Creature(food), EAST, 0, 0);
    a.add_creature(Creature(hopper), NORTH, 3, 3);
    a.add_creature(Creature(hopper), EAST, 3, 4);
    a.add_creature(Creature(hopper), SOUTH, 4, 4);
    a.add_creature(Creature(hopper), WEST, 4, 3);
    a.add_creature(Creature(food), NORTH, 7, 7);
    a.run(5);
    
    

    // ----------
    // darwin 7x9
    // ----------

    cout << "*** Darwin 7x9 ***" << endl;
    srand(0);
    /*
    7x9 Darwin
    Trap,   facing south, at (0, 0)
    Hopper, facing east,  at (3, 2)
    Rover,  facing north, at (5, 4)
    Trap,   facing west,  at (6, 8)
    Simulate 5 moves.
    Print every grid.
    */
    
    Darwin b(7, 9);
    b.add_creature(Creature(trap), SOUTH, 0, 0);
    b.add_creature(Creature(hopper), EAST, 3, 2);
    b.add_creature(Creature(rover), NORTH, 5, 4);
    b.add_creature(Creature(trap), WEST, 6, 8);
    b.run(5);
    

    // ------------
    // darwin 72x72
    // without best
    // ------------

    cout << "*** Darwin 72x72 without Best ***" << endl;
    srand(0);
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

    int n = 72;
    int mod = n*n;
    Darwin c(n, n);
    for(int i = 0; i < 10; ++i)
    {
        int pos = rand() % mod;
        int dir = rand() % 4;
        c.add_creature(Creature(food), dir, (pos/n), (pos%n)); 
    }
    for(int i = 0; i < 10; ++i)
    {
        int pos = rand() % mod;
        int dir = rand() % 4;
        c.add_creature(Creature(hopper), dir, (pos/n), (pos%n)); 
    }
    for(int i = 0; i < 10; ++i){
        int pos = rand() % mod;
        int dir = rand() % 4;
        c.add_creature(Creature(rover), dir, (pos/n), (pos%n)); 
    }
    for(int i = 0; i < 10; ++i){
        int pos = rand() % mod;
        int dir = rand() % 4;
        c.add_creature(Creature(trap), dir, (pos/n), (pos%n)); 
    }
    //c.run(100);
    c.run_prime(1000, 100, 10);

    // ------------
    // darwin 72x72
    // with best
    // ------------

    cout << "*** Darwin 72x72 with Best ***" << endl;
    srand(0);
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

    n = 72;
    mod = n*n;
    Darwin d(n, n);
    for(int i = 0; i < 10; ++i)
    {
        int pos = rand() % mod;
        int dir = rand() % 4;
        d.add_creature(Creature(food), dir, (pos/n), (pos%n)); 
    }
    for(int i = 0; i < 10; ++i)
    {
        int pos = rand() % mod;
        int dir = rand() % 4;
        d.add_creature(Creature(hopper), dir, (pos/n), (pos%n)); 
    }
    for(int i = 0; i < 10; ++i)
    {
        int pos = rand() % mod;
        int dir = rand() % 4;
        d.add_creature(Creature(rover), dir, (pos/n), (pos%n)); 
    }
    for(int i = 0; i < 10; ++i)
    {
        int pos = rand() % mod;
        int dir = rand() % 4;
        d.add_creature(Creature(trap), dir, (pos/n), (pos%n)); 
    }
    for(int i = 0; i < 10; ++i)
    {
        int pos = rand() % mod;
        int dir = rand() % 4;
        d.add_creature(Creature(best), dir, (pos/n), (pos%n)); 
    }
    d.run_prime(1000, 100, 10);

    return 0;}
