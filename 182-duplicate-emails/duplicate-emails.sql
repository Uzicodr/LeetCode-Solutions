/* Write your PL/SQL query statement below */
SELECT EMAIL
from person
group by email
having count(email)>1;