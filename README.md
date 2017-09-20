# NumberPartitionGA

This is a program to run two algorithms to solve the well-known Number Partition Problem (NPP)
The NPP is taking a set of numbers and partition that set. Each element in the original set may be placed in either of the two sub partitions.
The goal is to find a solution where the sum of the numbers in each partition is equal. For this particular algorithm, a fitness is represented
by an integer. A perfect solution will have a value of 0. As this number increases, the solution is further from a perfect solution. For a
particular set, there might not be a perfect solution. A "chromosome" is the term I will use for a particular solution. A chromosome is 
represented as a binary string of 1's and 0's. A 1 represents a value in one of the two partitions and a 0 represents a value in the other
partition. Each position of the bits corresponds to the position of the SORTED ascending original list. 

These two algorithms are as follows:
A greedy algorithm called the longest processing time heuristic. This algorithm first takes the largest element in the original set and places
it in the "left" partition. The sum for that partition is then calculated (one value at this point). The element is then removed from the
original set. The repetitive process at this point is to take the highest value element in the original set and place it in the partition
with the smaller sum. This is repeated until there are no longer any elements left in the original set.

The genetic algorithm (GA) is an algorithm that takes elements from biological evolution and mimics them to alter chromosomes that have a
better fitness than their respective parents. The general steps I take for this algorithm are: 

* Creating a finite set of randomly generated chromosomes (initial population)

* Using 2-tournament selection to choose two parents from the population

* Use 2-point crossover to splice the chromosomes from the two parents to create an offspring chromosome

* Simulate genetic mutation by making the probability of each bit in an offspring chromosome be the opposite of what it was. This probability
is much higher in this algorithm than actaul biology. This is to help speed up the process. 10% probabilty is a good area to work with.

After the finite number of generations are completed, the algorithm might have found multiple solutions. All of the best solutions are then
shown with their respective fitness (abs(sumLeft - sumRight)), binary chromosome, and numeric partitions.
