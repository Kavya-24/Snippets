import random

def guessing_game():
    """Function to play the Number Guessing Game."""
    number_to_guess = random.randint(1, 100)
    attempts = 10
    print("Welcome to the Number Guessing Game!")
    print("I'm thinking of a number between 1 and 100.")
    print(f"You have {attempts} attempts to guess it.\n")

    while attempts > 0:
        guess = int(input("Enter your guess: "))
        
        if guess < number_to_guess:
            print("Too low! Try again.")
        elif guess > number_to_guess:
            print("Too high! Try again.")
        else:
            print(f"Congratulations! You've guessed the number {number_to_guess} correctly!")
            break
        
        attempts -= 1
        print(f"You have {attempts} attempts left.\n")
    
    if attempts == 0:
        print(f"Sorry, you've run out of attempts. The number was {number_to_guess}.")

# Example usage
if __name__ == "__main__":
    guessing_game()
