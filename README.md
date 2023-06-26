<p align="center">
  <img src="https://github.com/LaOuede/42-project-badges/blob/main/badges/push_swape.png" />
</p>

<h1 align=center>Push Swap</h1>

<p align=center>
  <b>Push Swap</b> is a sorting algorithm project that aims to arrange a stack of numbers in ascending order using two stacks, a limited set of operations and the lowest possible number of actions.
  This challenge tests problem-solving skills, algorithmic thinking, and proficiency with complex data structures.
  The goal is to devise an efficient strategy to minimize the number of moves required, optimizing space complexity.
</p>

<div align="center">

Go to [42 Québec](https://42quebec.com/) to discover the course ! 👈
</div>

---

<h3 align="left">What I've learned</h3>

I've acquired a lot of basic knowledge on C programming :
- Problem-solving
- Algorithmic thinking
- Data structures (linked list)
- Optimization
- Attention to detail
- Debugging and troubleshooting
- Testing and validation
- Code readability

---

<h3 align="left">If I had to do it all over again</h3>

- I chose to implement an algorythm based on economy of movement, moving each time the number that requires the fewest movements.
  So I would challenge myself by implementing a new algorythm based on "divide and conquer algorythm" which is more focused on time management.
- I would use free_null instead of free to set pointers to NULL to prevent accidental access to freed memory

---

<h3 align="left">Usage</h3>

- compilation :
```bash
make
```
- execution :
```bash
./push_swap <list of numbers>
```
Numbers can be positive or negative integers.

- return value :

If the arguments are valid, the program will output is a series of instructions or operations that need to be performed on the given stack of numbers in order to sort them in ascending order.
Each instruction represents a specific operation on the stacks, such as swapping two numbers, rotating the stack, or pushing a number from one stack to another.

- Visualizer :

It's possible to see the rendering of movements by using this visualizer : [o-reo visualizer](https://github.com/o-reo/push_swap_visualizer)

![](https://i.imgur.com/zqcsZfY.png)

---

<h3 align="left">Rules of the project</h3>

The Push Swap program operates with two stacks: stack A and stack B. Initially, all numbers are placed in stack A, while stack B remains empty.

- Actions allowed
<table>
  <tr>
    <th>Name</th>
    <th>Description</th>
  </tr>
	<tr>
	<td align="center">pa</td>
        <td>Pushing the top element from stack B to stack A</td>
      </tr>
      <tr>
        <td align="center">pb</td>
        <td>Pushing the top element from stack A to stack B</td>
      </tr>
      <tr>
         <td align="center">sa</td>
         <td>Swapping the top two elements of stack A</td>
      </tr>
      <tr>
         <td align="center">sb</td>
         <td>Swapping the top two elements of stack B</td>
      </tr>
      <tr>
         <td align="center">ss</td>
      <td>Swapping the top two elements of both stacks simultaneously</td>
      </tr>
      <tr>
         <td align="center">ra</td>
         <td>Rotating stack A by shifting all elements up by one</td>
      </tr>
      <tr>
         <td align="center">rb</td>
         <td>Rotating stack B by shifting all elements up by one</td>
      </tr>
      <tr>
         <td align="center">rr</td>
         <td>Rotating both stacks simultaneously</td>
      </tr>
      <tr>
         <td align="center">rra</td>
         <td>Reverse rotating stack A by shifting all elements down by one</td>
      </tr>
        <tr>
         <td align="center">rrb</td>
         <td>Reverse rotating stack B by shifting all elements down by one</td>
      </tr>
      <tr>
         <td align="center">rrr</td>
         <td>Reverse rotating both stacks simultaneously</td>
      </tr>
</table>


- Movement restrictions
<table>
	<tr>
	<td align="center">Sorting 3 values</td>
        <td>3 movements max</td>
      </tr>
      <tr>
        <td align="center">Sorting 5 values</td>
        <td>12 movements max</td>
      </tr>
      <tr>
         <td align="center">Sorting 100 values</td>
         <td> < 700 mov. = 5 pts</td>
         <td> < 900 mov. = 4 pts</td>
         <td> < 1100 mov. = 3 pts</td>
         <td> < 1300 mov. = 2 pts</td>
         <td> < 1500 mov. = 1 pts</td>
      </tr>
      <tr>
         <td align="center">Sorting 500 values</td>
         <td> < 5500 mov. = 5 pts</td>
         <td> < 7000 mov. = 4 pts</td>
         <td> < 8500 mov. = 3 pts</td>
         <td> < 10000 mov. = 2 pts</td>
         <td> < 11500 mov. = 1 pts</td>
      </tr>
</table>

- Score

The project is marked out of 100 pts. The passing score is 80.

---

<div align="center">

To look at [my next 42 project](https://github.com/LaOuede/Minitalk) !
</div>
