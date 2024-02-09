# Time Complexity Example: Bubble Sort

Set launch target to `bubble_sort_timing` (see targets in `CMakeLists.txt`). 

## Analyze Runtime Directly

1. Run `./bubble_sort_timing` and look at the output. 
2. How does the runtime increase with $N$?

## Analyze Runtime with Excel

1. Run `./bubble_sort_timing  > output.csv`
2. Open `output.csv` in Excel. 
3. Remove all 0s (Excel trendlines don't work with 0s).
4. Make a chart using "scatterplot with lines" (make sure $N$ is on the x-axis).
5. Add a trendline (turn on the equation and R-squared) and play with the power for polynomial trendlines.

Here is an example: [timing.xlsx](timing.xlsx)


## Implementation Note

The implementations are how you typically see them with C arrays. 
[main_STL.cpp](main_STL.cpp) has a better C++ implementation using the STL and
avoiding the ugly memory management issues. 
