# Write your MySQL query statement below
select p.firstName, p.lastName, a.city, a.state from Person p
left outer join Address a using(personId);