delimiter ??
CREATE TRIGGER `update_log` before update ON `Film_creations`
FOR EACH ROW BEGIN
	declare f, d, s varchar(80);
    call filmHistory_proc(f, OLD.Film_id, NEW.Film_id);
    call directorHistory_proc(d, OLD.Director_id, NEW.Director_id);
    call studioHistory_proc(s, OLD.Studio_id, NEW.Studio_id);
    INSERT INTO History Set 
    FilmCreations_Id = OLD.Id, 
    FilmHistory = f,
    DirectorHistory = d,
    StudioHistory = s;
END;
??

??
create procedure `filmHistory_proc` (out res varchar(80), in oldId int, in newId int) deterministic
begin
	if oldId != newId then
		set res = concat_ws(' -> ',(select t.Name from Films t where oldId = t.Id),
			(select t.Name from Films t where newId = t.Id));
	end if;
end;
??

??
create procedure `directorHistory_proc` (out res varchar(80), in oldId int, in newId int) deterministic
begin
	if oldId != newId then
		set res = concat_ws(' -> ',(select t.Name from Directors t where oldId = t.Id),
			(select t.Name from Directors t where newId = t.Id));
	end if;
end;
??

??
create procedure `studioHistory_proc` (out res varchar(80), in oldId int, in newId int) deterministic
begin
	if oldId != newId then
		set res = concat_ws(' -> ',(select t.Name from Studios t where oldId = t.Id),
			(select t.Name from Studios t where newId = t.Id));
	end if;
end;
??