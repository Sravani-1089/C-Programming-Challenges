Challenge Objective 
 
A campus event uses ticket IDs from 1 to N. The scanner records N entries, but one ticket ID is missing and another ticket ID has been scanned
twice. Your job is to audit the scan log, identify the missing and duplicate IDs, and measure how far the scan sequence is out of order. Plan you
logic before writing code.

Algorithm

1.	Start.
2.	Declare a one-dimensional array and the required variables.
3.	Read N and check that it is between 5 and 15. Ask again if it is invalid.
4.	Read the ticket IDs and check that each is between 1 and N. Ask again if an ID is invalid.
5.	Display the original ticket sequence.
6.	Count the occurrences of each ID to find the missing and duplicate IDs.
7.	Check whether the scan log is valid; otherwise, display an invalid scan log message.
8.	Count the out-of-order pairs using nested loops.
9.	Calculate the target ID using (R % N) + 1.
10.	Display the missing ID, duplicate ID, out-of-order pair count, target ID, all target positions, and target occurrence count.
11.	Stop.
