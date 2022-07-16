# Naive implementation of "100 prisoners problem"
# https://en.wikipedia.org/wiki/100_prisoners_problem

import random

num_of_games = 10000
num_of_prisoners = 100
num_of_tries = 50
final_score = 0

# just open first 50 boxes - it will never work
def one_naive_attempt(boxes, prisoner_id):
    for try_id in range(0, num_of_tries):
        if (boxes[try_id] == prisoner_id):
            return True
    return False
    
def one_smart_attempt(boxes, prisoner_id):
    next_box_id = prisoner_id   # start with prisoner_id
    for try_id in range(0, num_of_tries):
        drawn_id = boxes[next_box_id]
        #print("  ", next_box_id, ": ", drawn_id)
        if (drawn_id == prisoner_id):
            return True
        else:
            next_box_id = drawn_id
    return False
    
def all_attempts(boxes):
    for prisoner_id in range(0, num_of_prisoners):
        #print(prisoner_id)
        if (one_smart_attempt(boxes, prisoner_id) == False):
            return False
    return True

for i in range(0, num_of_games):
    # generate array with shuffled numbers 0-99
    boxes = list(range(0, num_of_prisoners))
    random.shuffle(boxes)
    #print(boxes)
    final_score += all_attempts(boxes)

print(final_score/num_of_games)