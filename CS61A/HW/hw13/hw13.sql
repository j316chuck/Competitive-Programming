create table parents as
  select "abraham" as parent, "barack" as child union
  select "abraham"          , "clinton"         union
  select "delano"           , "herbert"         union
  select "fillmore"         , "abraham"         union
  select "fillmore"         , "delano"          union
  select "fillmore"         , "grover"          union
  select "eisenhower"       , "fillmore";

create table dogs as
  select "abraham" as name, "long" as fur, 26 as height union
  select "barack"         , "short"      , 52           union
  select "clinton"        , "long"       , 47           union
  select "delano"         , "long"       , 46           union
  select "eisenhower"     , "short"      , 35           union
  select "fillmore"       , "curly"      , 32           union
  select "grover"         , "short"      , 28           union
  select "herbert"        , "curly"      , 31;

create table sizes as
  select "toy" as size, 24 as min, 28 as max union
  select "mini",        28,        35        union
  select "medium",      35,        45        union
  select "standard",    45,        60;

-------------------------------------------------------------
-- PLEASE DO NOT CHANGE ANY SQL STATEMENTS ABOVE THIS LINE --
-------------------------------------------------------------

-- The size of each dog
create table size_of_dogs as
  select a.name, b.size FROM dogs as a, sizes as b WHERE a.height > b.min and a.height <= b.max;

-- All dogs with parents ordered by decreasing height of their parent
create table by_height as
  select child FROM dogs, parents WHERE name = parent ORDER BY height DESC;

create table sentences as 
  with siblings(first, second, h1, h2) as (
  select a.child, b.child, c.height, d.height FROM parents as a, parents as b, dogs as c, dogs as d 
  WHERE a.child < b.child and a.parent = b.parent and c.name = a.child and d.name = b.child
  )
  select first || " and " || second || " are " || size ||" siblings" from siblings, sizes
  WHERE h1 > min and h1 <= max and h2 > min and h2 <= max;
 
-- Ways to stack 4 dogs to a height of at least 170, ordered by total height
--create table stacks as
--  select a.name ||", "|| b.name ||", "||c.name||", "||d.name, a.height+b.height+c.height+d.height
--  FROM dogs as a, dogs as b, dogs as c, dogs as d WHERE a.height < b.height and b.height < c.height and c.height < d.height 
-- and a.height+b.height+c.height+d.height > 170 ORDER BY a.height+b.height+c.height+d.height;
create table stacks as
  with new(stack, h, total, num_of_dogs) as (
      select name, height, height, 1 from dogs union
      select stack || ", " || name, height, total+height, num_of_dogs+1 from dogs, new WHERE height > h and num_of_dogs < 4
  )
  select stack, total from new WHERE total > 170 ORDER BY total;
-- non_parents is an optional, but recommended question
-- All non-parent relations ordered by height difference
create table non_parents as
  with 
  grandparents(child, gp) as (
    select a.child, b.parent FROM parents as a, parents as b WHERE a.parent = b.child
  ), 
  ancestors(c, g) as (
    select child, gp from grandparents union
    select c, parent from ancestors, parents WHERE g = child
  ),
  ancestor(c, g) as (
    select c, g from ancestors union
    select g, c from ancestors
  )
  select c, g from ancestor, dogs as a, dogs as b WHERE a.name = c and b.name = g ORDER BY a.height-b.height ASC;

create table ints as
    with i(n) as (
        select 1 union
        select n+1 from i limit 100
    )
    select n from i;

create table divisors as
    with divisors(a, b) as (
        select a.n, b.n from ints as a, ints as b WHERE b.n <= a.n and a.n % b.n == 0 ORDER BY a.n ASC
    )
    select a, count(*) as count from divisors GROUP BY a;

create table primes as
    select a from divisors where count = 2;
