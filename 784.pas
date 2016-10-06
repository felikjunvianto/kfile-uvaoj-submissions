var n,x,y,z,count:longint;
	maze:array[1..30] of string;
	
procedure jejak(x,y:longint);
	var ver,hor:longint;
	
	begin
		maze[x,y]:='#';
		for ver:=-1 to 1 do
			for hor:=-1 to 1 do
				if((ver=0)xor(hor=0)) then 
					if maze[x+hor,y+ver]=' ' then jejak(x+hor,y+ver);
	end;
	
begin
	readln(n);
	for x:=1 to n do
	begin
		fillchar(maze,sizeof(maze),'X');
		count:=0;
		repeat
			inc(count);
			readln(maze[count]);
		until maze[count,1]='_';
		
		for y:=1 to count-1 do 
		begin
			for z:=1 to length(maze[y]) do if maze[y,z]='*' then break;
			if maze[y,z]='*' then break;
		end;
		jejak(y,z);
		for y:=1 to count do writeln(maze[y]);
	end;
end.