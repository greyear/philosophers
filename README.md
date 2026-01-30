# Philosophers – Dining Philosophers Problem
## Overview

The Philosophers project is a classic synchronization problem implementation in C, simulating the dining philosophers problem using threads and mutexes. 

The problem consists of philosophers sitting at a round table who must eat, think, and sleep. Each philosopher needs two forks to eat, but there are only as many forks as there are philosophers. The challenge is to prevent deadlocks and starvation while ensuring proper resource sharing.

This implementation uses:
- **Threads** to simulate concurrent philosopher actions
- **Mutexes** to protect shared resources (forks)
- **Precise timing** to track philosopher states and prevent race conditions

## Getting Started

1) Build
	```
	make
	```

2) Run
	```
	./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
	```

	**Arguments:**
	- `number_of_philosophers` — the number of philosophers and also the number of forks
	- `time_to_die` — time in milliseconds. If a philosopher doesn't start eating within this time since the beginning of their last meal, they die
	- `time_to_eat` — time in milliseconds it takes for a philosopher to eat (during which they hold two forks)
	- `time_to_sleep` — time in milliseconds a philosopher spends sleeping
	- `number_of_times_each_philosopher_must_eat` — (optional) simulation stops when all philosophers have eaten at least this many times. If not specified, simulation runs until a philosopher dies

## Examples

**Basic simulation with 5 philosophers:**
```
./philo 5 800 200 200
```

**Simulation that stops after each philosopher eats 7 times:**
```
./philo 5 800 200 200 7
```

**Test with parameters where no philosopher should die:**
```
./philo 4 410 200 200
```

**Single philosopher (should die):**
```
./philo 1 800 200 200
```

## Expected Output

The program displays timestamped messages for each philosopher action:

```
[timestamp_in_ms] [philosopher_id] has taken a fork
[timestamp_in_ms] [philosopher_id] is eating
[timestamp_in_ms] [philosopher_id] is sleeping
[timestamp_in_ms] [philosopher_id] is thinking
[timestamp_in_ms] [philosopher_id] died
```

**Example:**
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
400 1 is thinking
...
```

## Rules & Constraints

- One or more philosophers sit at a round table with a large bowl of spaghetti in the center
- There are as many forks on the table as there are philosophers
- A philosopher needs two forks to eat (one on their left and one on their right)
- Philosophers can only do one thing at a time: eat, sleep or think
  - **Eating:** philosopher takes their right and left forks and eats for `time_to_eat` milliseconds
  - **Sleeping:** philosopher sleeps for `time_to_sleep` milliseconds
  - **Thinking:** philosopher thinks until they can take two forks again
- Each philosopher is represented by a thread
- Forks are protected by mutexes to prevent race conditions
- The simulation stops when a philosopher dies or when all philosophers have eaten the required number of meals

## Implementation Details

### Key Features
- **Thread-safe operations** using mutexes for forks and shared data
- **Precise time tracking** with microsecond accuracy
- **Death detection** monitoring philosopher states in the main thread
- **Graceful termination** with proper resource cleanup
- **Data race prevention** through careful mutex usage

## Compilation

Compilation flags: `-Wall -Wextra -Werror -pthread`

## Author

[@Anya Zinchenko](https://github.com/greyear)
