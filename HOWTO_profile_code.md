# HOWTO Profile Code

[Profiling Software](https://en.wikipedia.org/wiki/Profiling_(computer_programming)) measures the space (memory) or time complexity of a program, the usage of particular instructions, or the frequency and duration of function calls. Most commonly, profiling information serves to aid program optimization.

**A note on compiler optimization:** 
Compilers use [code optimization](https://en.wikipedia.org/wiki/Optimizing_compiler) ([GCC optimizations](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)).
In VS Code, compile the code using in the bottom bar `CMake:[Release]` (i.e., with speed optimization) instead of `CMake: [Debug]` (optimizer disabled). 


Several open-source and commercial profilers are available (see [List of performance analysis tools](https://en.wikipedia.org/wiki/List_of_performance_analysis_tools)). Here I use 
`callgrind` and `KCachegrind`. Alternatives are [`perf`](https://perf.wiki.kernel.org/) for Linux and WSL2, and  [Dtrace](http://dtrace.org/blogs/about/) for MacOS.

Details on `callgrind` can be found in the [callgrind manual](https://developer.mantidproject.org/ProfilingWithValgrind.html). callgrind records each function call and how many machine code instructions were fetched. It can also calculate approximate run time by translating the instructions into cycle estimates.

### How to use callgrind/KCachgrind to Profile Runtime

**Installation:** You need to install `valgrind` and `KCachgrind` on your machine (Linux, WSL2; not available for Mac; for use on SMU's genuse machines, you need to [set up putty and VNC](https://www.smu.edu/OIT/Services/genuse)).

1. Run your executable with `valgrind`:
   ```
   valgrind --tool=callgrind --dump-instr=yes --simulate-cache=yes --collect-jumps=yes ./<executable> [args...]
   ```

2. This will produce a `callgrind.out.xxxxx` file. Open the file with:
   ```
   kcachegrind callgrind.out.xxxxx
   ```

3. Find the file/class you are interested in (e.g., `main.cpp`), click on the function below and choose [`Call Graph`](https://en.wikipedia.org/wiki/Call_graph) in the bottom right window. You should now see what gets called, how often, and how long it takes (in % of the caller). By default only calls that take long are shown. You can change his by right-click on the graph `Graph > Min. Node Cost`. 
4. Identify the functions that takes the most time and are called often. Optimize the code (loops, used algorithms, and data structure) there and profile again to se if and by how much you have improved the runtime (this can be judged by the number of instructions fetched).

## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)
