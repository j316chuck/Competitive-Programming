select * from records WHERE name = supervisor
select name from records WHERE salary > 50000 ORDER BY name 
SELECT employee, salary, supervisor, from records as a, records as b WHERE a.supervisor = b.name and b.salary > 2* a.salary
select b.name from records as a, records as b WHERE a.supervisor = b.name and b.supervisor!= b.name;
from meetings as a, records as b, records as c WHERE b.supervisor = c.name and 