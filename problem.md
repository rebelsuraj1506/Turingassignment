# Problem: Cyclic Subsegment Balancing

## Problem Statement

You are given a circular array **a** of **n** integers (where **a[1]** follows **a[n]**).

A subsegment of the circular array is called **balanced** if:
1. It has even length
2. You can partition its elements into pairs such that both elements in each pair are equal

Note: A subsegment in a circular array can wrap around. For example, if n=5, the subsegment from position 4 to position 2 contains elements: a[4], a[5], a[1], a[2].

Your task is to count the number of balanced subsegments in the circular array.

## Input Format

The first line contains a single integer **n** (2 ≤ n ≤ 3000) — the length of the array.

The second line contains **n** integers **a₁, a₂, ..., aₙ** (1 ≤ aᵢ ≤ 10⁹) — the elements of the circular array.

## Output Format

Print a single integer — the number of balanced subsegments.

## Examples

### Example 1
**Input:**
```
4
1 2 1 2
```

**Output:**
```
4
```

**Explanation:**
The balanced subsegments are:
- [1,1] (positions 1-3): can be partitioned into {1,1}
- [2,2] (positions 2-4): can be partitioned into {2,2}
- [1,2,1,2] (positions 1-4): can be partitioned into {1,1} and {2,2}
- [2,1,2,1] (positions 2-1): can be partitioned into {1,1} and {2,2}

### Example 2
**Input:**
```
5
3 3 3 1 1
```

**Output:**
```
3
```

**Explanation:**
- [3,3] at positions (1,2): {3,3}
- [3,3] at positions (2,3): {3,3}
- [1,1] at positions (4,5): {1,1}

### Example 3
**Input:**
```
6
5 5 5 5 5 5
```

**Output:**
```
9
```

## Notes

- A subsegment must contain at least 2 elements
- Two subsegments are different if they start at different positions or have different lengths
- Remember that the array is circular