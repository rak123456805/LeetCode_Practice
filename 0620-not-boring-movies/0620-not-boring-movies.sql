# Write your MySQL query statement below
select c.id,c.movie,c.description,c.rating
from Cinema c
where mod(id,2)<>0 
and description <>'boring'
order by c.rating desc