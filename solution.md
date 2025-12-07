# Solution Explanation

## Key Observations

1. **Cell Update Pattern**: The cell that updates at time t can be calculated as:
   - Let `pos = (t-1) mod (N×M) + 1` (1-indexed position in flattened grid)
   - Row = `(pos-1) / M + 1`
   - Col = `(pos-1) % M + 1`

2. **Constraint Propagation**: If we know cell (r,c) has color X at time T1 and color Y at time T2 where T1 < T2:
   - We need to check how many times this cell was updated between T1 and T2
   - If updated an odd number of times: Y must ≠ X (changed once or more odd times)
   - If updated an even number of times (including 0): Y must = X (back to original or never changed)

3. **Working Backwards**: From any constraint at time T, we can deduce constraints at time 0 by checking:
   - How many times was cell (r,c) updated from time 0 to time T?
   - If even: color at t=0 must equal color at t=T
   - If odd: color at t=0 must differ from color at t=T (but we don't know what it is specifically unless K=2)

## Algorithm

### Step 1: Group Snapshots by Cell
For each cell, collect all snapshots involving that cell and sort by time.

### Step 2: Validate Temporal Consistency
For each cell's snapshot sequence:
- For consecutive snapshots at times T1 and T2 with colors C1 and C2:
  - Calculate updates_between = number of times cell was updated in (T1, T2]
  - If updates_between is even: require C1 = C2
  - If updates_between is odd: require C1 ≠ C2
- If any constraint is violated, return IMPOSSIBLE

### Step 3: Deduce Initial Colors
For each cell with at least one snapshot:
- Take the earliest snapshot at time T with color C
- Calculate updates_from_zero = number of updates from time 0 to time T
- If updates_from_zero is even: initial_color = C
- If updates_from_zero is odd:
  - If K = 2: initial_color = (C == 1) ? 2 : 1
  - If K > 2: initial_color can be any color ≠ C (pick color 1 if C ≠ 1, else pick color 2)

### Step 4: Fill Remaining Cells
For cells with no constraints, assign any valid color (e.g., color 1).

## Complexity Analysis

- **Time Complexity**: O(Q log Q + N×M)
  - Sorting snapshots: O(Q log Q)
  - Processing each snapshot: O(1) per snapshot
  - Filling grid: O(N×M)
  
- **Space Complexity**: O(Q + N×M)
  - Storing snapshots and grid

## Implementation Details

Key helper function:
```cpp
long long count_updates(long long from_time, long long to_time, int r, int c, int N, int M) {
    // Calculate how many times cell (r,c) was updated in time range (from_time, to_time]
    // Cell (r,c) is at position: pos = (r-1)*M + c (1-indexed)
    // This cell updates at times: pos, pos + N*M, pos + 2*N*M, ...
    
    long long total_cells = (long long)N * M;
    long long cell_pos = (long long)(r-1) * M + c;
    
    // First update time for this cell
    long long first_update = cell_pos;
    
    if (first_update > to_time) return 0;
    if (first_update <= from_time) first_update = from_time + 1;
    
    // Count updates in [first_update, to_time]
    // These occur at: first_update, first_update + total_cells, ...
    // Formula: floor((to_time - first_update) / total_cells) + 1
}
```

---

## requirements.json

```json
{
  "time": 2,
  "space": 256,
  "judging": {
    "checker": "standard",
    "validator": "standard"
  }
}
```