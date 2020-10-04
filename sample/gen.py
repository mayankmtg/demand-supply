from random import randint
com = "tomato"
time  = "09:45"
sc = 1
dc = 1
for i in range(10):
    if i%2 == 0:
        print ('s' + str(sc) + " " + time + " " + com + " " + str(randint(1,20)) + " " + str(randint(1,150)))
        sc+=1
    else:
        print ('d' + str(dc) + " " + time + " " + com + " " + str(randint(1,20)) + " " + str(randint(1,150)))
        dc+=1
    
# s1 09:45 tomato 24 100
