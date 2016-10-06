var baris,kolom,x,y,ver,hor,count:longint;
	mine:array[1..150,1..150] of char;
	
begin
	count:=0;
	repeat
		readln(baris,kolom);
		if((baris<>0)and(kolom<>0)) then
		begin
			fillchar(mine,sizeof(mine),'.');
			inc(count);
			for y:=1 to baris do
			begin
				for x:=1 to kolom do 
				begin
					read(mine[x,y]);
					if mine[x,y]='.' then mine[x,y]:='0';
				end;
				readln;
			end;
			
			for y:=1 to baris do
				for x:=1 to kolom do if mine[x,y]='*' then
					for ver:=-1 to 1 do
						for hor:=-1 to 1 do
							if not((ver=0)and(hor=0)) then
								if((x+hor>=1)and(x+hor<=kolom)and(y+ver>=1)and(y+ver<=baris)) then
									if(mine[x+hor,y+ver]<>'*') then inc(mine[x+hor,y+ver]);
			
			if count>1 then writeln;
			writeln('Field #',count,':');		
			for y:=1 to baris do
			begin
				for x:=1 to kolom do write(mine[x,y]);
				writeln;
			end;
		end;					
		
	until ((baris=0)and(kolom=0));
end.