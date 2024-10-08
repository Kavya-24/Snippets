class quiz_brain:
    
    def __init__(self, question_list):
        """ Initialier of class 'quiz_brain' """
        self.question_list = question_list
        self.question_number = 0
        self.score = 0
    
    def question_check(self):
        """ Method to check the number of questions left """
        return self.question_number < len(self.question_list)
    
    
    def next_question(self):
        """ Method to go to the next question """
        current_question = self.question_list[self.question_number]
        self.question_number += 1
        user_answer  = input(f"Q.{self.question_number} {current_question.question_text} ('True'/'False')? ")
        self.check_answer(user_answer , current_question.answer)
    
    
    def check_answer(self, user_answer, correct_answer):
        """" 
        Method to check the value and provide a score and the actual correct answer 
        with a bonus trivia fact.
        """
        if (user_answer.lower() == correct_answer.lower()):
            print ("Great Going !!\nYou are Right !!")
            self.score += 1
        else:
            print ("Sorry!! You got this one Wrong.\nBest of Luck for the Next One !!")
        print (f"The Correct Answer is {self.question_list[self.question_number - 1].answer} ")
        print (f"Trivia Fact : {self.question_list[self.question_number - 1].trivia}")
        print (f"Your Current Score is {self.score}/{self.question_number}")
        print ()