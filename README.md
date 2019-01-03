Fillit
========
### 42 - Project #2

Fillit is a recursive backtracking algorithm that fits a set of Tetriminos in the smallest possible square without rotating the Tetriminos. More information can be found on this [PDF].

Here is an example of valid input of 9 Tetriminos (maximum of 26 blocks):

```
....
.##.
.##.
....

...#
...#
...#
...#

....
..##
.##.
....

....
..#.
.##.
.#..

.###
...#
....
....

##..
.#..
.#..
....

....
..##
.##.
....

.#..
.##.
..#.
....

....
###.
.#..
....
```

Solution (each individual tetriminos renamed starting from A):
```
AAB.CCD
AABCCDD
FFB..D.
.FBEEE.
HF.GGE.
HHGGIII
.H...I.
```
How to use:

    git clone https://github.com/bwan-nan/Fillit.git
    choose a map from the tests folder
    ./fillit tests/pdf_example_0.fillit


[PDF]: https://github.com/giacomoguiulfo/fillit/blob/master/fillit.en.pdf
