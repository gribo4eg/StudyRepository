SET global event_scheduler = 1;

delimiter ??

create event `Lab2DB`.`delete_history`
	on schedule every 1 day
    do truncate table Lab2DB.History;
??

