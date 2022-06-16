# Write your MySQL query statement below
select l.user_id, max(l.time_stamp) as last_stamp
from Logins as l
where l.time_stamp like "2020-%"
group by l.user_id;