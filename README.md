# 📚 Library Simulation

This is a project simulating the functionality of a bookcase. The bookcase consists of the following:
- A top shelf
- A middle shelf
- A bottom shelf
- A cabinet with 2 shelves
- A base

<img align="right" width="120" height="130" src="https://github.com/joannakonte/Bookcase-Simulation/blob/main/images/bookcase.png">

<br>

The library consists of N books at anytime. Each shelf has maximum capacity of N_Max books.

## Makefile

Use the Makefile to compile, run and clean using the following commands:

```bash
$ make 
$ make run
$ make clean
```

**Note:** "make run", does the following: `$ ./libsim 100 20 10 2`

If you want to enter your own argument values, run the executable manually, by giving in terminal the following:

```bash
$ ./libsim <N_Max> <L> <K1> <K2>

```

**Where:**
- **N_Max:** max capacity of shelves
- **L:** number of books
- **K1:** number of placements
- **K2:** number of removals
