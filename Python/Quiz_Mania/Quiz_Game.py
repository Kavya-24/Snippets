from Data import question_data
from Question_Model import question
from Quiz_Brain import quiz_brain

LOGO = '''
    ______    ____  ____   __   ________           ___      ___       __      _____  ___    __          __      
   /    " \  ("  _||_ " | |" \ ("      "\         |"  \    /"  |     /""\    (\ "  \|"  \  |" \        /""\     
  // ____  \ |   (  ) : | ||  | \___/   :)         \   \  //   |    /    \   |.\ \  \    | ||  |      /    \    
 /  /    )  )(:  |  | . ) |:  |   /  ___/          /\ \ \/.    |   /' /\  \  |: \.   \ \ | |:  |     /' /\  \   
(: (____/ //  \  \__/ //  |.  |  //  \__          |: \.        |  //  __'  \ |.  \    \. | |.  |    //  __'  \  
 \ \       \  /\  __ //\  /\  |\(:   / "\         |.  \    /:  | /   /  \ \ \|    \    \ | /\  |\  /   /  \ \ \ 
  \_____/\__\(__________)(__\_|_)\_______)        |___|\__/|___|(___/    \___)\___|\____\)(__\_|_)(___/    \___)
                                                                                                                
'''
print (LOGO)

question_resource = []
for question_item in question_data:
    question_text = question_item["text"]
    question_answer = question_item["answer"]
    question_trivia = question_item["trivia"]
    new_question = question(question_text, question_answer, question_trivia)
    question_resource.append(new_question)
    

quiz = quiz_brain(question_resource)    
while quiz.question_check:
    quiz.next_question()
    
    