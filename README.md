# Discrete Event Simulation
This is a project for CmpE 250, Data Structures and Algorithms, Fall 2017.

You are a businessman who wants to build new Starbucks in Etiler. There
are two types of employees in Starbucks, one of them is cashier who takes the
order of the customer and the other one is barista who prepares the coee
for the customer.
There are two dierent models in Starbucks. Each model has N cashiers
and N/3 baristas(N is divisible by 3 in examples). First model has one queue
for cashiers and one queue for baristas(Fig. 1). The other model has one
queue for cashiers and N/3 queues for baristas. First 3 cashiers send the
orders to the rst barista and next 3 cashiers send the orders to the second
barista and goes on like that(Fig. 2). In both systems, cashier queue works
by rst come rst serve design and barista queue works by most expensive
coee served rst.
You are going to simulate these two dierent models and collect the following
statistics for each model:
1. Total running time of the system
2. Utilization of each cashier and barista
3. Turnaround time of each order
4. Maximum length of each queue


# How to compile
In a terminal, call commands:

>cmake CMakeLists.txt

>make

OR

>cmake CMakeLists.txt && make

Make sure the executable is produced.

Then you can test the project with the command:

>./project2 inputFile outputFile