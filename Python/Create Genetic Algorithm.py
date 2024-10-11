from random import randint
import random as rn
class Sample:
    def __init__(self,s,score):
        self.s = s
        self.score = score

class GeneticEvolution:
    def __init__(self,s):
        self.s = s
        #97 122
        self.population = []
        self.mutation_rate = 0.1 # 10% mutation will be done, probability 10%
        for i in range(100):
            sample = ''
            for i in range(len(s)):
                sample+= chr(int(randint(97,122))) # asci value 97 to 123, 122 bcz this will generate 123-1
            self.population.append(Sample(sample,self.fitness(sample))) # sampple value will go to in population
    def fitness(self,sample):
        score=0
        for i,j in zip(list(sample),list(self.s)):
            if i==j:
                score+=1
        return score
    def selection(self):
        new_population = []
       
        self.population.sort(key = lambda x: x.score,reverse=True)
        new_population = self.population[:40]
       
        r_sample = rn.sample(self.population[40:],10)
        for i in r_sample:
            new_population.append(i)
        self.population = new_population
    def crossover(self):
        for i in range(100-len(self.population)):
            parents = rn.sample(self.population,2) # 2 parents needed
            child = '' # new child will be imported here
            for i,j in zip(list(parents[0].s),list(parents[1].s)):
                if rn.random()<0.5:
                    child+=i # from other parent which has 50 % chance, i= all kinds of string the charact which was declared before
                else:
                    child+=j # another 50 % parent
            self.population.append(Sample(child,self.fitness(child)))
           
    def mutation(self):
        new_population = []
       
        for sample in self.population:
            mutated = ''
            for i in sample.s: # we will mutated for each and every sample
                if rn.random()<self.mutation_rate: # if the random number is less than mutation rate
                    mutated += chr(int(randint(97,122)))
                else:
                    mutated += i #  if this is greater than, then put the value of i
       
            new_population.append(Sample(mutated,self.fitness(mutated)))
        self.population = new_population
   
    def evolution(self):
        generation = 0
        while True:
            generation+=1
            print(generation, self.population[0].score)
            #print(self.fitness(self.population[0]))
            self.selection()
            #condition
            if self.population[0].score==self.fitness(self.s):
                print(self.population[0].s,self.population[0].score)
                return self.population[0]
            elif generation>1000: # we cannot go far than 1000 for making the generation
                return None
            
            self.selection()
            self.crossover()
            self.mutation()
            
            
g = GeneticEvolution("helloworld")
g.evolution()
