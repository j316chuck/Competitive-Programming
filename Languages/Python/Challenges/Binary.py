def guess_binary():
    """Return the number of attempted guesses. Implement a faster search
    algorithm that asks the user whether a guess is less than or greater than
    the correct number.

    Hint: If you know the guess is greater than the correct number, then your
    algorithm doesn't need to try numbers that are greater than guess.
    """
    prompt_for_number(LOWER, UPPER)
    num_guesses = 0
    lower, upper = LOWER, UPPER
    correct = False
    "*** YOUR CODE HERE ***"
    while not correct:
        guess = (lower + upper)//2
        correct = is_correct(guess)
        if is_too_high(guess):
            upper = (lower + upper+1)//2
        else: 
            lower = (lower + upper+1)//2
        num_guesses = num_guesses + 1
    return num_guesses

# Receive user input. You do not need to understand the code below this line.

def prompt_for_number(lower, upper):
    """Prompt the user for a number between lower and upper. Return None."""
    is_valid_number = False
    while not is_valid_number:
        # You don't need to understand the following two lines.
        number = input('Pick an integer between {0} and {1} (inclusive) for me to guess: '.format(lower, upper))
        number = int(number)
        if lower <= number <= upper:
            is_valid_number = True

def is_correct(guess):
    """Ask the user if a guess is correct and return whether they respond y."""
    return is_yes('Is {0} your number? [y/n] '.format(guess))

def is_too_high(guess):
    """Ask the user if a guess is too high and return whether they say yes."""
    return is_yes('Is {0} too high? [y/n] '.format(guess))

def is_yes(prompt):
    """Ask the user a yes or no question and return whether they say yes."""
    while True: # This while statement will loop until a "return" is reached.
        yes_no = input(prompt).strip()
        if yes_no == 'y':
            return True
        elif yes_no == 'n':
            return False
        print('Please type y or n and press return/enter')