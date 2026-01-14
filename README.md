*This project has been created as part of the 42 curriculum by __lpaiva__*

## *DESCRIPTION*

**Push_swap** is a 42 School algorithm project. The goal is to sort data on a stack, with a limited set of instructions.

1. #### **OPERATIONS ALLOWED**

| *COMAND* | *NAME* | *WHAT IT DOES* |
| :-----  | :---    | :---  	     |
|`sa` | **SWAP A** -> Swap the first 2 elements at the top of stack A. |
|`sb` | **SWAP B** -> Swap the first 2 elements at the top of stack B. |
|`ss` | **SWAP A & B** -> does *sa* && *sb* at the same time.          |
|`pa` | **PUSH A** -> puts the first node in *A* on *B*                |
|`pb` | **PUSH B** -> puts the first node in *B* on *A*                |
|`ra` | **Rotate A** -> Shift all elements of stack A up by 1.         |
|`rb` | **Rotate B** -> Shift all elements of stack B up by 1.         |
|`rr` | **Rotate A & B** -> does *ra* && *rb* at the same time.        |
|`rra`| **Rev. Rotate A** -> Shift all elements of stack A down by 1.  |
|`rrb`| **Rev. Rotate B** -> Shift all elements of stack B down by 1.  |
|`rrr`| **Rev. Rotate A & B** -> does *rra* && *rrb* ate the same time.|

---

2. #### **STRUCTURE OF THE PROJECT** 
```
.
|____libft_src
| |____ft_dprintf.c
| |____aux_printf.c
| |____ft_split.c
| |____ft_strndup.c
| |____ft_atol.c
| |____get_next_line.c
| |____get_next_line_utils.c
|____src_pushswap
| |____build_stack.c
| |____oper_stack_a.c
| |____oper_stack_b.c
| |____handler.c
| |____sort_lst_smaller.c
| |____nodes_utils.c
| |____butterfly_sort.c
| |____parser_arr.c
| |____op_both_stacks.c
|____main.c
|____push_swap.h
|____README.md
|____Makefile
|____checker_bonus.c

```

### __*EXPLANATION*__

* #### **ABOUT THE PROJECT**
 
#### *In this secction its the explanation of the code itself, how it workes, what was used and why* 
	. the parser
	. sorting of small lists 
	. sorting algorthim for bigger lists
---

### **THE PARSER** 

This project can be executed in two forms 
 * `./push_swap "12 32 90 5 6"`  
 * `./push_swap 12 32 90 5 6`  

Meaning it can take one single string whith various numbers separated by spaces " " or various strings representing numbers.. and becouse our goal in this project is to organize a list of numbers (`int's`) we need to change the the types of our users input, creating a parser for it.
That parser is constructed with a split and atol 
* the atol is used to check for nunbers bigger or smaller than `INT_MAX` OR `INT_MIN`
* and the split is used if our user input is just one argument whith varios numbers


### __*SORTING LOGIC*__

* ##### **SORTING SMALLER LIST**

Before starting tackling the bigger lists it is needed to be able to sort smaller ones {3 and 5 to be precise} creating a general logic to sort them.
*Logic* =>find the biggest node and see if it is the 1st 2st node if so do ra || rra for the respected case
```

void	sort_lst_3(t_node **lst_a)
{
	t_node	*biggest_node;

	biggest_node = find_max_node(*lst_a);
	if (biggest_node == *lst_a)
		ra(lst_a, 1);
	else if ((*lst_a)->next == biggest_node)
		rra(lst_a, 1);
	if ((*lst_a)->index > (*lst_a)->next->index)
		sa(lst_a, 1);
}
```
*Logic* => reduce the stack a to 3 nbrs and sorted it usind the logic for 3
and sort the stack b if need it 

```
static void	rotate_to_top(t_node **lst, t_node *min, int size)
{
	int	pos;
	int	rev;

	pos = get_pos(lst, min);
	rev = size - pos;
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(lst, 1);
	else
		while (rev-- > 0)
			rra(lst, 1);
}

void	sort_lst_5(t_node **lst_a, t_node **lst_b)
{
	t_node	*min;

	while (lst_size(*lst_a) > 3)
	{
		min = find_min_node(*lst_a);
		rotate_to_top(lst_a, min, lst_size(*lst_a));
		pb(lst_a, lst_b, 1);
	}
	sort_lst_3(lst_a);
	if ((*lst_b)->index && ((*lst_b)->index < (*lst_b)->next->index))
		sb(lst_b, 1);
	while (*lst_b)
		pa(lst_a, lst_b, 1);
}

```

* #### __*Sorting bigger list*__

The sorting algorthm used for bigger list than 5 elements was the butterfly sort algoritm (or the chunks algorithm ) that sorts the main staxk in to phases: 
1. `an optimized distribution from A to B;`
>sending elements to Stack B in "chunks" based on their sorted indices (0 to N). creating a roughly sorted pile in B.
>>Using a *dynamic range* we define a range size (chunk). We iterate through Stack A looking for numbers that fall within 0 to counter + chunk.

2. `a greedy collection back to A.`
> We return elements to Stack A in strict descending order (largest to smallest) so they land in A sorted ascendingly.
>>finding the element with the maximum index currently in B and then calculate the shortest path (rotating up rb or down rrb) to bring that element to the top and push it to A (pa).


### __*Instructions*__
*how to use the push swap program*
```
make #creating the push_swap executable
make bonus #creating the checker executable
--- Runing it 
./push_swap <n random numb`s>
```
### __*RESOURCES*__

#### *References*
* **The Subject**: The official 42 School project documentation.
* **Butterfly Sort Logic**: Articles, GitHub, youtube, 42 colueges and AI
#### *AI usage*
* **Debugging & Memory Leaks**: AI was used to analyze Valgrind output logs to identify specific memory leaks, and cleaning it up.
* **Sorting Logic**: AI helpe me figure out what kind of algorithm to use and how to implemente it 
