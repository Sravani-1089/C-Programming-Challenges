 Algorithm  
1.	Start.
2.	Declare variables for expense amount, category totals, total expenses, average, and counters. Initialize all totals and counters to zero.
3.	Read the expense amount from the user.
4.	If the amount is 0, stop accepting input and go to Step 10.
5.	If the amount is negative, display an invalid expense message and go back to Step 3.
6.	If the amount is less than 100, classify it as Small and update its count and total.
7.	Otherwise, if the amount is less than 500, classify it as Medium and update its count and total.
8.	Otherwise, classify it as Large and update its count and total. Update the valid expense count and overall total for every valid expense.
9.	Go back to Step 3 and continue accepting expenses.
10.	Display the valid expense count, total expenses, and the count and total for each category.
11.	If the valid expense count is greater than zero, calculate and display the average. Otherwise, display “No valid expenses entered.”
12.	Stop.
