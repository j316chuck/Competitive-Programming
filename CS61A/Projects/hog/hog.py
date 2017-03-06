"""CS 61A Presents The Game of Hog."""

from dice import four_sided, six_sided, make_test_dice
from ucb import main, trace, log_current_line, interact
import math
GOAL_SCORE = 100  # The goal of Hog is to score 100 points.


######################
# Phase 1: Simulator #
######################

def roll_dice(num_rolls, dice=six_sided):
    """Simulate rolling the DICE exactly NUM_ROLLS>0 times. Return the sum of
    the outcomes unless any of the outcomes is 1. In that case, return the
    number of 1's rolled.
    """
    # These assert statements ensure that num_rolls is a positive integer.
    assert type(num_rolls) == int, 'num_rolls must be an integer.'
    assert num_rolls > 0, 'Must roll at least once.'
    # BEGIN PROBLEM 1
    "*** REPLACE THIS LINE ***"

   	#a = dice()
    #print (a)
    num_of_one = 0
    sum = 0
    for i in range(0, num_rolls):
    	number = dice()
    	if number == 1:
    		num_of_one += 1
    	sum += number
    #print (num_of_one)
    if num_of_one == 0: 
    	return sum
    else: 
    	return num_of_one #pig out
    # END PROBLEM 1


def free_bacon(opponent_score):
    """Return the points scored from rolling 0 dice (Free Bacon)."""
    # BEGIN PROBLEM 2
    "*** REPLACE THIS LINE ***"
    # END PROBLEM 2
    score = str(opponent_score)
    result = -1
    for i in score:
    	result = max(result, int(i))	
    return 1 + result
# Write your prime functions here!
def is_prime(n):
	if n == 1:
		return False
	if n == 0:
		return False 
	for i in range(2, int(math.sqrt(n))+1):
		if n % i == 0:
			return False
	return True

def next_prime(curr_number):
	curr_number += 1
	while is_prime(curr_number) == False:
		curr_number += 1
	return curr_number

def take_turn(num_rolls, opponent_score, dice=six_sided):
    """Simulate a turn rolling NUM_ROLLS dice, which may be 0 (Free Bacon).
    Return the points scored for the turn by the current player. Also
    implements the Hogtimus Prime and When Pigs Fly rules.

    num_rolls:       The number of dice rolls that will be made.
    opponent_score:  The total score of the opponent.
    dice:            A function of no args that returns an integer outcome.
    """
    # Leave these assert statements here; they help check for errors.
    assert type(num_rolls) == int, 'num_rolls must be an integer.'
    assert num_rolls >= 0, 'Cannot roll a negative number of dice in take_turn.'
    assert num_rolls <= 10, 'Cannot roll more than 10 dice.'
    assert opponent_score < 100, 'The game should be over.'
    # BEGIN PROBLEM 2
    "*** REPLACE THIS LINE ***"
    #print (opponent_score)
    if num_rolls == 0:
    	total = free_bacon(opponent_score) #free bacon
    else:
    	total = roll_dice(num_rolls, dice) #Hogtimus Prime
    if is_prime(total) == True:
    	total = next_prime(total)
    if total > 25 - num_rolls: #When Pigs Fly
    	total = 25 - num_rolls 

    return total

    # END PROBLEM 2
    
def reroll(dice):
    """Return dice that return even outcomes and re-roll odd outcomes of DICE."""
    def rerolled():
        # BEGIN PROBLEM 3
        "*** REPLACE THIS LINE ***"
        curr_roll = dice()
        if curr_roll % 2 == 0:
        	return curr_roll
        else:
        	new_roll = dice()
        	return new_roll
         # Replace this statement
        # END PROBLEM 3
    return rerolled


def select_dice(score, opponent_score, dice_swapped):
    """Return the dice used for a turn, which may be re-rolled (Hog Wild) and/or
    swapped for four-sided dice (Pork Chop).

    DICE_SWAPPED is True if and only if four-sided dice are being used.
    """
    # BEGIN PROBLEM 4
    "*** REPLACE THIS LINE ***"
    if dice_swapped == True:
    	dice = four_sided
    else:
    	dice = six_sided 
    # END PROBLEM 4
    if (score + opponent_score) % 7 == 0:
    	dice = reroll(dice)
    
    return dice


def other(player):
    """Return the other player, for a player PLAYER numbered 0 or 1.

    >>> other(0)
    1
    >>> other(1)
    0
    """
    return 1 - player
#def average_score(always_roll):
#	for i in range (0, 1000):
#		counter = 0;
#		score0 = 0;
#		while(score0 < goal):
#			always_roll


def play(strategy0, strategy1, score0=0, score1=0, goal=GOAL_SCORE):
    """Simulate a game and return the final scores of both players, with
    Player 0's score first, and Player 1's score second.

    A strategy is a function that takes two total scores as arguments
    (the current player's score, and the opponent's score), and returns a
    number of dice that the current player will roll this turn.

    strategy0:  The strategy function for Player 0, who plays first
    strategy1:  The strategy function for Player 1, who plays second
    score0   :  The starting score for Player 0
    score1   :  The starting score for Player 1
    """
    player = 0  # Which player is about to take a turn, 0 (first) or 1 (second)
    dice_swapped = False  # Whether 4-sided dice have been swapped for 6-sided
    # BEGIN PROBLEM 5
    "*** REPLACE THIS LINE ***"

    while(score0 < goal and score1 < goal):
    	#print (score0, score1)

    	if player == 0:
    		dice = select_dice(score0, score1, dice_swapped)
    		num_rolls = strategy0(score0, score1)
    		
    		if num_rolls >= 0:
    			score0 += take_turn(num_rolls, score1, dice)
    		elif num_rolls == -1: #pork chop
    			score0 += 1
    			if dice_swapped == True:
    				dice_swapped = False
    			else:
    				dice_swapped = True

    	elif player == 1:
    		dice = select_dice(score1, score0, dice_swapped)
    		num_rolls = strategy1(score1, score0)

    		if num_rolls >= 0:
    			score1 += take_turn(num_rolls, score0, dice)
    		elif num_rolls == -1: #pork chop
    			score1 += 1
    			if dice_swapped == True:
    				dice_swapped = False
    			else:
    				dice_swapped = True
    	
    	if score0 == 2 * score1 or score1 == 2 * score0: #swineswap
    		score1, score0 = score0, score1
    	player = other(player)

    return score0, score1

#######################
# Phase 2: Strategies #
#######################

def always_roll(n):
    """Return a strategy that always rolls N dice.

    A strategy is a function that takes two total scores as arguments
    (the current player's score, and the opponent's score), and returns a
    number of dice that the current player will roll this turn.

    >>> strategy = always_roll(5)
    >>> strategy(0, 0)
    5
    >>> strategy(99, 99)
    5
    """
    def strategy(score, opponent_score):
        return n
    return strategy


def check_strategy_roll(score, opponent_score, num_rolls):
    """Raises an error with a helpful message if NUM_ROLLS is an invalid
    strategy output. All strategy outputs must be integers from -1 to 10.

    >>> check_strategy_roll(10, 20, num_rolls=100)
    Traceback (most recent call last):
     ...
    AssertionError: strategy(10, 20) returned 100 (invalid number of rolls)

    >>> check_strategy_roll(20, 10, num_rolls=0.1)
    Traceback (most recent call last):
     ...
    AssertionError: strategy(20, 10) returned 0.1 (not an integer)

    >>> check_strategy_roll(0, 0, num_rolls=None)
    Traceback (most recent call last):
     ...
    AssertionError: strategy(0, 0) returned None (not an integer)
    """
    msg = 'strategy({}, {}) returned {}'.format(
        score, opponent_score, num_rolls)
    assert type(num_rolls) == int, msg + ' (not an integer)'
    assert -1 <= num_rolls <= 10, msg + ' (invalid number of rolls)'


def check_strategy(strategy, goal=GOAL_SCORE):
    """Checks the strategy with all valid inputs and verifies that the
    strategy returns a valid input. Use `check_strategy_roll` to raise
    an error with a helpful message if the strategy returns an invalid
    output.

    >>> def fail_15_20(score, opponent_score):
    ...     if score != 15 or opponent_score != 20:
    ...         return 5
    ...
    >>> check_strategy(fail_15_20)
    Traceback (most recent call last):
     ...
    AssertionError: strategy(15, 20) returned None (not an integer)
    >>> def fail_102_115(score, opponent_score):
    ...     if score == 102 and opponent_score == 115:
    ...         return 100
    ...     return 5
    ...
    >>> check_strategy(fail_102_115)
    >>> fail_102_115 == check_strategy(fail_102_115, 120)
    Traceback (most recent call last):
     ...
    AssertionError: strategy(102, 115) returned 100 (invalid number of rolls)
    """
    # BEGIN PROBLEM 6
    "*** REPLACE THIS LINE ***"
    for i in range(0, goal):
    	for j in range(0, goal):
    		num = strategy(i, j)
    		if num < -1 or num > 10 or type(num) != int:
    			return check_strategy_roll(i, j, num)

    return None
    # END PROBLEM 6


# Experiments

def make_averaged(fn, num_samples=1000):
    """Return a function that returns the average_value of FN when called.

    To implement this function, you will have to use *args syntax, a new Python
    feature introduced in this project.  See the project description.

    >>> dice = make_test_dice(3, 1, 5, 6)
    >>> averaged_dice = make_averaged(dice, 1000)
    >>> averaged_dice()
    3.75
    """
    # BEGIN PROBLEM 7
    "*** REPLACE THIS LINE ***"

    def execute_fn(*args):
    	res = 0.0
    	for i in range(0, num_samples):
    		res += fn(*args)
    	res = res/num_samples
    	return res
    return execute_fn
    # END PROBLEM 7

def max_scoring_num_rolls(dice=six_sided, num_samples=1000):
    """Return the number of dice (1 to 10) that gives the highest average turn
    score by calling roll_dice with the provided DICE over NUM_SAMPLES times.
    Assume that the dice always return positive outcomes.

    >>> dice = make_test_dice(3)
    >>> max_scoring_num_rolls(dice)
    10
    """
    # BEGIN PROBLEM 8
    "*** REPLACE THIS LINE ***"
    max_score = 0
    res = -1
    for i in range(1, 11):
    	if make_averaged(roll_dice, num_samples)(i, dice) > max_score:
    		max_score = make_averaged(roll_dice, num_samples)(i, dice)
    		res = i
    return res 
    # END PROBLEM 8


def winner(strategy0, strategy1):
    """Return 0 if strategy0 wins against strategy1, and 1 otherwise."""
    score0, score1 = play(strategy0, strategy1)
    if score0 > score1:
        return 0
    else:
        return 1


def average_win_rate(strategy, baseline=always_roll(4)):
    """Return the average win rate of STRATEGY against BASELINE. Averages the
    winrate when starting the game as player 0 and as player 1.
    """
    win_rate_as_player_0 = 1 - make_averaged(winner)(strategy, baseline)
    win_rate_as_player_1 = make_averaged(winner)(baseline, strategy)

    return (win_rate_as_player_0 + win_rate_as_player_1) / 2


def run_experiments():
    """Run a series of strategy experiments and report results."""
    if False:  # Change to False when done finding max_scoring_num_rolls
        six_sided_max = max_scoring_num_rolls(six_sided)
        print('Max scoring num rolls for six-sided dice:', six_sided_max)
        rerolled_max = max_scoring_num_rolls(reroll(six_sided))
        print('Max scoring num rolls for re-rolled dice:', rerolled_max)

    if False:  # Change to True to test always_roll(8)
        print('always_roll(8) win rate:', average_win_rate(back_strategy))

    if False:  # Change to True to test bacon_strategy
        print('bacon_strategy win rate:', average_win_rate(bacon_strategy))

    if False:  # Change to True to test swap_strategy
        print('swap_strategy win rate:', average_win_rate(swap_strategy))
    if True:
    	print ('Final strategy win rate: ', average_win_rate(final_strategy))
    #for i in range(1, 11):
    #	print (average_win_rate(always_roll(i)))
    "*** You may add additional experiments as you wish ***"


# Strategies

def bacon_strategy(score, opponent_score, margin=8, num_rolls=4):
    """This strategy rolls 0 dice if that gives at least MARGIN points,
    and rolls NUM_ROLLS otherwise.
    """
    # BEGIN PROBLEM 9
    "*** REPLACE THIS LINE ***"
    curr_margin = free_bacon(opponent_score)
    if is_prime(curr_margin):
    	curr_margin = next_prime(curr_margin)
    if curr_margin >= margin:
    	return 0
    else:
    	return num_rolls
 	 # Replace this statement
    # END PROBLEM 9
check_strategy(bacon_strategy)


def swap_strategy(score, opponent_score, margin=8, num_rolls=4):
    """This strategy rolls 0 dice when it triggers a beneficial swap. It also
    rolls 0 dice if it gives at least MARGIN points. Otherwise, it rolls
    NUM_ROLLS.
    """
    # BEGIN PROBLEM 10
    "*** REPLACE THIS LINE ***"
    curr_margin = free_bacon(opponent_score)
    if is_prime(curr_margin):
    	curr_margin = next_prime(curr_margin)
    score += curr_margin
    if 2 * score == opponent_score:
    	return 0
    if score == 2 * opponent_score:
    	return num_rolls
    if curr_margin >= margin:
    	return 0
    if curr_margin < margin:
    	return num_rolls 

     # Replace this statement
    # END PROBLEM 10
check_strategy(swap_strategy)


def final_strategy(score, opponent_score):
    """Write a brief description of your final strategy.

    *** YOUR DESCRIPTION HERE ***
    """
    # BEGIN PROBLEM 11
    "*** REPLACE THIS LINE ***"
    """
    
    if swap_strategy(score, opponent_score, margin = 11, num_rolls = 5)== 0:
    	return 0
    if score > 90:
    	return swap_strategy(score, opponent_score, margin = 5, num_rolls = 5)

    if score - opponent_score > 10:
	    return swap_strategy(score, opponent_score, margin = 9, num_rolls = 5)
    
    return 5
    """
    
    if score == 0:
    	return -1
    if swap_strategy(score, opponent_score, margin = 7, num_rolls = 5) == 0:
    	return 0
    if score > 90:
   		return swap_strategy(score, opponent_score, margin = 8, num_rolls = 5)
    return 5
 
    # Replace this statement
    
    # END PROBLEM 11

check_strategy(final_strategy)


##########################
# Command Line Interface #
##########################

# NOTE: Functions in this section do not need to be changed. They use features
# of Python not yet covered in the course.

@main
def run(*args):
    """Read in the command-line argument and calls corresponding functions.

    This function uses Python syntax/techniques not yet covered in this course.
    """
    import argparse
    parser = argparse.ArgumentParser(description="Play Hog")
    parser.add_argument('--run_experiments', '-r', action='store_true',
                        help='Runs strategy experiments')

    args = parser.parse_args()

    if args.run_experiments:
        run_experiments()