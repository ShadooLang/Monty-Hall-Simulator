# n-Doors-Monty-Hall-Simulator
A C++ Program which simulates n number of doors k number of times.

In the classical Monty Hall Problem, suppose you're in a gameshow and you're give the choice of 3 doors.
Behind one of the doors is a car while other are a goats.

You then pick a door, and the host, who knows what is behind the doors, opens the other door which has a goat.
He then asks you whether or not if you want to switch your choice.
The problem is then "Is it better to switch or stay with your choice"?

The classical problem has already been discussed numerous of times for the past few decades.
But this program will first try to solve the question numerically by running the simulation k number of times.
Then the program extends the question by the following:
Suppose we have n number of doors.
The host opens each door and each time he will ask you to stay or switch until only 2 doors are remaining at the end.
The question is then, will choosing to switch your choice randomly before there are only 2 doors left will impact the final probability of winning.

The program itself will simulate 6 strategies concurrently: 
1. never switching
2. only switching at the end
3. always switching
4. randomly switching
5. randomly switching but will not switch at the end
6. randomly switching but will always switch at the end

At the end the program will output a table of the names of the strategies along with their number of wins and win percentages.

With a little bit of tweaking of the code, the program can simulate many other types of strategies and numerically solve other variations of the Monty Hall problem.

Here are some example outputs of the program:
![](https://i.imgur.com/PXRvqg3.png)
![](https://i.imgur.com/6RVgHR6.png)
![](https://i.imgur.com/GVXves2.png)
![](https://i.imgur.com/5Hm2TTl.png)
![](https://i.imgur.com/kq8ozJU.png)
