select * from records WHERE supervisor = name 
select names from records WHERE salary > 50000

Name Division Title Salary Supervisor
Ben Bitdiddle Computer Wizard 60000 Oliver Warbucks
Alyssa P Hacker Computer Programmer 40000 Ben Bitdiddle
Cy D Fect Computer Programmer 35000 Ben Bitdiddle
Lem E Tweakit Computer Technician 25000 Ben Bitdiddle
Louis Reasoner Computer Programmer Trainee 30000 Alyssa P Hacker
Oliver Warbucks Administration Big Wheel 150000 Oliver Warbucks
DeWitt Aull Administration Secretary 25000 Oliver Warbucks
Eben Scrooge Accounting Chief Accountant 75000 Oliver Warbucks
Robert Cratchet Accounting Scrivener 18000 Eben Scrooge

Division Day Time
Accounting Monday 9am
Computer Wednesday 4pm
Administration Monday 11am
Administration Thursday 1pm

select a.name, a.salary, b.name, b.salary
from records as a, records as b WHERE a.supervisor = b.name and b.salary > 2 * a.salary;

select a.name from records as a, records as b where a.supervisor = b.name and b.division != a.division;

select b.day, b.time from records as a, time as b
WHERE a.supervisor = "Oliver Warbucks" and a.division = b.division

select b.name from records as a, records as b WHERE a.supervisor = b.name and b.supervisor != b.name; 

Ben Bitdiddle
Alyssa P Hacker
Eben Scrooge


select a.name from records as a, records as b, meetings as c, meetings as d 
WHERE a.supervisor = b.name and a.division = c.division and b.division = d.division
and d.day = c.day 

create table factorials as
	with ints(n) as(
		select 1 union 
		select n+1 from ints where n < 10
	)
	with factorial(m) as (
		select 1 union
		select n * m from ints, factorial 
	)

create table fibonacci as 
	with fib(prev, curr) as (
		select 0, 1 union
		select curr, prev+curr from fib
	)

	with fact(n, nfact) as (
		select 0, 1 union
		select n+1, (n+1) * nfact from fact where n < 10 
	)
	select nfact from fact;

	selct nfact from fact;

create table squares as
	with square(x, xx) as (
		select 1, 1 union
		select x+1, xx+1 * xx+1 from square 
		where n < 10
	)
	select s from sq;