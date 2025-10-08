/* Write your PL/SQL query statement below */
SELECT NAME AS "Customers"
from customers
where id != ALL(
    SELECT CUSTOMERID
    FROM ORDERS
);