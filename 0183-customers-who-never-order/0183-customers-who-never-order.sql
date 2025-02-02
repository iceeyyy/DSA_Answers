# Write your MySQL query statement below
select C.name  as customers from Customers AS C 
LEFT JOIN Orders AS O ON C.id=O.customerId
where O.customerId is NULL;


