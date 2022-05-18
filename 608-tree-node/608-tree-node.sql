# Write your MySQL query statement below
select tree.id, 
case
  when tree.p_id is null then 'Root'
  when tree.id in (
    select distinct tree.p_id from tree
  ) then 'Inner'
  else 'Leaf'
end
as type from Tree tree order by id asc;