Algorithm: SMARTCART

1. Start.
2. Read the purchase amount, customer type (1 for Student, 2 for Regular Customer), and delivery distance in kilometres.
3. If the customer is a Student:
   - If the purchase amount is greater than or equal to ₹2000, calculate a 15% discount.
   - Otherwise, calculate a 10% discount.
4. Else, if the customer is a Regular Customer:
   - If the purchase amount is greater than or equal to ₹3000, calculate an 8% discount.
   - Otherwise, the discount is 0.
5. Calculate the amount after discount by subtracting the discount from the purchase amount.
6. If the delivery distance is less than or equal to 5 km, set the delivery charge to ₹40.
7. Else, if the distance is less than or equal to 15 km, set the delivery charge to ₹70.
8. Otherwise, set the delivery charge to ₹100.
9. Calculate the final payable amount by adding the delivery charge to the amount after discount.
10. Display the purchase amount, discount amount, amount after discount, delivery charge, and final payable amount.
11. Stop.
