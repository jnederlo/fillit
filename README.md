# fillit

Fillit is a project at 42 School USA where we have to take a list of Tetriminos and arrange them to create the smallest square possible.

To complete the task we are allowed to use the exit, open, close, write, read, malloc, and free functions, and of course our created library.

Specifically, our executable must take as a parameter one (and only one) file which contains a list of Tetriminos to arrange. Every Tetriminos will consist of 4 lines and each Tetriminos is seperated by an empty line.

A few examples of valid descriptions of Tetriminos:

! [alt text](samples/sample_tetriminos.png)

In this problem we cannot rotate the tetriminos, and among the different solutions possible, we must make the smallest square possible where the Tetriminos are placed in their most upper-left position (in the order as they appear in the file).

The program must display the smalles square solution on the standard output. To identify each Tetriminos in the square solution, we must assign a capital letter (starting with 'A') to each Tetriminos in the order they appear in the file.

The file can contain up to a maximum of 26 Tetriminos.

We created a flowchart to demonstrate the different steps that we identified required to complete the stated problem:

![alt text](Fillit.png)
