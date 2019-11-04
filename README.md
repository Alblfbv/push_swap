# push_swap
42 project push_swap

## Description

### push_swap program 
Push_swap program is designed to sort a list of integers in the least amount of operations under specific constraints detailed below.    

The constraints are the following :  
  * the program only operate on two stacks (let's call them A and B) to sort the list of integers
  * at the beginning of the program, the A stack contain the given list, the B stack is empty
  * there is a limited set of instruction to sort the stacks :
    * pa    -> pushes top of A on top of B
    * pb    -> pushes top of B on top of A
    * sa    -> swaps top (1st) of A with 2nd of A
    * sb    -> swaps top (1st) of B with 2nd of B
    * ss    -> sa + sb
    * ra    -> rotates top of A to bottom of A
    * rb    -> rotates top of B to bottom of B
    * rr    -> ra + rb
    * rra   -> rotates bottom of A to top of A
    * rrb   -> rotates bottom of B to top of B
    * rrr   -> rra + rrb

The push_swap program outputs the list of operations to sort the stack (pb, pb, ra, ra, pb, rb, ra ...)

### checker program

The checker is a small program that checks if the push_swap programs does sort the list that was given to it.
To do so :
  * it takes the exact same list of integers (in the same order) that was given to the push_swap program
  * it reads on stdin for the list of operations to sort the list (output of the push_swap program)

The checker then displays OK or KO depending on if the list of instruction effectively sorts the list of integers.

## Requirements
  * gcc
  * SDL2
  * ruby
  
## Usage
### basic use
```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```
### with visualizer
```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```
