Challenge Objective
Create a menu-driven C program that lets a user choose a mathematical operation. After each operation, display the menu again. The program
must stop only when the user selects Exit.

Algorithm

1. Start
2. Start a repeating loop.
3. Show the menu and ask the user to choose an option (1 to 4).
4. If the user picks 1 (Linear Equation):
 • Get a and b.
 • If a is not 0, answer is -b / a.
 • If a is 0, print "No solution" or "Infinite solutions".
5. If the user picks 2 (Factorial):
 • Get a number between 0 and 12.
 • Multiply numbers from 1 up to that number and print the result.
6. If the user picks 3 (Quadratic Equation):
 • Get a, b, and c. (Make sure a is not 0).
 • Find D = b² - 4ac.
 • If D > 0, print 2 roots.
   If D = 0, print 1 root.
   If D < 0, print "No roots".
8. If the user picks 4 (Exit): break the loop.
9. If they pick anything else, show an error and repeat the loop.
10. Stop.
    
