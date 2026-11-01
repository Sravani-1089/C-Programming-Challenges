Challenge Objective
Campus security has divided a high-traffic area into an N × N grid. Each cell stores a risk score from a sensor: 0 means no
risk and 100 means the highest risk. You must build a C program called GRIDWATCH that traverses the grid in different
ways to identify risky zones and recommend a response. This is not just a maximum-value problem: your solution must
correctly analyse rows, columns, diagonals, boundaries, and neighbouring cells.

Algorithm

1. Start.
2. Read grid size N and validate it (3 to 6).
3. Read grid values and validate them (0 to 100).
4. Read threshold T and validate it (1 to 100).
5. Calculate row totals and find the highest row total.
6. Calculate column totals and find the highest column total.
7. Find the highest risk score, its positions, and count cells >= T.
8. Calculate both diagonal sums and compare them.
9. Calculate the boundary sum.
10. Find local hotspots by checking their four neighbours.
11. Display all hotspots or a message if none exist.
12. Display CRITICAL, WARNING, or NORMAL based on the conditions.
13. Stop.
