# Problem: Cyclic Subsegment Balancing

## Problem Statement

You are given a circular array a of n integers (where a[n] is followed by a[1]).

A subsegment of the circular array is called balanced if:
1. It has even length
2. You can partition its elements into pairs such that both elements in each pair are equal

Note: A subsegment in a circular array can wrap around. For example, if n=5, the subsegment from position 4 to position 2 (with length 4) contains elements: a[4], a[5], a[1], a[2].

Your task is to count the total number of balanced subsegments. Two subsegments are considered different if they start at different positions OR have different lengths, even if they contain the same sequence of elements.

## Input Format

The first line contains a single integer n (2 ≤ n ≤ 3000) — the length of the array.

The second line contains n integers a₁, a₂, ..., aₙ (1 ≤ aᵢ ≤ 10⁹) — the elements of the circular array.

## Output Format

Print a single integer — the number of balanced subsegments.

## Examples

### Example 1
Input:
4
1 2 1 2

Output:
4

Explanation:
For the array [1, 2, 1, 2]:
- Length 4 subsegments (all contain 1,1,2,2):
  - Starting at position 0: [1,2,1,2] ✓
  - Starting at position 1: [2,1,2,1] ✓
  - Starting at position 2: [1,2,1,2] ✓
  - Starting at position 3: [2,1,2,1] ✓
Total: 4 balanced subsegments

### Example 2
Input:
5
3 3 3 1 1

Output:
6

Explanation:
- Start 0, len 2: [3,3] ✓
- Start 1, len 2: [3,3] ✓
- Start 1, len 4: [3,3,1,1] ✓
- Start 2, len 4: [3,1,1,3] ✓
- Start 3, len 2: [1,1] ✓
- Start 3, len 4: [1,1,3,3] ✓
Total: 6 balanced subsegments

### Example 3
Input:
6
5 5 5 5 5 5

Output:
18

Explanation:
All elements are the same.
- Length 2: 6 subsegments
- Length 4: 6 subsegments
- Length 6: 6 subsegments
Total: 18 balanced subsegments

### Example 4
Input:
2
1 1

Output:
2

Explanation:
For array [1, 1]:
- Starting at position 0, length 2: [1,1] ✓
- Starting at position 1, length 2: [1,1] ✓ (wraps around to same elements)
Total: 2 balanced subsegments (counted separately by starting position)

## Notes

- A subsegment must contain at least 2 elements
- Each (start position, length) pair defines a unique subsegment
- The array is circular, so indices wrap around