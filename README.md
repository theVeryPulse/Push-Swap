# Push Swap
*A 42 programming project*

## Intro
Given a stack of non-repeating numbers, sort the stack with the help of one extra stack and a fixed set of 
instructions:
- sa : swap the first two numbers at the top of stack A
- sb : swap the first two numbers at the top of stack B
- pa : pop the first node from stack A and push it into stack B
- pb : pop the first node from stack B and push it into stack A
- ra : rotate the stack A, first number becomes the last
- rb : rotate the stack B, first number becomes the last
- rr : ra and rb at the same time
- rra : reverse rotate the stack A, last number becomes the first
- rrb : reverse rotate the stack B, last number becomes the first
- rrr : rra and rrb at the same time

For example, for stack A \[ 3 2 1 \] -> sa -> \[ 2 3 1 \] -> rra -> \[ 1 2 3 \] -> sorted

The **Goal** is to sort the stack with as few steps as possible.

## Solution
This implementation uses the [turk sort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by Ogun.
The strategy is to keep searching and pushing the value that would take the fewest steps before it could be
pushed into stack B in descending order. Eventually, the stack is pushed back into A and becomes ascending
order. 

**Optimization**: Turk sort works great with relatively smaller stacks (100s), but as the stack size grows,
it becomes slower and and slower at the end since it inevitably takes many rotations before a node can be 
pushed into the correct position. In this implementation, when the stack B is much larger (10 times) than
stack A, the program chooses to sort all the rest values in stack A independently. This auxiliary small-chunk
sort can be further optimized, but since it only takes a small portion of the algorithm, the impact would be
less significant.

## Final Score
- For 100 elements, it takes on average 550 steps to sort.
- For 500 elements, it takes on average 4950 steps to sort.
