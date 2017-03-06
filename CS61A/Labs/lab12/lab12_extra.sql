.read lab12.sql

CREATE TABLE sp16favnum AS
  select number, COUNT(*) AS count FROM sp16students GROUP BY number ORDER BY count DESC LIMIT 1;

CREATE TABLE sp16favpets AS
  select pet, COUNT(*) as count from sp16students GROUP BY pet ORDER BY count DESC LIMIT 10;

CREATE TABLE fa16favpets AS
  select pet, COUNT(*) as count from students GROUP BY pet ORDER BY count DESC LIMIT 10;

CREATE TABLE fa16dragon AS
  select pet, COUNT(*) as count from students WHERE pet = dragon GROUP BY pet;

CREATE TABLE fa16alldragons AS
  select pet, COUNT(*) from students WHERE pet LIKE '%dragon';

CREATE TABLE obedienceimage AS
  select seven, denero, COUNT(*) from students WHERE seven = '7' GROUP BY denero ;

CREATE TABLE smallest_int_count AS
  select number, count(*) from students WHERE number >= 1 ORDER BY number ASC;