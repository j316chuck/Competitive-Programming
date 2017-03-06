.read data.sql

-- Q1
create table flight_costs as
  """with costs(d, price, previous) as (
    select 1, 20, 0 union select 2, 30, 20 union select 3, 40, 30 union
    select d+1, (price + previous)/2 + (d + 1)%7 * 5, price from costs WHERE d >= 3 and d+1 <= 25
  )
  select d, price from costs;"""

  """with cost(d, previous, current) as (
      select 1, -1, 20 union
      select 2, 20, 30 union
      select 3, 30, 40 union
      select b.d+1, current, current + previous + (b.d+1+1)%7*5 from cost as b where b.d = d and d+1 <=25
  )
  select d, current from costs;"""
  with costs(day, cur, prev) as (
    select 1, 20, 0 union 
    select 2, 30, 30 union
    select 3, 40, 30 union 
    select day+1, (cur+prev)/2 + ((day+1)%7)*5, cur from costs, where day < 25 and day >=3
  )

-- Q2
create table schedule as
  with fly(path, cost, num, end)(
    select departure || "," || arrival, arrival, 1, price from fligths where departure = "sfo" union
    select path || ", " || a.arrival, a.price, num+1, a.arrival from fly as b, flights as a where b.end = a.departure and num <=2
  )
  select path, cost from flights where end = "PDX" order by cost;

-- Q3
create table shopping_cart as
  with cornbread as (food, budget, current_price)(
      select item, 60-price, price from supermarket WHERE budget - price >= 0 and current_price <= price union
      select food ||", "|| item, budget - price, price from cart , supermarket WHERE budget - price >= 0 and current_price <= price;
  )
  select food, budget from cornbread ORDER BY budget, food;

#GROUP BY departure having count(*) >= 2;
#select count(distinct departure) from flights;
-- Q4
create table number_of_options as
  select count(distinct meat) as "number_of_options" from main_course;

-- Q5
create table calories as
  select m.meat, min(m.calories + p.calorie) as calories from main_course as m, pies as p 
  group by m.meat having max(m.calories + p.calores) <= 3000;
-- Q6
create table healthiest_meats as
  select  from main_course as m, pies as p WHERE p.calories + m.;

-- Q7
create table average_prices as
  select category, avg(MSRP) from products group by category ;

-- Q8
create table lowest_prices as
  create 
  select name, store, price from products, inventory WHERE name = item group by name having min(price);

-- Q9
create table shopping_list as
  select category, store from product, lowerst_price where l.name = p.name group by category having max(MSRP/rating)

-- Q10
create table total_bandwidth as
  select sum(mbs) stores as l, shopping_list as m where l.store = m.store ;
