# 1-to-4 Demultiplexer

Console program in C for a METU NCC course. A 1-to-4 demultiplexer sends one data bit to one of four outputs. The two select bits choose the output; the others stay `0`.

| S1 | S0 | Data | Active output |
| --- | --- | --- | --- |
| 0 | 0 | D | Y0 = D |
| 0 | 1 | D | Y1 = D |
| 1 | 0 | D | Y2 = D |
| 1 | 1 | D | Y3 = D |

## How to use it

1. Choose `a` to compute, or `b` to quit.
2. Choose base `2` or base `10`.
3. Enter three bits, select then data: `S1 S0 D`.

In base 2, type exactly three characters of `0` or `1` and press Enter once (for example `101`). In base 10, enter an integer from `0` to `7`. The program splits that value into the same three bits and prints `Y3 Y2 Y1 Y0`.

## Build and run

```bash
gcc main.c -o demultiplexer
./demultiplexer
```
