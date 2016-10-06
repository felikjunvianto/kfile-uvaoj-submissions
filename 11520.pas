var n,m,x,y,z,ver,hor,a:longint;
	grid:array[1..10,1..10] of char;
	terakhir:char;
	beda:boolean;
	cek:string;
	
begin
	readln(n);
	cek:='';
	for x:=1 to n do
	begin
		readln(y);
		fillchar(grid,sizeof(grid),'.');
		for z:=1 to y do
		begin
			for m:=1 to y-1 do read(grid[z,m]);
			readln(grid[z,y]);
		end;
		writeln('Case ',x,':');
		
		for z:=1 to y do
		begin
			for m:=1 to y do 
			begin
				if grid[z,m]='.' then
				begin
					delete(cek,1,length(cek));
					for ver:=-1 to 1 do
						for hor:=-1 to 1 do 
							if((ver=0)xor(hor=0)) then
								if((z+ver>=1)and(z+ver<=y)and(m+hor>=1)and(m+hor<=y)) then cek:=cek+grid[z+ver,m+hor];
					terakhir:='@';
				
					repeat
						beda:=TRUE;
						inc(terakhir);
						for a:=1 to length(cek) do if terakhir=cek[a] then 
						begin
							beda:=FALSE;
							break;
						end;
					until beda;
					grid[z,m]:=terakhir;
				end;
				write(grid[z,m]);
			end;
			writeln;
		end;
	end;
end.