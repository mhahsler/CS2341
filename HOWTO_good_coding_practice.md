# HOWTO Good Coding Practice

## Dos

* **Make a design document fist** (e.g., UML class diagram, what data structures to use and why), 
  then implement and update your UML diagram when you make changes.
  Remember, each class should implement one "real object." and each function should only do one thing and not more.
* **Break the project into small parts (features).** Implement one feature at a time. After each feature, your code should compile, the tests should run without errors, and you should commit your changes to GitHub. 
* **Use comments** to structure your code (e.g., if there are multiple steps) and to explain more difficult parts and design choices.
* **Format your code** using appropriate indentations and lines that are not too long (most IDEs have a reformat option). 
* **Refacture constantly:** Improve your code constantly by rewriting parts of it to improve code quality, reusability, and performance. 


## Don'ts

* **Don't use non-standard language or compiler extensions** (e.g., `#pragma once`). These create a reliability and portability problem.
* **Don't ignore compiler warnings.** All ways turn compiler warnings on. These are typically an indication that your code will not be reliable, portable, and may contains memory management issues that will show up later.
* **Don't write complicated code.** The need for complicated code is is typically the result of bad design.
* **Don't use multiple copies of the same or slightly modified code in your project.** This creates a maintenance nightmare. Rethink your design.
* **Don't use code you find without completely understanding it.** The code might not exactly do what you need, introduce bugs into your code, or even be malicious. 