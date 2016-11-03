// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

// ----
// test
// ----

TEST(DarwinFixture, test)
{
	ASSERT_TRUE(true);
}

// making sure init doesn't seg fault
TEST(DarwinFixture, Species_1)
{
	Species s('a');
	ASSERT_TRUE(s.get_species() == 'a');
}

TEST(DarwinFixture, Species_2)
{
	Species s('b');
	ASSERT_TRUE(s.get_species() == 'b');
}

TEST(DarwinFixture, Species_3)
{
	Species s('c');
	ASSERT_TRUE(s.get_species() == 'c');
}

TEST(DarwinFixture, assign_species_1)
{
	Species s1('f');
	Species s2('c');

	s1 = s2;
	
	ASSERT_TRUE(s1 == s2);
}

TEST(DarwinFixture, assign_species_2)
{
	Species s1('f');
	Species s2('c');
	Species s3('h');

	s1 = s2;
	s1 = s3;
	
	ASSERT_TRUE(s1 == s3);
}

TEST(DarwinFixture, assign_species_3)
{
	Species s1('a');
	Species s2('b');
	Species s3('c');
	Species s4('d');

	s1 = s2;
	s1 = s3;
	s1 = s4;

	ASSERT_TRUE(s1 == s4);
}

TEST(DarwinFixture, Species_equal_equal_operator_1)
{
	Species s1('f');
	Species s2('f');
	ASSERT_TRUE(s1 == s2);
}

TEST(DarwinFixture, Species_equal_equal_operator_2)
{
	Species s1('a');
	Species s2('a');
	Species s3('c');

	s3 = s2;

	ASSERT_TRUE(s1 == s3);
}

TEST(DarwinFixture, Species_equal_equal_operator_3)
{
	Species s1('a');
	Species s2('b');
	Species s3('c');
	Species s4('d');
	Species s5('d');

	s1 = s2;
	s1 = s3;
	s1 = s4;

	ASSERT_TRUE(s1 == s5);
}

TEST(DarwinFixture, Species_add_instruction_1)
{
	Species s('f');
	s.add_instruction(hop);
	int n = 1;
	ASSERT_EQ(0, s.calc_valid_step(n));
}


TEST(DarwinFixture, Species_add_instruction_2)
{
	Species s('f');
	s.add_instruction(hop);
	s.add_instruction(hop);

	int n = 2;
	ASSERT_EQ(0, s.calc_valid_step(n));
}

TEST(DarwinFixture, Species_add_instruction_3)
{
	Species s('f');
	s.add_instruction(hop);
	s.add_instruction(hop);
	s.add_instruction(hop);

	int n = 3;
	ASSERT_EQ(0, s.calc_valid_step(n));
}

TEST(DarwinFixture, Species_print_species_1)
{
	Species s('a');
	s.print_species();
	cout << endl;
}

TEST(DarwinFixture, Species_print_species_2)
{
	Species s1('a');
	Species s2('b');
	s1 = s2;
	s1.print_species();
	cout << endl;
}

TEST(DarwinFixture, Species_print_species_3)
{
	Species s1('a');
	Species s2('b');
	Species s3('c');
	s1 = s2;
	s1 = s3;
	s1.print_species();
	cout << endl;
}

TEST(DarwinFixture, Species_execute_move_1)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> dest(0,3);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	int pc = 0;

	s.execute_move(loc, d, pc);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Species_execute_move_2)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> loc2(0,3);
	const pair<int,int> dest(0,2);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	int pc = 0;

	s.execute_move(loc, d, pc);
	s.execute_move(loc2, d, pc);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Species_execute_move_3)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> loc2(0,3);
	const pair<int,int> loc3(0,2);
	const pair<int,int> dest(0,1);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	int pc = 0;

	s.execute_move(loc, d, pc);
	s.execute_move(loc2, d, pc);
	s.execute_move(loc3, d, pc);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Species_calc_valid_step_1)
{
	Species s('f');
	s.add_instruction(hop);
	int n = 2;
	ASSERT_EQ(0, s.calc_valid_step(n));
}


TEST(DarwinFixture, Species_calc_valid_step_2)
{
	Species s('f');
	s.add_instruction(hop);
	s.add_instruction(hop);

	int n = 1;
	ASSERT_EQ(1, s.calc_valid_step(n));
}

TEST(DarwinFixture, Species_calc_valid_step_3)
{
	Species s('f');
	s.add_instruction(hop);
	s.add_instruction(hop);
	s.add_instruction(hop);

	int n = 5;
	ASSERT_EQ(2, s.calc_valid_step(n));
}

TEST(DarwinFixture, Creature_1)
{
	Species s('a');
	Creature c(s);

	ASSERT_TRUE(c.get_species() == s);
}

TEST(DarwinFixture, Creature_2)
{
	Species s('b');
	Creature c(s);

	ASSERT_TRUE(c.get_species() == s);
}

TEST(DarwinFixture, Creature_3)
{
	Species s('c');
	Creature c(s);

	ASSERT_TRUE(c.get_species() == s);
}

TEST(DarwinFixture, assign_creature_1)
{
	Species s('f');
	Creature c1(s);
	Creature c2(s);

	c1 = c2;
	ASSERT_TRUE(c1 == c2);
}

TEST(DarwinFixture, assign_creature_2)
{
	Species s('f');
	Species s2('f');
	Creature c1(s);
	Creature c2(s);
	Creature c3(s2);

	c1 = c2;
	ASSERT_TRUE(c1 == c3);
}

TEST(DarwinFixture, assign_creature_3)
{
	Species s('f');
	Species s2('f');
	Creature c1(s);
	Creature c2(s);
	Creature c3(s2);

	c1 = c2;
	c3 = c2;
	ASSERT_TRUE(c1 == c3);
}

TEST(DarwinFixture, Creature_equal_equal_operator_1)
{
	Species s('f');
	Creature c1(s);
	Creature c2(s);

	ASSERT_TRUE(c1 == c2);
}

TEST(DarwinFixture, Creature_equal_equal_operator_2)
{
	Species s('f');
	Species s2('f');
	Creature c1(s);
	Creature c2(s2);

	ASSERT_TRUE(c1 == c2);
}

TEST(DarwinFixture, Creature_equal_equal_operator_3)
{
	Species s('f');
	Species s2('a');
	s2 = s;
	Creature c1(s);
	Creature c2(s2);

	ASSERT_TRUE(c1 == c2);
}

TEST(DarwinFixture, Creature_execute_move_1)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> dest(0,3);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	c.execute_move(loc, d);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Creature_execute_move_2)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> loc2(0,3);
	const pair<int,int> dest(0,2);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	c.execute_move(loc, d);
	c.execute_move(loc2, d);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Creature_execute_move_3)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> loc2(0,3);
	const pair<int,int> loc3(0,2);
	const pair<int,int> dest(0,1);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	c.execute_move(loc, d);
	c.execute_move(loc2, d);
	c.execute_move(loc3, d);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Creature_do_specific_move_1)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> dest(0,3);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	c.do_specific_move(loc, d, 0);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Creature_do_specific_move_2)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> loc2(0,3);
	const pair<int,int> dest(0,2);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	c.do_specific_move(loc, d, 0);
	c.do_specific_move(loc2, d, 0);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Creature_do_specific_move_3)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,4);
	const pair<int,int> loc2(0,3);
	const pair<int,int> loc3(0,2);
	const pair<int,int> dest(0,1);

	d.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	c.do_specific_move(loc, d, 0);
	c.do_specific_move(loc2, d, 0);
	c.do_specific_move(loc3, d, 0);

	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Creature_infect_1)
{
	Species s1('f');
	Species s2('h');

	Creature c1(s1);
	Creature c2(s2);

	c1.infect(c2);

	ASSERT_TRUE(c1 == c2);
}

TEST(DarwinFixture, Creature_infect_2)
{
	Species s1('f');
	Species s2('h');
	Creature c1(s2);
	Creature c2(s1);
	Creature c3(s1);

	c2.infect(c1);

	ASSERT_TRUE(c1 == c3);
}

TEST(DarwinFixture, Creature_infect_3)
{
	Species s('f');
	Species s2('h');
	Creature c1(s);
	Creature c2(s);
	Creature c3(s2);

	c2.infect(c1);
	c2.infect(c3);

	ASSERT_TRUE(c1 == c3);
}

TEST(DarwinFixture, Creature_is_same_species_1)
{
	Species s('f');
	Creature c1(s);
	Creature c2(s);

	ASSERT_TRUE(c1.is_same_species(c2));
}

TEST(DarwinFixture, Creature_is_same_species_2)
{
	Species s1('f');
	Species s2('f');
	Creature c1(s1);
	Creature c2(s2);

	ASSERT_TRUE(c1.is_same_species(c2));
}

TEST(DarwinFixture, Creature_is_same_species_3)
{
	Species s1('f');
	Species s2('h');
	Creature c1(s1);
	Creature c2(s2);

	ASSERT_FALSE(c1.is_same_species(c2));
}

TEST(DarwinFixture, Creature_not_do_turn_1)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5, 5);

	const pair<int,int> loc(2, 2);

	d.add_creature(c, loc, faced_left);
	
	c.execute_move(loc, d);

	ASSERT_FALSE(c.not_do_turn(0));

}

TEST(DarwinFixture, Creature_not_do_turn_2)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5, 5);

	const pair<int,int> loc(2, 2);

	d.add_creature(c, loc, faced_left);
	
	c.execute_move(loc, d);

	ASSERT_FALSE(c.not_do_turn(0));

}

TEST(DarwinFixture, Creature_not_do_turn_3)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);

	Darwin d(5, 5);

	const pair<int,int> loc(2, 2);

	d.add_creature(c, loc, faced_left);
	
	c.execute_move(loc, d);

	ASSERT_TRUE(c.not_do_turn(1));

}


TEST(DarwinFixture, Creature_print_species_1)
{
	Species s('a');
	Creature c(s);

	c.print_species();
	cout << endl;
}

TEST(DarwinFixture, Creature_print_species_2)
{
	Species s1('a');
	Species s2('b');

	Creature c1(s1);
	Creature c2(s2);
	c1 = c2; 

	c1.print_species();
	cout << endl;
}

TEST(DarwinFixture, Creature_print_species_3)
{
	Species s1('a');
	Species s2('b');
	Species s3('c');

	Creature c1(s1);
	Creature c2(s2);
	Creature c3(s3);

	c1 = c2; 
	c1 = c3;

	c1.print_species();
	cout << endl;
}

TEST(DarwinFixture, Darwin_1)
{
	Darwin d(5, 5);

	Species def_s = Species('.');
	Creature def_c = Creature(def_s);

	const int x = 5;
	const int y = 5;

	vector< vector< pair<Direction_faced, Creature> > > _grid1(y, vector< pair<Direction_faced, Creature> >(x,pair<Direction_faced,Creature>(faced_left,def_c)));
    vector< vector< pair<Direction_faced, Creature> > > _grid2 = d.get_grid();

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			ASSERT_TRUE(_grid1[i][j].second == _grid2[i][j].second);
		}
	}
}

TEST(DarwinFixture, Darwin_2)
{
	Darwin d(10, 10);

	Species def_s = Species('.');
	Creature def_c = Creature(def_s);

	const int x = 10;
	const int y = 10;

	vector< vector< pair<Direction_faced, Creature> > > _grid1(y, vector< pair<Direction_faced, Creature> >(x,pair<Direction_faced,Creature>(faced_left,def_c)));
    vector< vector< pair<Direction_faced, Creature> > > _grid2 = d.get_grid();

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			ASSERT_TRUE(_grid1[i][j].second == _grid2[i][j].second);
		}
	}

}

TEST(DarwinFixture, Darwin_3)
{
	Darwin d(25, 25);

	Species def_s = Species('.');
	Creature def_c = Creature(def_s);

	const int x = 10;
	const int y = 10;

	vector< vector< pair<Direction_faced, Creature> > > _grid1(y, vector< pair<Direction_faced, Creature> >(x,pair<Direction_faced,Creature>(faced_left,def_c)));
    vector< vector< pair<Direction_faced, Creature> > > _grid2 = d.get_grid();

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			ASSERT_TRUE(_grid1[i][j].second == _grid2[i][j].second);
		}
	}
}

TEST(DarwinFixture, Darwin_add_creature_1)
{
	Species s('f');
	Creature c(s);

	Darwin d(5, 5);
	Darwin d2(5, 5);
	const pair<int,int> loc(0,4);

	d.add_creature(c, loc, faced_left);
	d2.add_creature(c, loc, faced_left);
	
	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Darwin_add_creature_2)
{
	Species s('f');
	Creature c(s);

	Darwin d(5, 5);
	Darwin d2(5, 5);
	const pair<int,int> loc(-1,-1);

	d.add_creature(c, loc, faced_left);
	
	ASSERT_TRUE(d == d2);
}

TEST(DarwinFixture, Darwin_add_creature_3)
{
	Species s('f');
	Creature c1(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc1(0, 0);
	const pair<int,int> loc2(1, 1);

	d1.add_creature(c1, loc1, faced_left);
	d1.add_creature(c2, loc2, faced_left);
	d2.add_creature(c1, loc1, faced_left);
	d2.add_creature(c2, loc2, faced_left);

	ASSERT_TRUE(d1 == d2);
}


TEST(DarwinFixture, Darwin_hop_1)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5 ,5);

	const pair<int,int> loc(0, 4);
	const pair<int,int> dest(0, 0);

	d1.add_creature(c, loc, faced_up);
	d2.add_creature(c2, dest, faced_up);

	int turns = 5;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_hop_2)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5 ,5);

	const pair<int,int> loc(0, 4);
	const pair<int,int> dest(0, 4);

	d1.add_creature(c, loc, faced_down);
	d2.add_creature(c2, dest, faced_down);

	int turns = 5;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_hop_3)
{
	Species s('f');
	s.add_instruction(hop);

	Creature c(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5 ,5);

	const pair<int,int> loc(0, 4);
	const pair<int,int> dest(4, 4);

	d1.add_creature(c, loc, faced_right);
	d2.add_creature(c2, dest, faced_right);

	int turns = 5;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}



TEST(DarwinFixture, Darwin_left_1)
{
	Species s('f');
	s.add_instruction(left);
	s.add_instruction(hop);

	Creature c1(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(1,2);

	d1.add_creature(c1, loc, faced_up);
	d2.add_creature(c2, dest, faced_left);

	int turns = 2;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

	
}

TEST(DarwinFixture, Darwin_left_2)
{
	Species s('f');
	s.add_instruction(left);
	s.add_instruction(hop);

	Creature c1(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(2,1);

	d1.add_creature(c1, loc, faced_right);
	d2.add_creature(c2, dest, faced_left);

	int turns = 2;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_left_3)
{
	Species s('f');
	s.add_instruction(left);
	s.add_instruction(hop);

	Creature c1(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(3,2);

	d1.add_creature(c1, loc, faced_down);
	d2.add_creature(c2, dest, faced_right);

	int turns = 2;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_right_1)
{
	Species s('f');
	s.add_instruction(right);
	s.add_instruction(hop);

	Creature c1(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(3,2);

	d1.add_creature(c1, loc, faced_up);
	d2.add_creature(c2, dest, faced_left);

	int turns = 2;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_right_2)
{
	Species s('f');
	s.add_instruction(right);
	s.add_instruction(hop);

	Creature c1(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(2,3);

	d1.add_creature(c1, loc, faced_right);
	d2.add_creature(c2, dest, faced_left);

	int turns = 2;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_right_3)
{
	Species s('f');
	s.add_instruction(right);
	s.add_instruction(hop);

	Creature c1(s);
	Creature c2(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(1,2);

	d1.add_creature(c1, loc, faced_down);
	d2.add_creature(c2, dest, faced_left);

	int turns = 2;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}



TEST(DarwinFixture, Darwin_infect_1)
{
	Species s1('f');
	Species s2('h');

	s1.add_instruction(infect);
	s2.add_instruction(hop);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,4);
	const pair<int,int> dest2(2,1);

	d1.add_creature(c1, loc1, faced_down);
	d1.add_creature(c2, loc2, faced_up);
	d2.add_creature(c1, loc1, faced_down);
	d2.add_creature(c1, dest2, faced_up);

	int turns = 6;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_infect_2)
{
	Species s1('f');
	Species s2('f');

	s1.add_instruction(infect);
	s2.add_instruction(hop);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,4);
	const pair<int,int> dest2(2,1);

	d1.add_creature(c1, loc1, faced_down);
	d1.add_creature(c2, loc2, faced_up);
	d2.add_creature(c1, loc1, faced_down);
	d2.add_creature(c1, dest2, faced_up);

	int turns = 6;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_infect_3)
{
	Species s1('f');
	Species s2('h');

	s1.add_instruction(infect);
	s2.add_instruction(hop);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,4);
	const pair<int,int> dest2(2,1);

	d1.add_creature(c1, loc1, faced_up);
	d1.add_creature(c2, loc2, faced_up);
	d2.add_creature(c1, loc1, faced_down);
	d2.add_creature(c2, dest2, faced_up);

	int turns = 6;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}


TEST(DarwinFixture, Darwin_go_1)
{
	Species s('f');

	s.add_instruction(hop);
	s.add_instruction(go);
	s.add_instruction(left);

	Creature c(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int,int> loc(4, 4);
	const pair<int,int> dest(4, 2);

	d1.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_up);

	int turns = 3;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_go_2)
{
	Species s('f');
	
	s.add_instruction(left);
	s.add_instruction(go);
	s.add_instruction(hop);

	Creature c(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int, int> loc(2,2);
	const pair<int, int> dest(2,3);

	d1.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_down);

	int turns = 3;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_go_3)
{
	Species s('f');
	
	s.add_instruction(left);
	s.add_instruction(go);
	s.add_instruction(right);

	Creature c(s);

	Darwin d1(5, 5);
	Darwin d2(5, 5);

	const pair<int, int> loc(2,3);
	const pair<int, int> dest(2,3);

	d1.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_down);

	int turns = 3;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_if_empty_1)
{
	Species s1('f');
	Species s2('h');

	s1.add_instruction(infect);
	
	s2.add_instruction(left);
	s2.add_instruction(if_empty);
	s2.add_instruction(hop);
	

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,4);

	const pair<int,int> dest1(2,0);
	const pair<int,int> dest2(2,4);

	d1.add_creature(c1, loc1, faced_up);
	d1.add_creature(c2, loc2, faced_right);

	d2.add_creature(c1, dest1, faced_up);
	d2.add_creature(c2, dest2, faced_left);

	int turns = 2;
	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_empty_2)
{
	Species s1('f');
	Species s2('h');

	s1.add_instruction(infect);

	s2.add_instruction(left);
	s2.add_instruction(hop);
	s2.add_instruction(hop);
	s2.add_instruction(hop);
	s2.add_instruction(if_empty);
	s2.add_instruction(right);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc1(1,0);
	const pair<int,int> loc2(2,4);

	const pair<int,int> dest1(1,0);
	const pair<int,int> dest2(2,1);

	d1.add_creature(c1, loc1, faced_up);
	d1.add_creature(c2, loc2, faced_right);

	d2.add_creature(c1, dest1, faced_up);
	d2.add_creature(c2, dest2, faced_left);

	int turns = 6;
	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_empty_3)
{
	Species s1('f');
	Species s2('h');

	s1.add_instruction(infect);

	s2.add_instruction(left);
	s2.add_instruction(hop);
	s2.add_instruction(hop);
	s2.add_instruction(hop);
	s2.add_instruction(if_empty);
	s2.add_instruction(right);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,4);

	const pair<int,int> dest1(2,0);
	const pair<int,int> dest2(1,1);

	d1.add_creature(c1, loc1, faced_up);
	d1.add_creature(c2, loc2, faced_right);

	d2.add_creature(c1, dest1, faced_up);
	d2.add_creature(c2, dest2, faced_left);

	int turns = 8;
	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_wall_1)
{
	Species s('f');

	s.add_instruction(right);
	s.add_instruction(if_wall);
	s.add_instruction(hop);

	Creature c(s);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(4,4);
	const pair<int,int> dest(3,4);

	d1.add_creature(c, loc, faced_right);
	d2.add_creature(c, dest, faced_left);

	int turns = 3;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_wall_2)
{
	Species s('f');

	s.add_instruction(right);
	s.add_instruction(if_wall);
	s.add_instruction(hop);

	Creature c(s);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(0,0);
	const pair<int,int> dest(1,0);

	d1.add_creature(c, loc, faced_left);
	d2.add_creature(c, dest, faced_right);

	int turns = 3;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_wall_3)
{
	Species s('f');

	s.add_instruction(right);
	s.add_instruction(if_wall);
	s.add_instruction(hop);

	Creature c(s);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(2,1);

	d1.add_creature(c, loc, faced_left);
	d2.add_creature(c, dest, faced_up);

	int turns = 3;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_random_1)
{
	srand(0);

	Species s('f');
	s.add_instruction(hop);
	s.add_instruction(if_random);
	s.add_instruction(left);
	
	Creature c(s);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(1,0);

	d1.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_down);

	int turns = 5;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_random_2)
{
	srand(0);

	Species s('f');
	s.add_instruction(right);
	s.add_instruction(if_random);
	s.add_instruction(left);
	
	Creature c(s);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(2,2);
	const pair<int,int> dest(2,2);

	d1.add_creature(c, loc, faced_up);
	d2.add_creature(c, dest, faced_left);

	int turns = 5;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_random_3)
{
	srand(0);

	Species s('f');
	s.add_instruction(hop);
	s.add_instruction(hop);
	s.add_instruction(if_random);
	s.add_instruction(left);
	
	Creature c(s);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc(2,0);
	const pair<int,int> dest(2,3);

	d1.add_creature(c, loc, faced_down);
	d2.add_creature(c, dest, faced_right);

	int turns = 4;

	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);

}

TEST(DarwinFixture, Darwin_if_enemy_1)
{
	Species s1('f');
	Species s2('h');
	s1.add_instruction(infect);

	// should not infect
	s2.add_instruction(left);
	s2.add_instruction(hop);
	s2.add_instruction(hop);
	s2.add_instruction(hop);
	s2.add_instruction(hop);
	s2.add_instruction(if_enemy);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,4);

	const pair<int,int> dest1(2,0);
	const pair<int,int> dest2(2,2);

	d1.add_creature(c1, loc1, faced_up);
	d1.add_creature(c2, loc2, faced_right);

	d2.add_creature(c1, dest1, faced_up);
	d2.add_creature(c2, dest2, faced_left);

	int turns = 8;
	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_if_enemy_2)
{
	Species s1('f');
	Species s2('h');
	s1.add_instruction(infect);

	// should not infect
	s2.add_instruction(left);
	s2.add_instruction(if_enemy);
	s2.add_instruction(hop);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,1);

	const pair<int,int> dest1(2,0);
	const pair<int,int> dest2(1,1);

	d1.add_creature(c1, loc1, faced_up);
	d1.add_creature(c2, loc2, faced_right);

	d2.add_creature(c1, dest1, faced_up);
	d2.add_creature(c2, dest2, faced_down);

	int turns = 4;
	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, Darwin_if_enemy_3)
{
	Species s1('f');
	Species s2('h');
	s1.add_instruction(infect);

	// should not infect
	s2.add_instruction(right);
	s2.add_instruction(if_enemy);
	s2.add_instruction(left);

	Creature c1(s1);
	Creature c2(s2);

	Darwin d1(5,5);
	Darwin d2(5,5);

	const pair<int,int> loc1(2,0);
	const pair<int,int> loc2(2,1);

	const pair<int,int> dest1(2,0);
	const pair<int,int> dest2(2,1);

	d1.add_creature(c1, loc1, faced_up);
	d1.add_creature(c2, loc2, faced_up);

	d2.add_creature(c1, dest1, faced_up);
	d2.add_creature(c2, dest2, faced_up);

	int turns = 4;
	d1.run_game(turns);

	ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, run_game_1)
{
	srand(0);
	Species fs('f');
	Species hs('h');
	Species rs('r');
	Species ts('t');

	fs.add_instruction(left);
	fs.add_instruction(go);

	hs.add_instruction(hop);
	hs.add_instruction(go);

	rs.add_instruction(if_enemy9);
	rs.add_instruction(if_empty7);
	rs.add_instruction(if_random5);
	rs.add_instruction(left);
	rs.add_instruction(go);
	rs.add_instruction(right);
	rs.add_instruction(go);
	rs.add_instruction(hop);
	rs.add_instruction(go);
	rs.add_instruction(infect);
	rs.add_instruction(go);

	Creature f(fs);
	Creature h(hs);
	Creature r(rs);
	Creature t(ts);

	Darwin d(8, 8);

	const pair<int,int> loc1(0, 0);
	const pair<int,int> loc2(3, 3);
	const pair<int,int> loc3(3, 4);
	const pair<int,int> loc4(4, 4);
	const pair<int,int> loc5(4, 3);
	const pair<int,int> loc6(7, 7);

	d.add_creature(f, loc1, faced_right);

	d.add_creature(h, loc2, faced_up);
	d.add_creature(h, loc3, faced_left);
	d.add_creature(h, loc4, faced_down);
	d.add_creature(h, loc5, faced_right);

	d.add_creature(f, loc6, faced_up);

	int turns = 5;

	d.run_game(turns);

}

TEST(DarwinFixture, run_game_2)
{
	srand(0);
	Species fs('f');
	Species hs('h');
	Species rs('r');
	Species ts('t');

	fs.add_instruction(left);
	fs.add_instruction(go);

	hs.add_instruction(hop);
	hs.add_instruction(go);

	rs.add_instruction(if_enemy9);
	rs.add_instruction(if_empty7);
	rs.add_instruction(if_random5);
	rs.add_instruction(left);
	rs.add_instruction(go);
	rs.add_instruction(right);
	rs.add_instruction(go);
	rs.add_instruction(hop);
	rs.add_instruction(go);
	rs.add_instruction(infect);
	rs.add_instruction(go);

	ts.add_instruction(if_enemy3);
	ts.add_instruction(left);
	ts.add_instruction(go);
	ts.add_instruction(infect);
	ts.add_instruction(go);

	Creature f(fs);
	Creature h(hs);
	Creature r(rs);
	Creature t(ts);

	Darwin d(7, 9);

	const pair<int,int> loc1(0, 0);
	const pair<int,int> loc2(2, 3);
	const pair<int,int> loc3(4, 5);
	const pair<int,int> loc4(6, 8);

	d.add_creature(t, loc1, faced_down);
	d.add_creature(h, loc2, faced_right);
	d.add_creature(r, loc3, faced_up);
	d.add_creature(t, loc4, faced_left);

	int turns = 5;

	d.run_game(turns);

}
