# Grid Color Restoration

## Problem Statement

You are studying an ancient civilization's color-changing grid system. The system consists of an N×M grid where each cell contains one of K possible colors (numbered 1 to K).

The grid follows a peculiar evolution rule: Every second, **exactly one cell** changes its color. The cell that changes is determined by a specific pattern:
- At time t=1, the cell at position (1, 1) changes to a new color
- At time t=2, the cell at position (1, 2) changes
- The pattern continues row by row: (1,3), (1,4), ..., (1,M), (2,1), (2,2), ..., (N,M)
- After reaching (N,M), it wraps back to (1,1)

When a cell changes color, it becomes a color **different** from its current color (chosen uniformly at random from the K-1 other colors).

You have discovered Q ancient "snapshots" - each snapshot tells you that at time T_i, the cell at position (R_i, C_i) had color COL_i.

Your task: Determine if there exists a valid initial configuration (time t=0) of the grid that is consistent with all Q snapshots. If yes, output any valid initial configuration. If multiple valid configurations exist, output any one.

## Input Format

The first line contains four integers: N, M, K, Q (2 ≤ N, M ≤ 1000, 2 ≤ K ≤ 10^9, 1 ≤ Q ≤ min(200000, N×M))
- N: number of rows
- M: number of columns  
- K: number of possible colors
- Q: number of snapshots

The next Q lines each contain four integers: T_i, R_i, C_i, COL_i (0 ≤ T_i ≤ 10^18, 1 ≤ R_i ≤ N, 1 ≤ C_i ≤ M, 1 ≤ COL_i ≤ K)
- T_i: the time of the snapshot
- R_i, C_i: the position of the cell
- COL_i: the color of that cell at that time

## Output Format

If no valid initial configuration exists, output a single line: `IMPOSSIBLE`

Otherwise, output `POSSIBLE` on the first line, followed by N lines each containing M space-separated integers representing the colors of the grid at time t=0.

## Constraints

- 2 ≤ N, M ≤ 1000
- 2 ≤ K ≤ 10^9
- 1 ≤ Q ≤ min(200000, N×M)
- 0 ≤ T_i ≤ 10^18
- 1 ≤ R_i ≤ N, 1 ≤ C_i ≤ M
- 1 ≤ COL_i ≤ K
- Memory limit: 256 MB
- Time limit: 2 seconds

## Examples

### Example 1
**Input:**
```
2 2 3 3
0 1 1 1
1 1 1 2
2 1 2 1
```

**Output:**
```
POSSIBLE
1 1
1 1
```

**Explanation:**
- At t=0: Grid is [[1,1],[1,1]]
- At t=1: Cell (1,1) changes from 1 to 2: [[2,1],[1,1]]
- At t=2: Cell (1,2) changes from 1 to 1 (wraps around to 1): [[2,1],[1,1]]

Actually, cell (1,2) must change to something different, so:
- At t=2: Cell (1,2) changes from 1 to something ≠ 1

Let me reconsider...

### Example 1 (Corrected)
**Input:**
```
2 2 3 2
0 1 1 1
1 1 1 2
```

**Output:**
```
POSSIBLE
1 1
1 1
```

### Example 2
**Input:**
```
2 2 3 3
0 1 1 1
1 1 1 1
2 1 2 1
```

**Output:**
```
IMPOSSIBLE
```

**Explanation:**
At t=0, cell (1,1) is color 1.
At t=1, cell (1,1) must change to a different color (not 1), but the snapshot says it's still 1.
This is impossible.