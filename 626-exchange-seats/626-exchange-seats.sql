# Write your MySQL query statement below
select (
  case
    when mod(s.id, 2) = 1 and t.counts != id then id+1
    when mod(s.id, 2) = 1 and t.counts = id then id
    else id-1
  end
) as id, 
  s.student as student
from Seat as s, (
  select count(*) as counts from Seat
) as t
order by id asc;