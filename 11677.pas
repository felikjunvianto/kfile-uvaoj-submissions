type hour=record
	 jam,menit:longint;
	 end;
	 
var x,y:longint;
	start,alarm:array[1..1000] of hour;
	hasil:longint;
	
begin
	x:=0;
	repeat
		inc(x);
		readln(start[x].jam,start[x].menit,alarm[x].jam,alarm[x].menit);
		hasil:=start[x].jam+start[x].menit+alarm[x].jam+alarm[x].menit;
	until hasil=0;
	dec(x);
	
	for y:=1 to x do 
	begin
		hasil:=alarm[y].jam*60+alarm[y].menit-(start[y].jam*60+start[y].menit);
		if hasil < 0 then hasil:=hasil+1440;
		writeln(hasil);
	end;
end.