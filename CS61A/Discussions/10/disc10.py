create

select [column description] from [existing table name]


create table cities as
	select 38 as latitude, 122 as longitude, "berkeley" as name union
	select 42, 71, "Cambrdige" union
	select 45, 93, "Minneapolis";

create table names as 
	select "west coast" as region, name from cities where longitude >=>=115 union
	select "ohter", name from cities where longitude < 115;

select [expression] as [name], expression as name
select columns from table where [condition] order by order:
select child from parents where parent = "abraham"


create table cities as
	select 38 as latitude, 122 as longitude, "berekely "as name union

select chari, single+2 * couple as total from lift w

create table ints as
	select "zero" as word, 0 as one, 0 as two, 0 as four, 0 as eight union

select word,  one + two + three + four as "value" from tab
select "hello," ||" world";
